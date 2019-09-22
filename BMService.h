#ifndef _BMSERVICE_BMSERVICE_H
#define _BMSERVICE_BMSERVICE_H

#include <vector>
#include <string>
#include "BMDefine.h"
#include "BMMatch.h"

namespace badminton {
class BMService
{
public:
    BMService();
    virtual ~BMService();

    int start();
    void stop();

    void startMatch(int type, const std::vector<std::string>& players);

    void handleMatchResult(BMMatch& match);
    
    void setOptionBigOrSmall(vector<BMPlayer>& players, int type);
    void rankMatch(vector<BMPlayer>& players, int type);
    
    

};

} //namespace badminton

#endif //_BMSERVICE_BMSERVICE_H
