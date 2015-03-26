/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:41:58 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/26 19:23:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int				main(int argc, char **argv)
{
	t_client		client;

	ft_bzero(&client, sizeof(t_client));
	if (!parse_argv(&client, argc, argv))
		return (ft_fdprintf(2, USAGE, argv[0]), 1);
	if (!ft_clientcreate(client.serv_addr, client.serv_port))
		return (ft_fdprintf(2, ERR_CANT_CON,
			client.serv_addr, client.serv_port), 1);
	return (0);
}
