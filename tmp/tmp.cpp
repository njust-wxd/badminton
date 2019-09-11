
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
    unsigned char pBuf[sizeof(badminton::MATCH_RESULTS)*_RECYCLE_8_+1000];
    memset(pBuf,0,sizeof(pBuf));

    int nBytes;
    nBytes=0;
    for (int i = 0; i < _RECYCLE_8_; i++)
    {
        string name = match_results[i].name_of_person;
        int win = match_results[i].win_or_lose[0];
        int lose = match_results[i].win_or_lose[1];
        int net_score = match_results[i].net_score;
        int rank = match_results[i].rank;
        string big_or_small = match_results[i].score_of_big_or_small;
        memcpy(pBuf+nBytes,&name,sizeof(string));
        nBytes += sizeof(string);
        memcpy(pBuf+nBytes,&win,sizeof(int));
        nBytes += sizeof(int);
        memcpy(pBuf+nBytes,&lose,sizeof(int));
        nBytes += sizeof(int);
        memcpy(pBuf+nBytes,&net_score,sizeof(int));
        nBytes += sizeof(int);
        memcpy(pBuf+nBytes,&rank,sizeof(int));
        nBytes += sizeof(int);
        memcpy(pBuf+nBytes,&big_or_small,sizeof(string));
        nBytes += sizeof(string);
    }

    
    
    std::string result = "//TODO 写分组算法，结果组织成 string 类型";
    memcpy(&result, pBuf, sizeof(pBuf));
    std::string sndMsg = BMCommon::genGroupResult(result);
    BMWSService::getInstance()->sendMessage(sndMsg);
}

}
