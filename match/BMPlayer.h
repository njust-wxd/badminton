#ifndef _BMSERVICE_BMPLAYER_H
#define _BMSERVICE_BMPLAYER_H

#include <string>
#include <vector>

using std::vector;
using std::string;

namespace badminton {
class BMGame;
class BMPlayer
{
public:
    BMPlayer();
    ~BMPlayer();

    void setName(const string& name);
    void setNickName(const string& nickName);
    void setBigorSmall(const string& bigorsmall);
    void setSex(int sex);
    void setWinTimes(int winTimes);
    void setLoseTimes(int loseTimes);
    void setFinalScore(int finalScore);
    void setRank(int rank);
    void setJoinGames(const vector<BMGame>& joinGames);
    
    void addOneWinTimes();
    void addOneLoseTimes();
    void addFinalScore(int net_score);
    void addOneRank();
    int getWinTimes();
    int getLoseTimes();
    int getFinalScore();
    string getBigorSmall();
    string getName();
    int getRank();

private:
    string m_name;
    string m_nickName;
    int m_sex;  // 性别
    int m_winTimes;
    int m_loseTimes;
    int m_finalScore;
    int m_rank;
    string m_BigorSmall;
    vector<BMGame> m_joinGames;
};

} // namespace badminton

#endif //_BMSERVICE_BMMATCH_H
