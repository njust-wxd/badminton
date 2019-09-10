#include "BMWSService.h"
#include "BMWSCallback.h"
#include "BMLogWrap.h"
#include "json/json.h"
#include "BMService.h"

#include <cstring>
#include <vector>
#include <string>

namespace badminton {
const static std::string CMD_GROUP = "CMD_GROUP";

BMWSService* BMWSService::s_pInstance = nullptr;
static struct lws_http_mount simple_mount = {
    /* .mount_next */		NULL,		/* linked-list "next" */
    /* .mountpoint */		"/",		/* mountpoint URL */
    /* .origin */			"./../html",  /* serve from dir */
    /* .def */			    "index.html",	/* default filename */
    /* .protocol */			NULL,
    /* .cgienv */			NULL,
    /* .extra_mimetypes */	NULL,
    /* .interpret */		NULL,
    /* .cgi_timeout */		0,
    /* .cache_max_age */	0,
    /* .auth_mask */		0,
    /* .cache_reusable */		0,
    /* .cache_revalidate */		0,
    /* .cache_intermediaries */	0,
    /* .origin_protocol */		LWSMPRO_FILE,	/* files in a dir */
    /* .mountpoint_len */		1,		/* char count */
    /* .basic_auth_login_file */	NULL,
};

static struct lws_protocols protocols[] = {
	{ "http", lws_callback_http_dummy, 0, 0 },
	LWS_PLUGIN_PROTOCOL_MINIMAL,
	{ NULL, NULL, 0, 0 } /* terminator */
};

BMWSService::BMWSService(BMService* pService)
    : m_pService(pService)
    , m_pContext(NULL)
    , m_bQuit(false)
    , m_rcvPayload(NULL)
    , m_rcvLen(0)
{
    BMSLOG_I("invoked");
}

BMWSService::~BMWSService()
{
    BMSLOG_I("invoked");
    if (m_rcvPayload != NULL)
    {
        delete[] m_rcvPayload;
        m_rcvPayload = NULL;
    }
}

BMWSService* BMWSService::getInstance(BMService* pService)
{
    if(!s_pInstance)
    {
        s_pInstance = new BMWSService(pService);
    }

    return s_pInstance;
}

void BMWSService::destroy()
{
    if(s_pInstance)
    {
        delete s_pInstance;
        s_pInstance = nullptr;
    }
}

int BMWSService::initialize()
{
    BMSLOG_I("invoked");
    struct lws_context_creation_info info;

	lwsl_notice("LWS minimal ws server | visit http://localhost:7681\n");

	memset(&info, 0, sizeof info); /* otherwise uninitialized garbage */
	info.port = 7681;
	info.mounts = &simple_mount;
	info.protocols = protocols;

	m_pContext = lws_create_context(&info);
	if (!m_pContext)
    {
		lwsl_err("lws init failed\n");
		return 1;
	}
    return 0;
}

void BMWSService::uninitialize()
{
    BMSLOG_I("invoked");
    if (NULL != m_pContext)
    {
        lws_context_destroy(m_pContext);
    }
}

int BMWSService::start()
{
    BMSLOG_I("invoked");
    if (0 != initialize())
    {
        BMSLOG_E("initialize error");
        return 1;
    }
    m_thread = std::thread(&BMWSService::stc_thread_func, this);
    BMSLOG_I("websocket start successfully!");

    return 0;
}

void BMWSService::stop()
{
    BMSLOG_I("invoked");
    m_bQuit = true;
    if (m_thread.joinable())
    {
        m_thread.join();
    }
    uninitialize();
}

void* BMWSService::stc_thread_func(void *arg)
{
    BMSLOG_I("invoked");
    BMWSService *self = (BMWSService *)arg;
    if (nullptr != self)
    {
        self->run();
    }

    return nullptr;
}

void BMWSService::run()
{
    int n = 0;
	while (n >= 0 && !m_bQuit)
		n = lws_service(m_pContext, 50);
}

void BMWSService::onWSEstablished(struct lws *wsi)
{
    BMSLOG_I("invoked");
    m_lws = wsi;
}

void BMWSService::onWSClosed(struct lws *wsi)
{
    BMSLOG_I("invoked");
    m_lws = nullptr;
}

void BMWSService::onWSReceive(struct lws *wsi, char* in, size_t len)
{
    BMSLOG_I("invoked");
    if (nullptr == m_rcvPayload)
    {
        m_rcvPayload = new char[PAYLOAD_MAX_LEN];
        m_rcvLen = 0;
    }
    memcpy(m_rcvPayload + m_rcvLen, in, len);
    m_rcvLen += len;
    if (0 != lws_remaining_packet_payload(wsi))
    {
        BMSLOG_I("has not receive all data");
        return;
    }
    
    BMSLOG_I("has receive data length: %d", m_rcvLen);
    handleMessage(m_rcvPayload, m_rcvLen);
    delete[] m_rcvPayload;
    m_rcvPayload = nullptr;
    m_rcvLen = 0;

}

void BMWSService::handleMessage(char* payload, size_t len)
{
    BMSLOG_I("invoked");
    std::string msg = std::string(payload, len);
    BMSLOG_I("msg: %s", msg.data());
    Json::Reader reader;
    Json::Value root;
    if (!reader.parse(msg, root))
    {
        BMSLOG_E("websocket message parse error!!");
        return;
    }

    std::string cmd = root["cmd"].asString();
    if (CMD_GROUP == cmd)
    {
        BMSLOG_I("CMD_GROUP");
        std::string player1 = root["player1"].asString();
        std::string player2 = root["player2"].asString();
        std::string player3 = root["player3"].asString();
        std::string player4 = root["player4"].asString();
        std::string player5 = root["player5"].asString();
        std::string player6 = root["player6"].asString();
        std::string player7 = root["player7"].asString();
        std::string player8 = root["player8"].asString();
        BMSLOG_I("CMD_GROUP, player1: %s", player1.data());
        BMSLOG_I("CMD_GROUP, player2: %s", player2.data());
        BMSLOG_I("CMD_GROUP, player3: %s", player3.data());
        BMSLOG_I("CMD_GROUP, player4: %s", player4.data());
        BMSLOG_I("CMD_GROUP, player5: %s", player5.data());
        BMSLOG_I("CMD_GROUP, player6: %s", player6.data());
        BMSLOG_I("CMD_GROUP, player7: %s", player7.data());
        BMSLOG_I("CMD_GROUP, player8: %s", player8.data());
        std::vector<std::string> players;
        players.push_back(player1);
        players.push_back(player2);
        players.push_back(player3);
        players.push_back(player4);
        players.push_back(player5);
        players.push_back(player6);
        players.push_back(player7);
        players.push_back(player8);
        m_pService->group(players);
    }
    else
    {
        BMSLOG_W("CMD_UKNOW");
    }
}

void BMWSService::onWSWritable()
{
    BMSLOG_I("invoked");
    if (!m_msgs.empty())
    {
        std::string msg = m_msgs.front();
        m_msgs.pop_front();
        BMSLOG_I("send msg: %s", msg.data());
        std::shared_ptr<char> p(new char[msg.length()+LWS_PRE], std::default_delete<char []>());
        memcpy(p.get() + LWS_PRE, msg.data(), msg.length());
        int sndSize = lws_write(m_lws, (unsigned char*)p.get() + LWS_PRE, msg.length(), LWS_WRITE_TEXT);
        if (sndSize < msg.length())
        {
            lwsl_err("ERROR %d writing to ws\n", sndSize);
            return;
        }
        lws_callback_on_writable(m_lws);
    }
}

void BMWSService::sendMessage(const std::string& msg)
{
    BMSLOG_I("invoked");
    if (m_lws != NULL)
    {
        m_msgs.push_back(msg);
        lws_callback_on_writable(m_lws);
    }
}

} // namespace badminton