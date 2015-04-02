/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:42:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/02 16:52:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>

static void		wait_clients(t_server *serv)
{
	int				cs;
	pid_t			pid;

	while ((cs = accept(serv->server, NULL, 0)) >= 0)
	{
		if ((pid = fork()) < 0)
			ft_fdprintf(2, ERR_NO_FORK);
		else if (pid == 0)
		{
			serv->sock.fd = cs;
			serv->sock.in = BUFF(cs, MAL(char, BUFF_SIZE), BUFF_SIZE);
			serv->sock.out = OUT(cs, MAL(char, BUFF_SIZE), BUFF_SIZE);
			ft_printf(INFO_NEW);
			handle_client(serv);
			close(cs);
			free(serv->sock.in.data);
			free(serv->sock.out.buff);
			ft_printf(INFO_CLOSED);
			exit(0);
		}
	}
}

int				main(int argc, char **argv)
{
	t_server		server;

	ft_bzero(&server, sizeof(t_server));
	if (!parse_argv(&server, argc, argv))
		return (ft_fdprintf(2, USAGE, argv[0]), 1);
	if ((server.server = ft_servcreate(server.port)) < 0)
		return (ft_fdprintf(2, ERR_CANT_PORT, server.port), 1);
	ft_printf(INFO_LISTEN, server.port);
	wait_clients(&server);
	close(server.server);
	ft_printf(INFO_STOPPED);
	return (0);
}
