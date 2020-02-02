#ifndef PROXY_INCLUDE_SESSION_H__
#define PROXY_INCLUDE_SESSION_H__

#include "list.h"
#include "socket.h"

enum socket_type
{
    SOCKET_TYPE_SERVER,
    SOCKET_TYPE_CLIENT
};

enum port_type
{
    PORT_TYPE_COMMAND,
    PORT_TYPE_DATA
};

enum session_error_type
{
	SESSION_SUCCESS,
	SESSION_INVALID_LIST,
	SESSION_ALLOC_FAILED,
	SESSION_INVALID_SOCKET,
	SESSION_INVALID_PARAMS,
	SESSION_INVALID_SESSION
};

struct session
{
	struct client* client;
	struct server* server;
	struct list list;
};

int add_session_to_list(struct list* session_list, int socket_fd, int socket_type, int port_type);
int remove_session(struct session* target_session);
struct session* get_session_from_list(const struct list* session_list, int socket_fd);
int session_polling(int epoll_fd, struct list* session_list, int proxy_command_socket);

#endif

