#ifndef _BMSERVICE_BMCOMMON_H
#define _BMSERVICE_BMCOMMON_H

#include "BMDefine.h"
#include <string>

namespace badminton {
class BMCommon
{
public:
    static std::string getTimeString();

    static std::string genGroupResult(const std::string& result);

    static std::string genMatchResult(MATCH_RESULTS* pResult, size_t num);
};

} // namespace badminton

#endif //_BMSERVICE_BMCOMMON_H