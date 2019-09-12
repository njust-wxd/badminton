#ifndef _BMSERVICE_BMMATCH_H
#define _BMSERVICE_BMMATCH_H

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace badminton {
class BMMatch
{
public:
    BMMatch(int type, vector<string> players);
    ~BMMatch();

};

} // namespace badminton

#endif //_BMSERVICE_BMMATCH_H