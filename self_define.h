#include <list.h>

#define MSG_MAX_LEN 1024

// what's PRTC short for ??
typedef enum CONN_PRTC{
	CONN_TCP_SERVER = 0,
	CONN_TCP_CLIENT = 1,  // use this
	CONN_UDP_SERVER,
	CONN_UDP_CLIENT, 
	PROTOCOL_NUM
}CONN_PRTC;

typedef struct task_object_t{
	char *send_msg;
	int msg_length;
	unsigned int task_period;
	unsigned int ms_timeout;
	int task_index;
	char task_desc[32];
}task_obj;

typedef struct conn_objct_t{
	char ip_addr[16];
	unsigned short port;
	int sock_fd;
	int conn_mode;
	char *msg_content;
	iop_lock_t lock;
	iop_list_head_t task_list;
}conn_obj;
