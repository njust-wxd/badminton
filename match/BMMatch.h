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
    bool startMatch();

    string getName();
    int getType();
    vector<BMPlayer> getPlayers();
    vector<BMGame> getGames();

    string getGamesString();

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