#include "BMMatch.h"
#include "BMLogWrap.h"
#include "BMGame.h"
#include "BMPlayer.h"

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
    BMSLOG_D("invoked");
    m_name = name;
}

void BMMatch::setType(int type)
{
    BMSLOG_D("invoked");
    m_type = type;
}

void BMMatch::initPlayers(const vector<string> &names)
{
    BMSLOG_D("invoked");
}

void BMMatch::setPlayers(const vector<BMPlayer> &players)
{
    BMSLOG_D("invoked");
    m_players = players;
}

bool BMMatch::startMatch()
{
    BMSLOG_D("invoked");
}

string BMMatch::getName()
{
    BMSLOG_D("invoked");
    return m_name;
}

int BMMatch::getType()
{
    BMSLOG_D("invoked");
    return m_type;
}

vector<BMPlayer> BMMatch::getPlayers()
{
    BMSLOG_D("invoked");
    return m_players;
}

vector<BMGame> BMMatch::getGames()
{
    BMSLOG_D("invoked");
    return m_games;
}

} // namespace badminton