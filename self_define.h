#define MSG_MAX_LEN 1024

// what's PRTC short for ??
typedef enum CONN_PRTC{
	CONN_TCP_SERVER = 0,
	CONN_TCP_CLIENT = 1,  // use this
	CONN_UDP_SERVER ,
	CONN_UDP_CLIENT , 
	PROTOCOL_NUM
}CONN_PRTC;


