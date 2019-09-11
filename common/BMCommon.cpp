#include "BMCommon.h"
#include "json/json.h"

namespace badminton {

std::string BMCommon::getTimeString()
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return std::string(buffer);
}

std::string BMCommon::genGroupResult(const std::string& result)
{
    Json::FastWriter writer;
    Json::Value root;
    root["type"] = Json::Value(WS_GROUP_RESULT);
    root["data"] = Json::Value(result);
    return writer.write(root);
}

std::string BMCommon::genMatchResult(MATCH_RESULTS* pResult, size_t num)
{
    Json::FastWriter writer;
    Json::Value root;
    Json::Value jmatch_result;
    root["type"] = Json::Value(WS_MATCH_RESULT);
    for (size_t i = 0; i < num; ++i)
    {
        Json::Value jplayer;
        jplayer["name"] = pResult[i].name_of_person;
        jplayer["win_times"] = pResult[i].win_or_lose[0];
        jplayer["lose_times"] = pResult[i].win_or_lose[1];
        jplayer["net_score"] = pResult[i].net_score;
        jplayer["rank"] = pResult[i].rank;
        jplayer["big_or_small"] = pResult[i].score_of_big_or_small;
        jmatch_result.append(jplayer);
    }
    root["result"] = Json::Value(jmatch_result);

    return writer.write(root);
}

} // namespace badminton