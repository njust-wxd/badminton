#include "BMCommon.h"
#include "BMDefine.h"
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

} // namespace badminton