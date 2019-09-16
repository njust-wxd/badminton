#include "BMPlayer.h"
#include "BMLogWrap.h"
#include "BMGame.h"

namespace badminton {

BMPlayer::BMPlayer()
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

string BMPlayer::getName()
{
    return m_name;
}

} // namespace badminton