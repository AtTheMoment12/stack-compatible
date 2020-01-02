#include "hook.h"
#include "string.h"
#include "/home/lz/f-stack/lib/ff_api.h"



int hook_socket(int domain, int type, int protocol)
{
	return ff_socket(domain, type, protocol);
}
int hook_listen(int s, int backlog)
{
	return ff_listen(s, backlog);
}
int hook_bind(int s, struct hook_sockaddr* addr, __uint32_t addrlen)
{
	struct linux_sockaddr* addr1;
	addr->hook_family = addr1->sa_family;
	strcpy(addr->hook_data,addr1->sa_data);
	return ff_bind(s, addr1, addrlen);
}
int hook_accept(int s, struct hook_sockaddr* addr, __uint32_t* addrlen)
{
	struct linux_sockaddr* addr1;
	addr->hook_family = addr1->sa_family;
	strcpy(addr->hook_data, addr1->sa_data);
	return ff_accept(s, addr1, addrlen);
}
int hook_connect(int s, struct hook_sockaddr* name, __uint32_t namelen)
{
	struct linux_sockaddr* addr1;
	name->hook_family = addr1->sa_family;
	strcpy(name->hook_data, addr1->sa_data);
	return ff_connect(s, addr1, namelen);
}
int hook_close(int fd)
{
	return ff_close(fd);
}
int hook_shutdown(int s, int how)
{
	return ff_shutdown(s, how);
}







