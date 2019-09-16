#include "BMGame.h"
#include "BMLogWrap.h"
#include "BMPlayer.h"

namespace badminton {

BMGame::BMGame()
    : m_type(2)
{
}

BMGame::~BMGame()
{
}

void BMGame::setIndex(int index)
{
    m_index = index;
}

void BMGame::setType(int type)
{
    m_type = type;
}

void BMGame::setPlayersA(const vector<BMPlayer>& players)
{
    m_players_A = players;
}

void BMGame::addPlayerA(const BMPlayer& player)
{
    m_players_A.push_back(player);
}

void BMGame::setPlayersB(const vector<BMPlayer>& players)
{
    m_players_B = players;
}

void BMGame::addPlayerB(const BMPlayer& player)
{
    m_players_B.push_back(player);
}

void BMGame::setScore(int scoreA, int scoreB)
{
    m_scoreA = scoreA;
    m_scoreB = scoreB;
    m_score = scoreA - scoreB;
}

int BMGame::getIndex()
{
    return m_index;
}

string BMGame::getGameString()
{
    string strA = m_players_A.size() == 2 ? 
        m_players_A[0].getName() + "/" + m_players_A[1].getName() : m_players_A[0].getName();
    
    string strB = m_players_B.size() == 2 ? 
        m_players_B[0].getName() + "/" + m_players_B[1].getName() : m_players_B[0].getName();
    
    return strA + " : " + strB;
}

} // namespace badminton