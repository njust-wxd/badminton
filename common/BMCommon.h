#ifndef _BMSERVICE_BMCOMMON_H
#define _BMSERVICE_BMCOMMON_H

#include "BMDefine.h"
#include "BMGame.h"
#include "BMPlayer.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace badminton {
class BMCommon
{
public:
    static string getTimeString();

    static string genGroupResult(const string& result);

    static string genGamesString(const vector<BMGame>& games);

    static string genRankResult(const vector<BMPlayer>& players);
};

} // namespace badminton

#endif //_BMSERVICE_BMCOMMON_H