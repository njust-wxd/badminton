//
//  BMAlgorithm_Recycle_4.hpp
//  Badminton_6_or_8
//
//  Created by 张倚萌 on 2019/9/12.
//  Copyright © 2019 张倚萌. All rights reserved.
//

#ifndef BMAlgorithm_Recycle_4_h
#define BMAlgorithm_Recycle_4_h

#include <stdio.h>
#include "BMDefine.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

using std::vector;
namespace badminton {
    
    class BMA_4{
        
    private:
        
    public:
        //获取所有比赛的人员对阵名单
        //输入(vector<string> list_of_players)：从界面得到的选手的名单。
        //输出(ONE_MATCH* all_matches)：
        //    1.所有比赛的人员对阵名单，放在all_matches中的players_of_one_match结构中；
        //    2.比赛的ID号，放在all_matches中的id_match结构中。
        void get_four_players_of_a_match_4(vector<string> list_of_players,
                                         ONE_MATCH* all_matches);
        
        //得到一场比赛的分数
        //输入(int id_of_match)：比赛的ID号；
        //输入(scores_of_first_pair_of_players):第一对选手的比赛得分；
        //输入(scores_of_second_pair_of_players):第二对选手的比赛得分；
        //输出(ONE_MATCH* all_matches):将比分放在all_matches中的scores_of_one_match结构中。
        void send_scores_of_a_match_4(int id_of_match,
                                    int scores_of_first_pair_of_players,
                                    int scores_of_second_pair_of_players,
                                    ONE_MATCH* all_matches);
        
        //得到所有的比赛结果
        //输入(vector<string> list_of_players)：所有选手的名单；
        //输入(ONE_MATCH all_matches[_RECYCLE_8_NUM_OF_MATCH_])：所有的比赛名单和比赛分数；
        //输出(MATCH_RESULTS* match_result)：输出所有的比赛结果。
        void get_match_results_4(vector<string> list_of_players,
                               ONE_MATCH all_matches[_RECYCLE_8_NUM_OF_MATCH_],
                               MATCH_RESULTS* match_results);
        
        
        void print_all_teams_of_match_4(PLAYERS_OF_ONE_MATCH* players_of_match);
        
        void print_match_results_4(MATCH_RESULTS* match_results);
        
    };
    
    
} // namespace badminton


#endif /* BMAlgorithm_Recycle_4_hpp */
