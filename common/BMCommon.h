#ifndef _BMSERVICE_BMCOMMON_H
#define _BMSERVICE_BMCOMMON_H

#include <string>

namespace badminton {
class BMCommon
{
public:
    static std::string getTimeString();

    static std::string genGroupResult(const std::string& result);
};

} // namespace badminton

#endif //_BMSERVICE_BMCOMMON_H