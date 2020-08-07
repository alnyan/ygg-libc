#pragma once
#include <ygg/socket.h>

int socket(int domain, int type, int proto);
int bind(int fd, const struct sockaddr *sa, socklen_t salen);
int connect(int fd, const struct sockaddr *sa, socklen_t salen);
int accept(int fd, struct sockaddr *sa, socklen_t *salen);

ssize_t recvfrom(int fd, void *buf, size_t lim, int flags, struct sockaddr *sa, socklen_t *salen);
ssize_t sendto(int fd, const void *buf, size_t lim, int flags, const struct sockaddr *sa, socklen_t salen);
