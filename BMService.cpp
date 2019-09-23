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

    

    

    
void BMService::handleMatchResult(BMMatch& match)
{
    BMSLOG_I("invoked");
    std::vector<BMPlayer> players = match.getPlayers();
    std::vector<BMGame> games = match.getGames();

    
    match.get_match_results(players, games);
    int type = match.getType();
    BMSLOG_I("%d\n", type);
    match.rankMatch(players,type);
    match.setOptionBigOrSmall(players, type);
 
    string result = BMCommon::genRankResult(players);
    BMWSService::getInstance()->sendMessage(result);
}

}
