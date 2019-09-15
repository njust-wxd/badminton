#ifndef _BMSERVICE_BMGAME_H
#define _BMSERVICE_BMGAME_H

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace badminton {
class BMPlayer;
class BMGame
{
public:
    BMGame();
    ~BMGame();

    void setType(int type);
    void setPlayersA(const vector<BMPlayer>& players);
    void setPlayersB(const vector<BMPlayer>& players);
    void setScore(int scoreA, int scoreB);

private:
    int m_type;  // 单打1、双打2，细分为: 男单11、女单12、男双21、女双22、混双23
    vector<BMPlayer> m_players_A;
    vector<BMPlayer> m_players_B;
    int m_scoreA; // A的得分
    int m_scoreB; // B的得分
    int m_score;  // A:B的净胜分
};

} // namespace badminton

#endif //_BMSERVICE_BMGAME_H