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
    match.setName("八人转");
    match.setType(type);
    match.initPlayers(players);
    match.startMatch();
    string gamesString = match.getGamesString();

    BMWSService::getInstance()->sendMessage(gamesString);
}

void BMService::handleMatchResult(BMMatch& match)
{
    BMSLOG_I("invoked");
    std::vector<BMPlayer> players = match.getPlayers();
    std::vector<BMGame> games = match.getGames();
    
    unsigned i;
    for (i = 0; i < _RECYCLE_8_NUM_OF_MATCH_; i++)
    {
        SCORES_OF_ONE_MATCH scores = games[i].getScore();
        
        unsigned j = 0;
        for (j = 0; j < _RECYCLE_8_; j++)
        {
            std::vector<BMPlayer> m_players_A = games[i].getPlayersA();
            std::vector<BMPlayer> m_players_B = games[i].getPlayersB();
            
            if (scores.scores_of_first_pair_of_players > scores.scores_of_second_pair_of_players)
            {
                
                if (m_players_A[0].getName() == players[j].getName()
                    or m_players_A[1].getName() == players[j].getName())
                {
                    
                    players[j].addOneWinTimes();
                    int net_score = games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                if (m_players_B[0].getName() == players[j].getName()
                    or m_players_B[1].getName() == players[j].getName())
                {
                    players[j].addOneLoseTimes();
                    int net_score = 0 - games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                
            }
            else
            {
                if (m_players_B[0].getName() == players[j].getName()
                    or m_players_B[1].getName() == players[j].getName())
                {
                    players[j].addOneWinTimes();
                    int net_score = 0 - games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                if (m_players_A[0].getName() == players[j].getName()
                    or m_players_A[1].getName() == players[j].getName())
                {
                    players[j].addOneLoseTimes();
                    int net_score = games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
            }
            
        }
    }
    
    for (i = 0; i < _RECYCLE_8_; i++)
    {
        int wintimes_i = players[i].getWinTimes();
        for (int k = 0; k < _RECYCLE_8_; k++)
        {
            int wintimes_k = players[k].getWinTimes();
            if (wintimes_i < wintimes_k)
            {
                players[i].addOneRank();
            }
        }
        players[i].addOneRank();
    }
    
    string result = BMCommon::genRankResult(players);
    BMWSService::getInstance()->sendMessage(result);
}

}
