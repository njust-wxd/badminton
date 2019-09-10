#ifndef _BMSERVICE_BMLOGWRAP_H
#define _BMSERVICE_BMLOGWRAP_H

#include <libgen.h>
#include <string>
#include <time.h>
#include <iomanip>
#include <stdarg.h>
#include <cstdio>
#include <sstream>
#include "BMDefine.h"
#include "BMLogger.h"

namespace badminton {

#define BMSLOG(level, format, args...) \
    { \
        badminton::BMSLogger* pLogger = badminton::BMSLogger::getInstance(); \
        if (pLogger != NULL) \
        { \
            std::ostringstream oss; \
            oss << basename((char *)__FILE__) << ":" << __LINE__;                 \
            pLogger->writeLog(level, oss.str().data(), __FUNCTION__, format, ##args); \
        } \
    }

#define BMSLOG_D(format, args...) \
    { \
        BMSLOG(LOG_LEVEL_DEBUG, format, ##args); \
    }

#define BMSLOG_I(format, args...) \
    { \
        BMSLOG(LOG_LEVEL_INFO, format, ##args); \
    }

#define BMSLOG_W(format, args...) \
    { \
        BMSLOG(LOG_LEVEL_WARN, format, ##args); \
    }

#define BMSLOG_E(format, args...) \
    { \
        BMSLOG(LOG_LEVEL_ERROR, format, ##args); \
    }

} // namespace badminton

#endif // _BMSERVICE_BMLOGWRAP_H