/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_servcreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 17:04:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/06 00:32:02 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int				ft_servcreate(const char *port)
{
	struct addrinfo	hints;
	struct addrinfo	*res;
	struct protoent	*proto;
	int				fd;

	if ((proto = getprotobyname("tcp")) == NULL)
		return (-1);
	ft_bzero(&hints, sizeof(struct addrinfo));
	hints.ai_family = AF_INET6;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	hints.ai_protocol = proto->p_proto;
	if (getaddrinfo(NULL, port, &hints, &res) != 0)
		return (-1);
	while (res != NULL)
	{
		fd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (fd >= 0 && bind(fd, res->ai_addr, res->ai_addrlen) == 0
			&& listen(fd, MAX_CLIENTS) == 0)
			return (fd);
		if (fd >= 0)
			close(fd);
		res = res->ai_next;
	}
	return (-1);
}
