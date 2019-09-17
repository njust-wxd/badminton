#include "BMCommon.h"
#include "BMPlayer.h"
#include "json/json.h"

namespace badminton {

string BMCommon::getTimeString()
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return string(buffer);
}

string BMCommon::genGroupResult(const string& result)
{
    Json::FastWriter writer;
    Json::Value root;
    root["type"] = Json::Value(WS_GROUP_RESULT);
    root["data"] = Json::Value(result);
    return writer.write(root);
}

string BMCommon::genGamesString(const vector<BMGame>& games)
{
    Json::FastWriter writer;
    Json::Value root;
    Json::Value jgames;
    root["type"] = Json::Value(WS_MATCH_GAMES);
    for (BMGame game : games)
    {
        Json::Value jgame;
        jgame["index"] = game.getIndex();
        jgame["players_a"] = game.getPlayersAString();
        jgame["players_b"] = game.getPlayersBString();
        jgames.append(jgame);
    }
    root["games"] = Json::Value(jgames);
    return writer.write(root);
}

string BMCommon::genRankResult(const vector<BMPlayer>& players)
{
    Json::FastWriter writer;
    Json::Value root;
    Json::Value jmatch_result;
    root["type"] = Json::Value(WS_RANK_RESULT);
    for (BMPlayer player : players)
    {
        Json::Value jplayer;
        jplayer["name"] = player.getName();
        jplayer["win_times"] = player.getWinTimes();
        jplayer["lose_times"] = player.getLoseTimes();
        jplayer["net_score"] = player.getFinalScore();
        jplayer["rank"] = player.getRank();
        jmatch_result.append(jplayer);
    }
    root["players_result"] = Json::Value(jmatch_result);

    return writer.write(root);
}

} // namespace badminton