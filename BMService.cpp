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
    
    //创建记录所有比赛人员和分数的变量
    ONE_MATCH all_matches[_RECYCLE_8_NUM_OF_MATCH_];
    memset(all_matches, 0, sizeof(ONE_MATCH) * (_RECYCLE_8_NUM_OF_MATCH_));
    
    
    //输出所有比赛的人员对阵名单
    get_four_players_of_a_match(players,all_matches);
    //获得所有的比赛分数
    send_scores_of_a_match(1,15,21,all_matches);
    send_scores_of_a_match(2,21,11,all_matches);
    send_scores_of_a_match(3,15,21,all_matches);
    send_scores_of_a_match(4,8,21,all_matches);
    send_scores_of_a_match(5,12,21,all_matches);
    send_scores_of_a_match(6,21,18,all_matches);
    send_scores_of_a_match(7,13,21,all_matches);
    send_scores_of_a_match(8,21,17,all_matches);
    send_scores_of_a_match(9,21,19,all_matches);
    send_scores_of_a_match(10,21,8,all_matches);
    send_scores_of_a_match(11,5,21,all_matches);
    send_scores_of_a_match(12,18,21,all_matches);
    send_scores_of_a_match(13,23,25,all_matches);
    send_scores_of_a_match(14,21,17,all_matches);
    
    //创建比赛结果变量
    MATCH_RESULTS match_results[_RECYCLE_8_];
    memset(match_results, 0, sizeof(MATCH_RESULTS) * (_RECYCLE_8_));
    //获得所有的比赛结果，结果解放在match_results中
    get_match_results(players,all_matches,match_results);
    
    std::string result = "//TODO 写分组算法，结果组织成 string 类型";
    std::string sndMsg = BMCommon::genGroupResult(result);
    BMWSService::getInstance()->sendMessage(sndMsg);
}

}
