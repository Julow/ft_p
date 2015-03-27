/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:42:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 19:55:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>

static void		handle_client(t_server *serv)
{
	int				len;
	char			buff[512];

	while ((len = read(serv->client, buff, 512)) > 0)
	{
		ft_printf("Client say: %.*s", len, buff);
		write(serv->client, "0\nLOLOLOLOLOL\n\xFF", 20);
		ft_putchar('\n');
	}
}

static void		wait_clients(t_server *serv)
{
	int				cs;
	pid_t			pid;

	while ((cs = accept(serv->socket, NULL, 0)) >= 0)
	{
		if ((pid = fork()) < 0)
			ft_fdprintf(2, ERR_NO_FORK);
		else if (pid == 0)
		{
			serv->client = cs;
			ft_printf(INFO_NEW);
			handle_client(serv);
			close(cs);
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
	if ((server.socket = ft_servcreate(server.port)) < 0)
		return (ft_fdprintf(2, ERR_CANT_PORT, server.port), 1);
	ft_printf(INFO_LISTEN, server.port);
	wait_clients(&server);
	close(server.socket);
	ft_printf(INFO_STOPPED);
	return (0);
}
