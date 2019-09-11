#ifndef _BMSERVICE_BMSERVICE_H
#define _BMSERVICE_BMSERVICE_H

#include <vector>
#include <string>
#include <BDAlgorithm_to_process.h>
#include "BMDefine.h"

namespace badminton {
class BMService
{
public:
    BMService();
    virtual ~BMService();

    int start();
    void stop();

    void group(const std::vector<std::string>& players);

};

} //namespace badminton

#endif //_BMSERVICE_BMSERVICE_H
