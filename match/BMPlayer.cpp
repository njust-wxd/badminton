#include "BMPlayer.h"
#include "BMLogWrap.h"
#include "BMGame.h"

namespace badminton {

BMPlayer::BMPlayer()
    : m_rank(0)
    , m_winTimes(0)
    , m_loseTimes(0)
    , m_finalScore(0)
{
}

BMPlayer::~BMPlayer()
{
}

void BMPlayer::setName(const string& name)
{
    m_name = name;
}

void BMPlayer::setNickName(const string& nickName)
{
    m_nickName = nickName;
}

void BMPlayer::setSex(int sex)
{
    m_sex = sex;
}

void BMPlayer::setBigorSmall(const string& bigorsmall)
{
    m_BigorSmall = bigorsmall;
}
void BMPlayer::setWinTimes(int winTimes)
{
    m_winTimes = winTimes;
}

void BMPlayer::setLoseTimes(int loseTimes)
{
    m_loseTimes = loseTimes;
}

void BMPlayer::setFinalScore(int finalScore)
{
    m_finalScore = finalScore;
}

void BMPlayer::setRank(int rank)
{
    m_rank = rank;
}

void BMPlayer::setJoinGames(const vector<BMGame>& joinGames)
{
    m_joinGames = joinGames;
}

string BMPlayer::getBigorSmall()
{
    return m_BigorSmall;
}
string BMPlayer::getName()
{
    return m_name;
}

void BMPlayer::addOneWinTimes()
{
    m_winTimes++;
}

void BMPlayer::addOneLoseTimes()
{
    m_loseTimes++;
}

void BMPlayer::addOneRank()
{
    m_rank++;
}

void BMPlayer::addFinalScore(int net_score)
{
    m_finalScore = m_finalScore + net_score;
}

int BMPlayer::getWinTimes()
{
    return m_winTimes;
}

int BMPlayer::getLoseTimes()
{
        return m_loseTimes;
}

int BMPlayer::getFinalScore()
{
    return m_finalScore;
}

int BMPlayer::getRank()
{
    return m_rank;
}

} // namespace badminton
