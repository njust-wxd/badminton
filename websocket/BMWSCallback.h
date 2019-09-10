#ifndef _BMSERVICE_BMWSCALLBACK_H
#define _BMSERVICE_BMWSCALLBACK_H

#include <cstring>
#include "libwebsockets.h"
#include "BMWSService.h"

namespace badminton {
/* one of these created for each message */
struct msg {
	void *payload; /* is malloc'd */
	size_t len;
};

/* one of these is created for each client connecting to us */

struct per_session_data__minimal {
	struct per_session_data__minimal *pss_list;
	struct lws *wsi;
	int last; /* the last message number we sent */
};

/* one of these is created for each vhost our protocol is used with */

struct per_vhost_data__minimal {
	struct lws_context *context;
	struct lws_vhost *vhost;
	const struct lws_protocols *protocol;

	struct per_session_data__minimal *pss_list; /* linked-list of live pss*/

	struct msg amsg; /* the one pending message... */
	int current; /* the current message number we are caching */
};

/* destroys the message when everyone has had a copy of it */

static void
__minimal_destroy_message(void *_msg)
{
	struct msg *msg = (struct msg *)_msg;

	free(msg->payload);
	msg->payload = NULL;
	msg->len = 0;
}

static int
callback_minimal(struct lws *wsi, enum lws_callback_reasons reason,
			void *user, void *in, size_t len)
{
	struct per_session_data__minimal *pss =
			(struct per_session_data__minimal *)user;
	struct per_vhost_data__minimal *vhd =
			(struct per_vhost_data__minimal *)
			lws_protocol_vh_priv_get(lws_get_vhost(wsi),
					lws_get_protocol(wsi));
	int m;
	lwsl_notice("lws_callback_reasons, reason=%d\n", reason);
	switch (reason) {
	case LWS_CALLBACK_PROTOCOL_INIT:
		vhd = (struct per_vhost_data__minimal *)lws_protocol_vh_priv_zalloc(lws_get_vhost(wsi),
				lws_get_protocol(wsi),
				sizeof(struct per_vhost_data__minimal));
		vhd->context = lws_get_context(wsi);
		vhd->protocol = lws_get_protocol(wsi);
		vhd->vhost = lws_get_vhost(wsi);
		break;

	case LWS_CALLBACK_ESTABLISHED:
		/* add ourselves to the list of live pss held in the vhd */
		lws_ll_fwd_insert(pss, pss_list, vhd->pss_list);
		pss->wsi = wsi;
		pss->last = vhd->current;
		BMWSService::getInstance()->onWSEstablished(wsi);
		break;

	case LWS_CALLBACK_CLOSED:
		/* remove our closing pss from the list of live pss */
		lws_ll_fwd_remove(struct per_session_data__minimal, pss_list,
				  pss, vhd->pss_list);
		BMWSService::getInstance()->onWSClosed(wsi);
		break;

	case LWS_CALLBACK_SERVER_WRITEABLE:
		// onWSWritable
		BMWSService::getInstance()->onWSWritable();
		if (!vhd->amsg.payload)
			break;

		if (pss->last == vhd->current)
			break;

		pss->last = vhd->current;
		break;

	case LWS_CALLBACK_RECEIVE:
		// onWSReceive
		BMWSService::getInstance()->onWSReceive(wsi, (char *)in, len);
		if (vhd->amsg.payload)
			__minimal_destroy_message(&vhd->amsg);

		vhd->amsg.len = len;
		/* notice we over-allocate by LWS_PRE */
		vhd->amsg.payload = malloc(LWS_PRE + len);
		if (!vhd->amsg.payload) {
			lwsl_user("OOM: dropping\n");
			break;
		}
		
		memcpy((char *)vhd->amsg.payload + LWS_PRE, in, len);
		vhd->current++;
		break;

    default:
        break;
	}

	return 0;
}

#define LWS_PLUGIN_PROTOCOL_MINIMAL \
	{ \
		"badminton-service", \
		callback_minimal, \
		sizeof(struct per_session_data__minimal), \
		128, \
		0, NULL, 0 \
	}

} // namespace badminton

#endif // _BMSERVICE_BMWSCALLBACK_H