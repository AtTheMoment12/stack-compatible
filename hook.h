#include <stdio.h>


struct hook_sockaddr {
	short hook_family;
	char hook_data[126];
};



int hook_socket(int domain, int type, int protocol);
int hook_listen(int s, int backlog);
int hook_bind(int s, struct hook_sockaddr* addr, __uint32_t addrlen);
int hook_accept(int s, struct hook_sockaddr* addr, __uint32_t* addrlen);
int hook_connect(int s, struct hook_sockaddr* name, __uint32_t namelen);
int hook_close(int fd);
int hook_shutdown(int s, int how);
