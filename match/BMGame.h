#ifndef _BMSERVICE_BMGAME_H
#define _BMSERVICE_BMGAME_H

#include <vector>
#include <string>
#include "BMDefine.h"

using std::vector;
using std::string;

namespace badminton {
class BMPlayer;
class BMGame
{
public:
    BMGame();
    ~BMGame();

    void setIndex(int index);
    void setType(int type);
    void setPlayersA(const vector<BMPlayer>& players);
    void addPlayerA(const BMPlayer& player);
    void setPlayersB(const vector<BMPlayer>& players);
    void addPlayerB(const BMPlayer& player);
    void setScore(int scoreA, int scoreB);
    SCORES_OF_ONE_MATCH getScore();
    vector<BMPlayer> getPlayersA();
    vector<BMPlayer> getPlayersB();
    int getNetScore();

    int getIndex();
    string getGameString();

private:
    int m_index;
    int m_type;  // 单打1、双打2，细分为: 男单11、女单12、男双21、女双22、混双23
    vector<BMPlayer> m_players_A;
    vector<BMPlayer> m_players_B;
    int m_scoreA; // A的得分
    int m_scoreB; // B的得分
    int m_score;  // A:B的净胜分
};

} // namespace badminton

#endif //_BMSERVICE_BMGAME_H
