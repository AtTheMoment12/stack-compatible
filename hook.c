#include "hook.h"





int socket(int domain, int type, int protocol)
{
	printf("hook!!!\n");
	return hook_socket(domain,type,protocol);
}
int listen(int s, int backlog)
{
	printf("ff_listen!!\n");
	return hook_listen(s,backlog);
}
int bind(int s, struct hook_sockaddr* addr, __uint32_t addrlen)
{
	printf("ff_bind!!\n");
	return hook_bind(s,addr,addrlen);
}
int accept(int s, struct hook_sockaddr* addr, __uint32_t* addrlen)
{
	printf("ff_accpet!!\n");
	return hook_accept(s,addr,addrlen);
}
int connect(int s, struct hook_sockaddr* name, __uint32_t namelen)
{
	printf("ff_connect!!\n");
	return hook_connect(s,name,namelen);
}
int close(int fd)
{
	printf("ff_close!!\n");
	return hook_close(fd);
}
int shutdown(int s, int how)
{
	printf("ff_shutdown!!\n");
	return hook_shutdown(s,how);
}

