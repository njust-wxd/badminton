#ifndef _BMSERVICE_BMDEFINE_H
#define _BMSERVICE_BMDEFINE_H

#include <string>

using std::string;

namespace badminton {
#define WS_GROUP_RESULT "WS_GROUP_RESULT"
#define WS_MATCH_RESULT "WS_MATCH_RESULT"
#define WS_MATCH_GAMES  "WS_MATCH_GAMES"

//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

enum BMLogLevel
{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR
};

#define _RECYCLE_4_ 4               //4人转
#define _RECYCLE_4_NUM_OF_MATCH_ 3   //4人转一共打3场

#define _RECYCLE_5_ 5               //5人转
#define _RECYCLE_5_NUM_OF_MATCH_ 5   //5人转一共打5场

#define _RECYCLE_8_ 8               //8人转
#define _RECYCLE_8_NUM_OF_MATCH_ 14  //8人转一共打14场

#define _RECYCLE_9_ 9              //9人转
#define _RECYCLE_9_NUM_OF_MATCH_ 18  //9人转一共打18场


//比赛结果
struct MATCH_RESULTS {
    string name_of_person;  //人名
    int win_or_lose[2];     //比赛赢得次数和输的次数（大分）
    int net_score;          //比赛净胜分(小分)
    int rank;               //比赛排名
    string score_of_big_or_small;//结果按大分还是小分（两个人赢得次数一样的话算小分，否则算大分）
};

//一场比赛的四个选手
struct PLAYERS_OF_ONE_MATCH {
    string first_pair_of_players[2];    //第一对选手
    string second_pair_of_players[2];   //第二队选手
};

//一场比赛分数
struct SCORES_OF_ONE_MATCH {
    int scores_of_first_pair_of_players; //第一对选手的得分
    int scores_of_second_pair_of_players;//第二对选手的得分
};

//一场比赛
struct ONE_MATCH {
    unsigned id_match;
    PLAYERS_OF_ONE_MATCH players_of_one_match;
    SCORES_OF_ONE_MATCH scores_of_one_match;
};

} // badminton

#endif //_BMSERVICE_BMDEFINE_H