/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 14:39:30 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/26 17:05:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTION	42

int				create_server(int port)
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
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (struct sockaddr*)&s_addr, sizeof(s_addr)) < 0)
		return (close(sock), -1);
	if (listen(sock, MAX_CONNECTION) < 0)
		return (close(sock), -1);
	return (sock);
}

void			read_socket(int cs)
{
	int				len;
	char			buff[512];

	printf("HE IS FUCKING WRITING\n");
	while ((len = read(cs, buff, 512)) > 0)
		printf("%.*s", len, buff);
	printf("GOOD BY BRO\n");
}

void			accept_client(int sock)
{
	int					cs;
	struct sockaddr_in	cin;
	unsigned int		cin_len;

	printf("LOLING WHILE NOBODY\n");
	// cs = accept(sock, (struct sockaddr*)&cin, &cin_len);
	cs = accept(sock, NULL, 0);
	printf("SOMEONE FUCKING HERE\n");
	read_socket(cs);
	(void)cin;
	(void)cin_len;
	close(cs);
}

int				main(int argc, char **argv)
{
	int				sock;

	if (argc < 2)
		return (printf("LOL FUCK DAT ARGV\n"), 1);
	if ((sock = create_server(atoi(argv[1]))) < 0)
		return (printf("NO CHAUSSETTE\n"), 1);
	while (1)
		accept_client(sock);
	close(sock);
	return (0);
}
