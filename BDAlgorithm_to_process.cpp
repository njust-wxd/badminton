//
//  BDAlgorithm_to_process.cpp
//  Badminton_6_or_8
//
//  Created by 张倚萌 on 2019/9/11.
//  Copyright © 2019 张倚萌. All rights reserved.
//

#include "BDAlgorithm_to_process.h"

void get_four_players_of_a_match(vector<string> list_of_players,
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
    all_matches[1].players_of_one_match.first_pair_of_players[0] = list_of_players[4];
    all_matches[1].players_of_one_match.first_pair_of_players[1] = list_of_players[5];
    all_matches[1].players_of_one_match.second_pair_of_players[0] = list_of_players[6];
    all_matches[1].players_of_one_match.second_pair_of_players[1] = list_of_players[7];
    
    all_matches[2].id_match = 3;
    all_matches[2].players_of_one_match.first_pair_of_players[0] = list_of_players[0];
    all_matches[2].players_of_one_match.first_pair_of_players[1] = list_of_players[2];
    all_matches[2].players_of_one_match.second_pair_of_players[0] = list_of_players[1];
    all_matches[2].players_of_one_match.second_pair_of_players[1] = list_of_players[3];
    
    all_matches[3].id_match = 4;
    all_matches[3].players_of_one_match.first_pair_of_players[0] = list_of_players[4];
    all_matches[3].players_of_one_match.first_pair_of_players[1] = list_of_players[6];
    all_matches[3].players_of_one_match.second_pair_of_players[0] = list_of_players[5];
    all_matches[3].players_of_one_match.second_pair_of_players[1] = list_of_players[7];
    
    all_matches[4].id_match = 5;
    all_matches[4].players_of_one_match.first_pair_of_players[0] = list_of_players[0];
    all_matches[4].players_of_one_match.first_pair_of_players[1] = list_of_players[3];
    all_matches[4].players_of_one_match.second_pair_of_players[0] = list_of_players[1];
    all_matches[4].players_of_one_match.second_pair_of_players[1] = list_of_players[2];
    
    all_matches[5].id_match = 6;
    all_matches[5].players_of_one_match.first_pair_of_players[0] = list_of_players[4];
    all_matches[5].players_of_one_match.first_pair_of_players[1] = list_of_players[7];
    all_matches[5].players_of_one_match.second_pair_of_players[0] = list_of_players[5];
    all_matches[5].players_of_one_match.second_pair_of_players[1] = list_of_players[6];
    
    all_matches[6].id_match = 7;
    all_matches[6].players_of_one_match.first_pair_of_players[0] = list_of_players[0];
    all_matches[6].players_of_one_match.first_pair_of_players[1] = list_of_players[4];
    all_matches[6].players_of_one_match.second_pair_of_players[0] = list_of_players[1];
    all_matches[6].players_of_one_match.second_pair_of_players[1] = list_of_players[5];
    
    all_matches[7].id_match = 8;
    all_matches[7].players_of_one_match.first_pair_of_players[0] = list_of_players[2];
    all_matches[7].players_of_one_match.first_pair_of_players[1] = list_of_players[6];
    all_matches[7].players_of_one_match.second_pair_of_players[0] = list_of_players[3];
    all_matches[7].players_of_one_match.second_pair_of_players[1] = list_of_players[7];
    
    all_matches[8].id_match = 9;
    all_matches[8].players_of_one_match.first_pair_of_players[0] = list_of_players[0];
    all_matches[8].players_of_one_match.first_pair_of_players[1] = list_of_players[5];
    all_matches[8].players_of_one_match.second_pair_of_players[0] = list_of_players[1];
    all_matches[8].players_of_one_match.second_pair_of_players[1] = list_of_players[4];
    
    all_matches[9].id_match = 10;
    all_matches[9].players_of_one_match.first_pair_of_players[0] = list_of_players[2];
    all_matches[9].players_of_one_match.first_pair_of_players[1] = list_of_players[7];
    all_matches[9].players_of_one_match.second_pair_of_players[0] = list_of_players[3];
    all_matches[9].players_of_one_match.second_pair_of_players[1] = list_of_players[6];
    
    all_matches[10].id_match = 11;
    all_matches[10].players_of_one_match.first_pair_of_players[0] = list_of_players[0];
    all_matches[10].players_of_one_match.first_pair_of_players[1] = list_of_players[6];
    all_matches[10].players_of_one_match.second_pair_of_players[0] = list_of_players[1];
    all_matches[10].players_of_one_match.second_pair_of_players[1] = list_of_players[7];
    
    all_matches[11].id_match = 12;
    all_matches[11].players_of_one_match.first_pair_of_players[0] = list_of_players[2];
    all_matches[11].players_of_one_match.first_pair_of_players[1] = list_of_players[4];
    all_matches[11].players_of_one_match.second_pair_of_players[0] = list_of_players[3];
    all_matches[11].players_of_one_match.second_pair_of_players[1] = list_of_players[5];
    
    all_matches[12].id_match = 13;
    all_matches[12].players_of_one_match.first_pair_of_players[0] = list_of_players[0];
    all_matches[12].players_of_one_match.first_pair_of_players[1] = list_of_players[7];
    all_matches[12].players_of_one_match.second_pair_of_players[0] = list_of_players[1];
    all_matches[12].players_of_one_match.second_pair_of_players[1] = list_of_players[6];
    
    all_matches[13].id_match = 14;
    all_matches[13].players_of_one_match.first_pair_of_players[0] = list_of_players[2];
    all_matches[13].players_of_one_match.first_pair_of_players[1] = list_of_players[5];
    all_matches[13].players_of_one_match.second_pair_of_players[0] = list_of_players[3];
    all_matches[13].players_of_one_match.second_pair_of_players[1] = list_of_players[4];

}

void send_scores_of_a_match(int id_of_match,
                            int scores_of_first_pair_of_players,
                            int scores_of_second_pair_of_players,
                            ONE_MATCH* all_matches)
{
    all_matches[id_of_match-1].scores_of_one_match.scores_of_first_pair_of_players = scores_of_first_pair_of_players;
    all_matches[id_of_match-1].scores_of_one_match.scores_of_second_pair_of_players = scores_of_second_pair_of_players;
}

void get_match_results(vector<string> list_of_players,
                       ONE_MATCH all_matches[_RECYCLE_8_NUM_OF_MATCH_],
                       MATCH_RESULTS* match_results)
{
    
        match_results[0].name_of_person = list_of_players[0];
        match_results[1].name_of_person = list_of_players[1];
        match_results[2].name_of_person = list_of_players[2];
        match_results[3].name_of_person = list_of_players[3];
        match_results[4].name_of_person = list_of_players[4];
        match_results[5].name_of_person = list_of_players[5];
        match_results[6].name_of_person = list_of_players[6];
        match_results[7].name_of_person = list_of_players[7];
    
    
        unsigned i;
        for (i = 0; i < _RECYCLE_8_NUM_OF_MATCH_; i++)
        {
            int score_of_first = all_matches[i].scores_of_one_match.scores_of_first_pair_of_players;
            int score_of_second = all_matches[i].scores_of_one_match.scores_of_second_pair_of_players;

            unsigned j = 0;
            for (j = 0; j < _RECYCLE_8_; j++)
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
    
    
        for (i = 0; i < 8; i++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (match_results[i].win_or_lose[0] < match_results[k].win_or_lose[0])
                {
                    match_results[i].rank += 1;
                }
            }
            match_results[i].rank += 1;
        }
}

void print_all_teams_of_match(PLAYERS_OF_ONE_MATCH* players_of_match)
{
    unsigned i;
    for (i = 0; i < _RECYCLE_8_NUM_OF_MATCH_; i++)
    {
        cout<<players_of_match[i].first_pair_of_players[0]<<" and "<<players_of_match[i].first_pair_of_players[1]
        <<" vs "<<players_of_match[i].second_pair_of_players[0]<<" and "<<players_of_match[i].second_pair_of_players[1]<<endl;
    }

}

void print_match_results(MATCH_RESULTS* match_results)
{
    unsigned i;

    for (i = 0; i < _RECYCLE_8_; i++)
    {
        cout<<match_results[i].name_of_person<<" "
        <<match_results[i].win_or_lose[0]<<"-"
        <<match_results[i].win_or_lose[1]<<" "
        <<match_results[i].net_score<<" "
        <<match_results[i].rank<<endl;
    }
}
