#ifndef PING_H
#define PING_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

#include "opt.h"

#define PKT_SIZE 64

typedef struct s_pkt
{
	char		hdr_buf[PKT_SIZE];
	struct iphdr	*ip;
	struct icmphdr	*hdr;
} t_pkt;

opt_t parse_opt(int ac, char **av);
int handle_opt(opt_t opt);

int ft_strcmp(char *s1, char *s2);

#endif
