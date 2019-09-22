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

void BMMatch::setGames(const vector<BMGame>& games)
{
    m_games = games;
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
    return true;
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
    
void BMMatch::get_four_players_of_a_match_for_4()
{
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
    game1.addPlayerA(m_players[0]);
    game1.addPlayerA(m_players[2]);
    game1.addPlayerB(m_players[1]);
    game1.addPlayerB(m_players[3]);
    m_games.push_back(game1);
        
    BMGame game2;
    game2.setIndex(3);
    game2.addPlayerA(m_players[0]);
    game2.addPlayerA(m_players[3]);
    game2.addPlayerB(m_players[1]);
    game2.addPlayerB(m_players[2]);
    m_games.push_back(game2);
        
}
    
void BMMatch::get_four_players_of_a_match_for_5()
{
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
    game1.addPlayerA(m_players[1]);
    game1.addPlayerA(m_players[2]);
    game1.addPlayerB(m_players[4]);
    game1.addPlayerB(m_players[3]);
    m_games.push_back(game1);
    
    BMGame game2;
    game2.setIndex(3);
    game2.addPlayerA(m_players[0]);
    game2.addPlayerA(m_players[4]);
    game2.addPlayerB(m_players[1]);
    game2.addPlayerB(m_players[3]);
    m_games.push_back(game2);
        
    BMGame game3;
    game3.setIndex(4);
    game3.addPlayerA(m_players[0]);
    game3.addPlayerA(m_players[2]);
    game3.addPlayerB(m_players[1]);
    game3.addPlayerB(m_players[4]);
    m_games.push_back(game3);
        
    BMGame game4;
    game4.setIndex(5);
    game4.addPlayerA(m_players[0]);
    game4.addPlayerA(m_players[3]);
    game4.addPlayerB(m_players[4]);
    game4.addPlayerB(m_players[2]);
    m_games.push_back(game4);
    
}
    
void BMMatch::get_four_players_of_a_match_for_8()
{
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

void BMMatch::get_four_players_of_a_match_for_9()
{
        //随机打乱人员名单
    random_shuffle(m_players.begin(), m_players.end());
        
    BMGame game0;
    game0.setIndex(1);
    game0.addPlayerA(m_players[0]);
    game0.addPlayerA(m_players[8]);
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
    game2.addPlayerA(m_players[2]);
    game2.addPlayerA(m_players[8]);
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
    game5.addPlayerA(m_players[8]);
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
    game10.addPlayerA(m_players[8]);
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
    game13.addPlayerA(m_players[8]);
    game13.addPlayerA(m_players[5]);
    game13.addPlayerB(m_players[3]);
    game13.addPlayerB(m_players[4]);
    m_games.push_back(game13);
    
    BMGame game14;
    game14.setIndex(15);
    game14.addPlayerA(m_players[0]);
    game14.addPlayerA(m_players[1]);
    game14.addPlayerB(m_players[3]);
    game14.addPlayerB(m_players[8]);
    m_games.push_back(game14);
    
    BMGame game15;
    game15.setIndex(16);
    game15.addPlayerA(m_players[2]);
    game15.addPlayerA(m_players[5]);
    game15.addPlayerB(m_players[7]);
    game15.addPlayerB(m_players[4]);
    m_games.push_back(game15);
    
    BMGame game16;
    game16.setIndex(17);
    game16.addPlayerA(m_players[8]);
    game16.addPlayerA(m_players[1]);
    game16.addPlayerB(m_players[0]);
    game16.addPlayerB(m_players[2]);
    m_games.push_back(game16);
    
    BMGame game17;
    game17.setIndex(18);
    game17.addPlayerA(m_players[0]);
    game17.addPlayerA(m_players[6]);
    game17.addPlayerB(m_players[7]);
    game17.addPlayerB(m_players[8]);
    m_games.push_back(game17);
}
    
    
void BMMatch::send_scores_of_a_match(int id_of_match,
                                int scores_of_first_pair_of_players,
                                int scores_of_second_pair_of_players)
{
    
    m_games[id_of_match].setScore(scores_of_first_pair_of_players, scores_of_second_pair_of_players);
}

void BMMatch::get_match_results_Recycle4(vector<BMPlayer>& players, vector<BMGame> games)
{
    unsigned i;
    for (i = 0; i < _RECYCLE_4_NUM_OF_MATCH_; i++)
    {
        SCORES_OF_ONE_MATCH scores = games[i].getScore();
        
        unsigned j = 0;
        for (j = 0; j < _RECYCLE_4_; j++)
        {
            std::vector<BMPlayer> m_players_A = games[i].getPlayersA();
            std::vector<BMPlayer> m_players_B = games[i].getPlayersB();
            
            if (scores.scores_of_first_pair_of_players > scores.scores_of_second_pair_of_players)
            {
                
                if (m_players_A[0].getName() == players[j].getName()
                    or m_players_A[1].getName() == players[j].getName())
                {
                    
                    players[j].addOneWinTimes();
                    int net_score = games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                if (m_players_B[0].getName() == players[j].getName()
                    or m_players_B[1].getName() == players[j].getName())
                {
                    players[j].addOneLoseTimes();
                    int net_score = 0 - games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                
            }
            else
            {
                if (m_players_B[0].getName() == players[j].getName()
                    or m_players_B[1].getName() == players[j].getName())
                {
                    players[j].addOneWinTimes();
                    int net_score = 0 - games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                if (m_players_A[0].getName() == players[j].getName()
                    or m_players_A[1].getName() == players[j].getName())
                {
                    players[j].addOneLoseTimes();
                    int net_score = games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
            }
            
        }
    }
    
    for (i = 0; i < _RECYCLE_4_; i++)
    {
        int wintimes_i = players[i].getWinTimes();
        for (int k = 0; k < _RECYCLE_4_; k++)
        {
            int wintimes_k = players[k].getWinTimes();
            if (wintimes_i < wintimes_k)
            {
                players[i].addOneRank();
            }
        }
        players[i].addOneRank();
    }
}
void BMMatch::get_match_results_Recycle5(vector<BMPlayer>& players, vector<BMGame> games)
{
    unsigned i;
    for (i = 0; i < _RECYCLE_5_NUM_OF_MATCH_; i++)
    {
        SCORES_OF_ONE_MATCH scores = games[i].getScore();
        unsigned j = 0;
        for (j = 0; j < _RECYCLE_5_; j++)
        {
            std::vector<BMPlayer> m_players_A = games[i].getPlayersA();
            std::vector<BMPlayer> m_players_B = games[i].getPlayersB();
                
            if (scores.scores_of_first_pair_of_players > scores.scores_of_second_pair_of_players)
            {
                if (m_players_A[0].getName() == players[j].getName()
                    or m_players_A[1].getName() == players[j].getName())
                {
                    
                    players[j].addOneWinTimes();
                    int net_score = games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                if (m_players_B[0].getName() == players[j].getName()
                    or m_players_B[1].getName() == players[j].getName())
                {
                    players[j].addOneLoseTimes();
                    int net_score = 0 - games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                
            }
            else
            {
                if (m_players_B[0].getName() == players[j].getName()
                    or m_players_B[1].getName() == players[j].getName())
                {
                    players[j].addOneWinTimes();
                    int net_score = 0 - games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                if (m_players_A[0].getName() == players[j].getName()
                    or m_players_A[1].getName() == players[j].getName())
                {
                    players[j].addOneLoseTimes();
                    int net_score = games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
            }
        }
    }
        
    for (i = 0; i < _RECYCLE_5_; i++)
    {
        int wintimes_i = players[i].getWinTimes();
        for (int k = 0; k < _RECYCLE_5_; k++)
        {
            int wintimes_k = players[k].getWinTimes();
            if (wintimes_i < wintimes_k)
            {
                players[i].addOneRank();
            }
        }
        players[i].addOneRank();
    }
}
    
void BMMatch::get_match_results_Recycle8(vector<BMPlayer>& players, vector<BMGame> games)
{
    unsigned i;
    for (i = 0; i < _RECYCLE_5_NUM_OF_MATCH_; i++)
    {
        SCORES_OF_ONE_MATCH scores = games[i].getScore();
        unsigned j = 0;
        for (j = 0; j < _RECYCLE_8_; j++)
        {
            std::vector<BMPlayer> m_players_A = games[i].getPlayersA();
            std::vector<BMPlayer> m_players_B = games[i].getPlayersB();
            
            if (scores.scores_of_first_pair_of_players > scores.scores_of_second_pair_of_players)
            {
                if (m_players_A[0].getName() == players[j].getName()
                    or m_players_A[1].getName() == players[j].getName())
                {
                    
                    players[j].addOneWinTimes();
                    int net_score = games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                if (m_players_B[0].getName() == players[j].getName()
                    or m_players_B[1].getName() == players[j].getName())
                {
                    players[j].addOneLoseTimes();
                    int net_score = 0 - games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                
            }
            else
            {
                if (m_players_B[0].getName() == players[j].getName()
                    or m_players_B[1].getName() == players[j].getName())
                {
                    players[j].addOneWinTimes();
                    int net_score = 0 - games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                if (m_players_A[0].getName() == players[j].getName()
                    or m_players_A[1].getName() == players[j].getName())
                {
                    players[j].addOneLoseTimes();
                    int net_score = games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
            }
        }
    }
        
    for (i = 0; i < _RECYCLE_8_; i++)
    {
        int wintimes_i = players[i].getWinTimes();
        for (int k = 0; k < _RECYCLE_8_; k++)
        {
            int wintimes_k = players[k].getWinTimes();
            if (wintimes_i < wintimes_k)
            {
                players[i].addOneRank();
            }
        }
        players[i].addOneRank();
    }
}
    
void BMMatch::get_match_results_Recycle9(vector<BMPlayer>& players, vector<BMGame> games)
{
    unsigned i;
    for (i = 0; i < _RECYCLE_9_NUM_OF_MATCH_; i++)
    {
        SCORES_OF_ONE_MATCH scores = games[i].getScore();
        unsigned j = 0;
        for (j = 0; j < _RECYCLE_9_; j++)
        {
            std::vector<BMPlayer> m_players_A = games[i].getPlayersA();
            std::vector<BMPlayer> m_players_B = games[i].getPlayersB();
                
            if (scores.scores_of_first_pair_of_players > scores.scores_of_second_pair_of_players)
            {
                if (m_players_A[0].getName() == players[j].getName()
                    or m_players_A[1].getName() == players[j].getName())
                {
                    
                    players[j].addOneWinTimes();
                    int net_score = games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                if (m_players_B[0].getName() == players[j].getName()
                    or m_players_B[1].getName() == players[j].getName())
                {
                    players[j].addOneLoseTimes();
                    int net_score = 0 - games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                    
            }
            else
            {
                if (m_players_B[0].getName() == players[j].getName()
                    or m_players_B[1].getName() == players[j].getName())
                {
                    players[j].addOneWinTimes();
                    int net_score = 0 - games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
                if (m_players_A[0].getName() == players[j].getName()
                    or m_players_A[1].getName() == players[j].getName())
                {
                    players[j].addOneLoseTimes();
                    int net_score = games[i].getNetScoreA();
                    players[j].addFinalScore(net_score);
                }
            }
        }
    }
        
    for (i = 0; i < _RECYCLE_9_; i++)
    {
        int wintimes_i = players[i].getWinTimes();
        for (int k = 0; k < _RECYCLE_9_; k++)
        {
            int wintimes_k = players[k].getWinTimes();
            if (wintimes_i < wintimes_k)
            {
                players[i].addOneRank();
            }
        }
        players[i].addOneRank();
    }
}
    
void BMMatch::get_match_results(vector<BMPlayer>& players, vector<BMGame> games)
{

    switch (m_type)
    {
        case 4:
            get_match_results_Recycle4(players, games);
            break;
        case 5:
            get_match_results_Recycle5(players, games);
            break;
        case 8:
            get_match_results_Recycle8(players, games);
            break;
        case 9:
            get_match_results_Recycle9(players, games);
            break;
        default:
            break;
    }
}
void BMMatch::startMatch_Recycle4()
{
    BMSLOG_D("invoked");
    
    if (m_players.size() != _RECYCLE_4_)
    {
        BMSLOG_E("player num is not 4!");
        return;
    }
    
    get_four_players_of_a_match_for_4();
}

void BMMatch::startMatch_Recycle5()
{
    BMSLOG_D("invoked");
    
    if (m_players.size() != _RECYCLE_5_)
    {
        BMSLOG_E("player num is not 5!");
        return;
    }
    
    get_four_players_of_a_match_for_5();
}

void BMMatch::startMatch_Recycle8()
{
    if (m_players.size() != _RECYCLE_8_)
    {
        BMSLOG_E("player num is not 8!");
        return;
    }
    
    get_four_players_of_a_match_for_8();
    
}

void BMMatch::startMatch_Recycle9()
{
    if (m_players.size() != _RECYCLE_9_)
    {
        BMSLOG_E("player num is not 8!");
        return;
    }
    
    get_four_players_of_a_match_for_9();
}

} // namespace badminton
