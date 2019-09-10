#ifndef _BMSERVICE_BMWSSERVICE_H
#define _BMSERVICE_BMWSSERVICE_H

#include "libwebsockets.h"
#include <thread>
#include <string>
#include <list>

#define PAYLOAD_MAX_LEN 1024*1024

namespace badminton {
class BMService;
class BMWSService
{
public:
    static BMWSService* getInstance(BMService* pService = nullptr);
    static void destroy();

public:
    int start();
    void stop();

    void onWSEstablished(struct lws *wsi);
    void onWSClosed(struct lws *wsi);
    void onWSWritable();
    void onWSReceive(struct lws *wsi, char* in, size_t len);
    void sendMessage(const std::string& msg);

private:
    BMWSService(BMService* pService = nullptr);
    virtual ~BMWSService();

    int initialize();
    void uninitialize();
    void handleMessage(char* payload, size_t len);

    static void* stc_thread_func(void *arg);
    void run();
    
private:
    static BMWSService* s_pInstance;
    BMService* m_pService;

    struct lws_context* m_pContext;
    struct lws* m_lws;
    std::list<std::string> m_msgs; // msg for send
    std::thread m_thread;
    bool m_bQuit;

    char* m_rcvPayload;
    size_t m_rcvLen;

};

} // namespace badminton

#endif // _BMSERVICE_BMWSSERVICE_H