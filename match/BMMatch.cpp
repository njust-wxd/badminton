#include "BMMatch.h"
#include "BMLogWrap.h"
#include "BMGame.h"
#include "BMPlayer.h"
#include "BMCommon.h"
#include <algorithm>

namespace badminton {

BMMatch::BMMatch()
{
    BMSLOG_D("invoked");
}

BMMatch::~BMMatch()
{
    BMSLOG_D("invoked");
}

void BMMatch::setName(const string &name)
{
    m_name = name;
}

void BMMatch::setType(int type)
{
    m_type = type;
}

void BMMatch::initPlayers(const vector<string> &names)
{
    for (string name : names)
    {
        BMPlayer player;
        player.setName(name);
        m_players.push_back(player);
    }
}

void BMMatch::setPlayers(const vector<BMPlayer> &players)
{
    m_players = players;
}

bool BMMatch::startMatch()
{
    BMSLOG_D("invoked");
    switch (m_type)
    {
    case 4:
        startMatch_Recycle4();
        break;
    case 5:
        startMatch_Recycle5();
        break;
    case 8:
        startMatch_Recycle8();
        break;
    case 9:
        startMatch_Recycle9();
        break;
    default:
        break;
    }
}

string BMMatch::getName()
{
    return m_name;
}

int BMMatch::getType()
{
    return m_type;
}

vector<BMPlayer> BMMatch::getPlayers()
{
    return m_players;
}

vector<BMGame> BMMatch::getGames()
{
    return m_games;
}

string BMMatch::getGamesString()
{
    return BMCommon::genGamesString(m_games);
}

void BMMatch::startMatch_Recycle4()
{
    BMSLOG_D("invoked");
}

void BMMatch::startMatch_Recycle5()
{
    BMSLOG_D("invoked");
}

void BMMatch::startMatch_Recycle8()
{
    if (m_players.size() != 8)
    {
        BMSLOG_E("player num is not 8!");
        return;
    }
    //随机打乱人员名单
    random_shuffle(m_players.begin(), m_players.end());    
    
    BMGame game0;
    game0.setIndex(1);
    game0.addPlayerA(m_players[0]);
    game0.addPlayerA(m_players[1]);
    game0.addPlayerB(m_players[2]);
    game0.addPlayerB(m_players[3]);
    m_games.push_back(game0);

    BMGame game1;
    game1.setIndex(2);
    game1.addPlayerA(m_players[4]);
    game1.addPlayerA(m_players[5]);
    game1.addPlayerB(m_players[6]);
    game1.addPlayerB(m_players[7]);
    m_games.push_back(game1);
    
    BMGame game2;
    game2.setIndex(3);
    game2.addPlayerA(m_players[0]);
    game2.addPlayerA(m_players[2]);
    game2.addPlayerB(m_players[1]);
    game2.addPlayerB(m_players[3]);
    m_games.push_back(game2);

    BMGame game3;
    game3.setIndex(4);
    game3.addPlayerA(m_players[4]);
    game3.addPlayerA(m_players[6]);
    game3.addPlayerB(m_players[5]);
    game3.addPlayerB(m_players[7]);
    m_games.push_back(game3);
    
    BMGame game4;
    game4.setIndex(5);
    game4.addPlayerA(m_players[0]);
    game4.addPlayerA(m_players[3]);
    game4.addPlayerB(m_players[1]);
    game4.addPlayerB(m_players[2]);
    m_games.push_back(game4);

    BMGame game5;
    game5.setIndex(6);
    game5.addPlayerA(m_players[4]);
    game5.addPlayerA(m_players[7]);
    game5.addPlayerB(m_players[5]);
    game5.addPlayerB(m_players[6]);
    m_games.push_back(game5);

    BMGame game6;
    game6.setIndex(7);
    game6.addPlayerA(m_players[0]);
    game6.addPlayerA(m_players[4]);
    game6.addPlayerB(m_players[1]);
    game6.addPlayerB(m_players[5]);
    m_games.push_back(game6);

    BMGame game7;
    game7.setIndex(8);
    game7.addPlayerA(m_players[2]);
    game7.addPlayerA(m_players[6]);
    game7.addPlayerB(m_players[3]);
    game7.addPlayerB(m_players[7]);
    m_games.push_back(game7);
    
    BMGame game8;
    game8.setIndex(9);
    game8.addPlayerA(m_players[0]);
    game8.addPlayerA(m_players[5]);
    game8.addPlayerB(m_players[1]);
    game8.addPlayerB(m_players[4]);
    m_games.push_back(game8);

    BMGame game9;
    game9.setIndex(10);
    game9.addPlayerA(m_players[2]);
    game9.addPlayerA(m_players[7]);
    game9.addPlayerB(m_players[3]);
    game9.addPlayerB(m_players[6]);
    m_games.push_back(game9);

    BMGame game10;
    game10.setIndex(11);
    game10.addPlayerA(m_players[0]);
    game10.addPlayerA(m_players[6]);
    game10.addPlayerB(m_players[1]);
    game10.addPlayerB(m_players[7]);
    m_games.push_back(game10);
    
    BMGame game11;
    game11.setIndex(12);
    game11.addPlayerA(m_players[2]);
    game11.addPlayerA(m_players[4]);
    game11.addPlayerB(m_players[3]);
    game11.addPlayerB(m_players[5]);
    m_games.push_back(game11);

    BMGame game12;
    game12.setIndex(13);
    game12.addPlayerA(m_players[0]);
    game12.addPlayerA(m_players[7]);
    game12.addPlayerB(m_players[1]);
    game12.addPlayerB(m_players[6]);
    m_games.push_back(game12);
    
    BMGame game13;
    game13.setIndex(14);
    game13.addPlayerA(m_players[2]);
    game13.addPlayerA(m_players[5]);
    game13.addPlayerB(m_players[3]);
    game13.addPlayerB(m_players[4]);
    m_games.push_back(game13);
}

void BMMatch::startMatch_Recycle9()
{
    BMSLOG_D("invoked");
}

} // namespace badminton