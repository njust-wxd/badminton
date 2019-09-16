#ifndef _BMSERVICE_BMCOMMON_H
#define _BMSERVICE_BMCOMMON_H

#include "BMDefine.h"
#include "BMGame.h"
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

    static string genMatchResult(MATCH_RESULTS* pResult, size_t num);

    static string genGamesString(const vector<BMGame>& games);
};

} // namespace badminton

#endif //_BMSERVICE_BMCOMMON_H