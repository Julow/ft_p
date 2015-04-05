/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clientcreate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 19:08:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/06 00:14:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int				ft_clientcreate(const char *addr, const char *port)
{
	struct addrinfo	hints;
	struct addrinfo	*res;
	struct protoent	*proto;
	int				fd;

	if ((proto = getprotobyname("tcp")) == NULL)
		return (-1);
	ft_bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = proto->p_proto;
	if (getaddrinfo(addr, port, &hints, &res) != 0)
		return (-1);
	while (res != NULL)
	{
		fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (fd >= 0 && connect(fd, res->ai_addr, res->ai_addrlen) >= 0)
			return (fd);
		if (fd >= 0)
			close(fd);
		res = res->ai_next;
	}
	return (-1);
}
