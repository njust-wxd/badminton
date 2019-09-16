#ifndef _BMSERVICE_BMSERVICE_H
#define _BMSERVICE_BMSERVICE_H

#include <vector>
#include <string>
#include <BMAlgorithm_to_process.h>
#include "BMDefine.h"

namespace badminton {
class BMService
{
public:
    BMService();
    virtual ~BMService();

    int start();
    void stop();

    void startMatch(int type, const std::vector<std::string>& players);

};

} //namespace badminton

#endif //_BMSERVICE_BMSERVICE_H
