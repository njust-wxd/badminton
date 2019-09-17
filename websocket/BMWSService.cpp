#include "BMWSService.h"
#include "BMWSCallback.h"
#include "BMLogWrap.h"
#include "BMDefine.h"
#include "json/json.h"
#include "BMService.h"
#include "BMMatch.h"
#include "BMGame.h"
#include "BMPlayer.h"

#include <cstring>
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace badminton {
const static std::string CMD_START_MATCH = "CMD_START_MATCH";
const static std::string CMD_MATCH_RESULT = "CMD_MATCH_RESULT";

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
    if (CMD_START_MATCH == cmd)
    {
        BMSLOG_I("CMD_START_MATCH");
        std::vector<std::string> players;
        for (auto jplayer : root["players"])
        {
            players.push_back(jplayer.asString());
        }
        m_pService->startMatch(8, players);
    }
    else if (CMD_MATCH_RESULT == cmd)
    {
        BMSLOG_I("CMD_MATCH_RESULT");
        BMMatch match;
        match.setName("八人转");
        match.setType(8);

        vector<BMPlayer> players;
        for (auto jplayer : root["players"])
        {
            BMPlayer player;
            player.setName(jplayer.asString());
            players.push_back(player);
        }
        match.setPlayers(players);
        vector<BMGame> games;
        for (auto jresult : root["result"])
        {
            BMGame game;
            BMPlayer player_a1, player_a2, player_b1, player_b2;
            player_a1.setName(jresult["player_a1"].asString());
            player_a2.setName(jresult["player_a2"].asString());
            player_b1.setName(jresult["player_b1"].asString());
            player_b2.setName(jresult["player_b2"].asString());
            game.addPlayerA(player_a1);
            game.addPlayerA(player_a2);
            game.addPlayerB(player_b1);
            game.addPlayerB(player_b2);
            int score_a = jresult["score_a"].asInt();
            int score_b = jresult["score_b"].asInt();
            game.setScore(score_a, score_b);
            games.push_back(game);
        }
        match.setGames(games);
        m_pService->handleMatchResult(match);
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
