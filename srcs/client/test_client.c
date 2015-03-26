/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 14:40:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/26 14:58:33 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int				create_client(const char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	s_addr;

	proto = getprotobyname("tcp");
	if (proto == NULL)
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

void			test_client(int sock)
{
	int				len;
	char			buff[512];

	printf("WRITE SOME SHIT HERE SO I CAN TELL MY BRO\n");
	while ((len = read(0, buff, 512)) > 0)
		write(sock, buff, len);
	printf("BY BITCH\n");
}

int				main(int argc, char **argv)
{
	int				sock;

	if (argc < 3)
		return (printf("NOOB addr port"), 1);
	if ((sock = create_client(argv[1], atoi(argv[2]))) < 0)
		return (printf("FUCKED CONNECTION\n"), 1);
	test_client(sock);
	close(sock);
	return (0);
}
