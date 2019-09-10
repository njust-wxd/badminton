#include "BMService.h"
#include "BMLogWrap.h"
#include "BMCommon.h"
#include "BMWSService.h"

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

void BMService::group(const std::vector<std::string>& players)
{
    BMSLOG_I("invoked");
    //TODO 写分组算法，结果组织成 string 类型
    std::string result = "//TODO 写分组算法，结果组织成 string 类型";
    std::string sndMsg = BMCommon::genGroupResult(result);
    BMWSService::getInstance()->sendMessage(sndMsg);
}

}