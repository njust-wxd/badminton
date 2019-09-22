#include "BMService.h"
#include "BMLogWrap.h"
#include "BMCommon.h"
#include "BMWSService.h"
#include "BMMatch.h"
#include "BMGame.h"
#include "BMPlayer.h"

namespace badminton {
BMService::BMService()
{
    BMSLOG_I("invoked");
    BMWSService::getInstance(this);
}

BMService::~BMService()
{
    BMSLOG_I("invoked");
    BMWSService::getInstance()->destroy();
}

int BMService::start()
{
    BMSLOG_I("invoked");
    return BMWSService::getInstance()->start();;
}

void BMService::stop()
{
    BMSLOG_I("invoked");
    BMWSService::getInstance()->stop();
}

void BMService::startMatch(int type, const std::vector<std::string>& players)
{
    BMSLOG_I("invoked");
    BMMatch match;
    match.setType(type);
    match.initPlayers(players);
    match.startMatch();
    string gamesString = match.getGamesString();

    BMWSService::getInstance()->sendMessage(gamesString);
}

    
void BMService::rankMatch(vector<BMPlayer>& players, int type)
{
    unsigned int i = 0, j = 0;
    for (j = 0; j < type; j++)
    {
        for (i = 0; i < type - 1; i++)
        {
            int rank1 = players[i].getRank();
            int rank2 = players[i+1].getRank();
            if (rank1 > rank2)
                std::swap(players[i], players[i+1]);
            if (rank1 == rank2)
            {
                int finalscore1 = players[i].getFinalScore();
                int finalscore2 = players[i+1].getFinalScore();
                if (finalscore1 < finalscore2)
                {
                    std::swap(players[i], players[i+1]);
                }
            }
            
        }

    }
    
    for (i = 0; i < type - 1; i++)
    {
        int wintimes1 = players[i].getWinTimes();
        int wintimes2 = players[i+1].getWinTimes();
        int finalscore1 = players[i].getFinalScore();
        int finalscore2 = players[i+1].getFinalScore();
        if (wintimes1 == wintimes2)
        {
            if (finalscore1 == finalscore2)
            {
                continue;
            }
            else
            {
                players[i+1].setRank(i+2);
                BMSLOG_I("%d\n", i);
            }
        }
    }
    
}
    
void BMService::setOptionBigOrSmall(vector<BMPlayer>& players, int type)
{
    unsigned int i = 0;
    players[0].setBigorSmall("大分");
    for (i = 0; i < type - 1; i++)
    {
        int winTimes1 = players[i].getWinTimes();
        int winTimes2 = players[i+1].getWinTimes();
        if (winTimes1 == winTimes2)
        {
            players[i].setBigorSmall("小分");
            players[i+1].setBigorSmall("小分");
        }
        else
        {
            players[i+1].setBigorSmall("大分");
        }
    }
}
    
void BMService::handleMatchResult(BMMatch& match)
{
    BMSLOG_I("invoked");
    std::vector<BMPlayer> players = match.getPlayers();
    std::vector<BMGame> games = match.getGames();

    
    match.get_match_results(players, games);
    int type = match.getType();
    BMSLOG_I("%d\n", type);
    rankMatch(players,type);
//    setOptionBigOrSmall(players, type);
 
    string result = BMCommon::genRankResult(players);
    BMWSService::getInstance()->sendMessage(result);
}

}
