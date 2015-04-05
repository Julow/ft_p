/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 19:12:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 23:46:00 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

t_bool			parse_argv(t_client *client, int argc, char **argv)
{
	int				i;

	i = 1;
	if (i >= argc)
		return (ft_fdprintf(2, ERR_NO_ARG), false);
	if (ft_strcase(argv[i], "localhost"))
		client->serv_addr = "127.0.0.1";
	else
		client->serv_addr = argv[i];
	i++;
	if (i >= argc)
		return (ft_fdprintf(2, ERR_NO_ARG), false);
	if (!ft_sisint(argv[i]))
		return (ft_fdprintf(2, ERR_BAD_PORT, argv[i]), false);
	client->serv_port = argv[i++];
	return (true);
}
