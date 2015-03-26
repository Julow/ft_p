/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clientcreate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 19:08:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/26 19:13:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int				ft_clientcreate(const char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	s_addr;

	if ((proto = getprotobyname("tcp")) == NULL)
		return (-1);
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) < 0)
		return (-1);
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(port);
	s_addr.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (struct sockaddr*)&s_addr, sizeof(s_addr)) < 0)
		return (close(sock), -1);
	return (sock);
}
