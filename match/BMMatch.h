#ifndef _BMSERVICE_BMMATCH_H
#define _BMSERVICE_BMMATCH_H

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace badminton {
class BMPlayer;
class BMGame;
class BMMatch {
public:
    BMMatch();
    ~BMMatch();

    void setName(const string& name);
    void setType(int type);
    void initPlayers(const vector<string>& names);
    void setPlayers(const vector<BMPlayer>& players);
    void setGames(const vector<BMGame>& games);
    bool startMatch();

    string getName();
    int getType();
    vector<BMPlayer> getPlayers();
    vector<BMGame> getGames();

    string getGamesString();
    
    //获取所有8人比赛的人员对阵名单
    void get_four_players_of_a_match_for_8();
    
    //得到一场比赛的分数
    //输入(int id_of_match)：比赛的ID号；
    //输入(scores_of_first_pair_of_players):第一对选手的比赛得分；
    //输入(scores_of_second_pair_of_players):第二对选手的比赛得分；
    void send_scores_of_a_match(int id_of_match,
                                int scores_of_first_pair_of_players,
                                int scores_of_second_pair_of_players);
    //得到所有的比赛结果
    //输入(vector<string> list_of_players)：所有选手的名单；
    //输入(ONE_MATCH all_matches[_RECYCLE_8_NUM_OF_MATCH_])：所有的比赛名单和比赛分数；
    //输出(MATCH_RESULTS* match_result)：输出所有的比赛结果。
    void get_match_results(vector<BMPlayer>& players, vector<BMGame> games);

private:
    void startMatch_Recycle4();
    void startMatch_Recycle5();
    void startMatch_Recycle8();
    void startMatch_Recycle9();

private:
    string m_name;
    int m_type;
    vector<BMPlayer> m_players;
    vector<BMGame> m_games;
};

} // namespace badminton

#endif //_BMSERVICE_BMMATCH_H
