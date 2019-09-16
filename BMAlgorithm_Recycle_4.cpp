//
//  BMAlgorithm_Recycle_4.cpp
//  Badminton_6_or_8
//
//  Created by 张倚萌 on 2019/9/12.
//  Copyright © 2019 张倚萌. All rights reserved.
//

#include "BMAlgorithm_Recycle_4.h"


namespace badminton {
    
    void BMA_4::get_four_players_of_a_match_4(vector<string> list_of_players,
                                            ONE_MATCH* all_matches)
    {
        //随机打乱人员名单
        random_shuffle(list_of_players.begin(), list_of_players.end());
        
        all_matches[0].id_match = 1;
        all_matches[0].players_of_one_match.first_pair_of_players[0] = list_of_players[0];
        all_matches[0].players_of_one_match.first_pair_of_players[1] = list_of_players[1];
        all_matches[0].players_of_one_match.second_pair_of_players[0] = list_of_players[2];
        all_matches[0].players_of_one_match.second_pair_of_players[1] = list_of_players[3];
        
        all_matches[1].id_match = 2;
        all_matches[1].players_of_one_match.first_pair_of_players[0] = list_of_players[0];
        all_matches[1].players_of_one_match.first_pair_of_players[1] = list_of_players[2];
        all_matches[1].players_of_one_match.second_pair_of_players[0] = list_of_players[1];
        all_matches[1].players_of_one_match.second_pair_of_players[1] = list_of_players[3];
        
        all_matches[2].id_match = 3;
        all_matches[2].players_of_one_match.first_pair_of_players[0] = list_of_players[0];
        all_matches[2].players_of_one_match.first_pair_of_players[1] = list_of_players[3];
        all_matches[2].players_of_one_match.second_pair_of_players[0] = list_of_players[1];
        all_matches[2].players_of_one_match.second_pair_of_players[1] = list_of_players[2];
        
                
    }
    
    
    void BMA_4::send_scores_of_a_match_4(int id_of_match,
                                       int scores_of_first_pair_of_players,
                                       int scores_of_second_pair_of_players,
                                       ONE_MATCH* all_matches)
    {
        all_matches[id_of_match-1].scores_of_one_match.scores_of_first_pair_of_players = scores_of_first_pair_of_players;
        all_matches[id_of_match-1].scores_of_one_match.scores_of_second_pair_of_players = scores_of_second_pair_of_players;
    }
    
    void BMA_4::get_match_results_4(vector<string> list_of_players,
                                  ONE_MATCH all_matches[_RECYCLE_4_NUM_OF_MATCH_],
                                  MATCH_RESULTS* match_results)
    {
        
        match_results[0].name_of_person = list_of_players[0];
        match_results[1].name_of_person = list_of_players[1];
        match_results[2].name_of_person = list_of_players[2];
        match_results[3].name_of_person = list_of_players[3];
        
        unsigned i;
        for (i = 0; i < _RECYCLE_4_NUM_OF_MATCH_; i++)
        {
            int score_of_first = all_matches[i].scores_of_one_match.scores_of_first_pair_of_players;
            int score_of_second = all_matches[i].scores_of_one_match.scores_of_second_pair_of_players;
            
            unsigned j = 0;
            for (j = 0; j < _RECYCLE_4_; j++)
            {
                if (score_of_first > score_of_second)
                {
                    if (all_matches[i].players_of_one_match.first_pair_of_players[0] == match_results[j].name_of_person
                        or all_matches[i].players_of_one_match.first_pair_of_players[1] == match_results[j].name_of_person)
                    {
                        match_results[j].win_or_lose[0] += 1;
                        match_results[j].net_score += score_of_first - score_of_second;
                    }
                    if (all_matches[i].players_of_one_match.second_pair_of_players[0] == match_results[j].name_of_person
                        or all_matches[i].players_of_one_match.second_pair_of_players[1] == match_results[j].name_of_person)
                    {
                        match_results[j].win_or_lose[1] += 1;
                        match_results[j].net_score += score_of_second - score_of_first;
                    }
                    
                }
                else
                {
                    if (all_matches[i].players_of_one_match.second_pair_of_players[0] == match_results[j].name_of_person
                        or all_matches[i].players_of_one_match.second_pair_of_players[1] == match_results[j].name_of_person)
                    {
                        match_results[j].win_or_lose[0] += 1;
                        match_results[j].net_score += (score_of_second - score_of_first);
                    }
                    if (all_matches[i].players_of_one_match.first_pair_of_players[0] == match_results[j].name_of_person
                        or all_matches[i].players_of_one_match.first_pair_of_players[1] == match_results[j].name_of_person)
                    {
                        match_results[j].win_or_lose[1] += 1;
                        match_results[j].net_score += (score_of_first - score_of_second);
                    }
                }
                
            }
        }
        
        
        for (i = 0; i < _RECYCLE_4_; i++)
        {
            for (int k = 0; k < _RECYCLE_4_; k++)
            {
                if (match_results[i].win_or_lose[0] < match_results[k].win_or_lose[0])
                {
                    match_results[i].rank += 1;
                }
            }
            match_results[i].rank += 1;
        }
    }
    void BMA_4::print_all_teams_of_match_4(PLAYERS_OF_ONE_MATCH* players_of_match)
    {
        unsigned i;
        for (i = 0; i < _RECYCLE_4_NUM_OF_MATCH_; i++)
        {
            cout<<players_of_match[i].first_pair_of_players[0]<<" and "<<players_of_match[i].first_pair_of_players[1]
            <<" vs "<<players_of_match[i].second_pair_of_players[0]<<" and "<<players_of_match[i].second_pair_of_players[1]<<endl;
        }
        
    }
    
    void BMA_4::print_match_results_4(MATCH_RESULTS* match_results)
    {
        unsigned i;
        
        for (i = 0; i < _RECYCLE_4_; i++)
        {
            cout<<match_results[i].name_of_person<<" "
            <<match_results[i].win_or_lose[0]<<"-"
            <<match_results[i].win_or_lose[1]<<" "
            <<match_results[i].net_score<<" "
            <<match_results[i].rank<<endl;
        }
    }
    
}

