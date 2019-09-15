#include "BMPlayer.h"
#include "BMLogWrap.h"
#include "BMGame.h"

namespace badminton {

BMPlayer::BMPlayer()
{
    BMSLOG_D("invoked");
}

BMPlayer::~BMPlayer()
{
    BMSLOG_D("invoked");
}

void BMPlayer::setName(const string& name)
{
    BMSLOG_D("invoked");
    m_name = name;
}

void BMPlayer::setNickName(const string& nickName)
{
    BMSLOG_D("invoked");
    m_nickName = nickName;
}

void BMPlayer::setSex(int sex)
{
    BMSLOG_D("invoked");
    m_sex = sex;
}

void BMPlayer::setWinTimes(int winTimes)
{
    BMSLOG_D("invoked");
    m_winTimes = winTimes;
}

void BMPlayer::setLoseTimes(int loseTimes)
{
    BMSLOG_D("invoked");
    m_loseTimes = loseTimes;
}

void BMPlayer::setFinalScore(int finalScore)
{
    BMSLOG_D("invoked");
    m_finalScore = finalScore;
}

void BMPlayer::setRank(int rank)
{
    BMSLOG_D("invoked");
    m_rank = rank;
}

void BMPlayer::setJoinGames(const vector<BMGame>& joinGames)
{
    BMSLOG_D("invoked");
    m_joinGames = joinGames;
}

} // namespace badminton