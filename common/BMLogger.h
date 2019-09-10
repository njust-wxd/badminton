#ifndef _BMSERVICE_BMLOGGER_H
#define _BMSERVICE_BMLOGGER_H

#include <vector>
#include <string>
#include <stdarg.h>

namespace badminton {
#define BUFFER_SIZE  4096

class BMSLogger
{
public:
    static BMSLogger* getInstance();
    static void destroy();

    void writeLog(
        int level, 
        const char* location, 
        const char* source, 
        const char* message, ...);

    void writeLog(
        int level, 
        const char* location, 
        const std::string& source, 
        const char* message, ...); 

private:
    BMSLogger();
    ~BMSLogger();

    int log(
        int level, 
        const char* source, 
        const char* message);
    
private:
    static BMSLogger* m_pLogger;

};

} // namespace badminton

#endif // _BMSERVICE_BMLOGGER_H