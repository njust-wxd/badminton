#include "BMGame.h"
#include "BMLogWrap.h"
#include "BMPlayer.h"

namespace badminton {

BMGame::BMGame()
    : m_type(2)
{
    BMSLOG_D("invoked");
}

BMGame::~BMGame()
{
    BMSLOG_D("invoked");
}

void BMGame::setType(int type)
{
    BMSLOG_D("invoked");
    m_type = type;
}

void BMGame::setPlayersA(const vector<BMPlayer>& players)
{
    BMSLOG_D("invoked");
    m_players_A = players;
}

void BMGame::setPlayersB(const vector<BMPlayer>& players)
{
    BMSLOG_D("invoked");
    m_players_B = players;
}

void BMGame::setScore(int scoreA, int scoreB)
{
    BMSLOG_D("invoked");
    m_scoreA = scoreA;
    m_scoreB = scoreB;
    m_score = scoreA - scoreB;
}

} // namespace badminton