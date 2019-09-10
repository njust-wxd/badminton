#include "BMLogger.h"
#include "BMDefine.h"
#include "BMCommon.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>

namespace badminton {
static const char *COLOUR[] = {
    RESET,
    BLUE,
    GREEN,
    YELLOW,
    RED
};

static const char *LEVELS[] = {
    "",
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR"};

BMSLogger* BMSLogger::m_pLogger = NULL;
BMSLogger* BMSLogger::getInstance()
{
    if (m_pLogger == NULL)
    {
        m_pLogger = new BMSLogger();
    }
    return m_pLogger;
}

void BMSLogger::destroy()
{
    if (!m_pLogger)
    {
        delete m_pLogger;
        m_pLogger = NULL;
    }
}

BMSLogger::BMSLogger()
{
}

BMSLogger::~BMSLogger()
{
}

void BMSLogger::writeLog(
    int level, 
    const char *location, 
    const char *source, 
    const char *message, ...)
{
    std::string str = location;
    str += " ";
    str += source;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE * sizeof(char));
    if (message != NULL)
    {
        va_list args;
        va_start(args, message);
        vsnprintf(buffer, BUFFER_SIZE - 1, message, args);
        va_end(args);
    }
    log(level, str.data(), buffer);
}

void BMSLogger::writeLog(
    int level, 
    const char *location, 
    const std::string &source, 
    const char *message, ...)
{
    va_list args;
    va_start(args, message);
    writeLog(level, location, source.data(), message, args);
    va_end(args);
}

int BMSLogger::log(
    int level, 
    const char* source, 
    const char* message)
{
    std::ostream *p;
    if (level < 4)
    {
        p = &std::cout;
    }
    else
    {
        p = &std::cerr;
    }
    (*p) << std::left;
    // set color
    (*p) << COLOUR[level];
    (*p) << " [" << LEVELS[level] << "] ";
    // reset color
    (*p) << COLOUR[0];

    // set time
    std::string time = BMCommon::getTimeString();
    (*p) << std::setw(16) << time << " ";

    if (source != NULL)
    {
        (*p) << " " << source;
    }

    if (message != NULL)
    {
        (*p) << " " << message;
    }
    (*p) << std::endl;

    return 0;
}

} // namespace badminton
