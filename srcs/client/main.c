/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:41:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/30 13:37:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"
#include <stdlib.h>
#include <unistd.h>

static t_bool	init_sockets(t_client *client)
{
	int				fd;

	fd = ft_clientcreate(client->serv_addr, client->serv_port);
	if (fd < 0)
		return (false);
	client->sock.fd = fd;
	client->sock.in = BUFF(fd, MAL(char, BUFF_SIZE), BUFF_SIZE);
	client->sock.out = OUT(fd, MAL(char, BUFF_SIZE), BUFF_SIZE);
	return (true);
}

int				main(int argc, char **argv)
{
	t_client		client;

	ft_bzero(&client, sizeof(t_client));
	if (!parse_argv(&client, argc, argv))
		return (ft_fdprintf(2, USAGE, argv[0]), 1);
	ft_printf(INFO_CONN, client.serv_addr, client.serv_port);
	if (!init_sockets(&client))
		return (ft_fdprintf(2, ERR_CANT_CON,
			client.serv_addr, client.serv_port), 1);
	ft_printf(INFO_CONNTED);
	prompt_user(&client);
	close(client.sock.fd);
	return (0);
}
