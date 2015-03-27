/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 17:13:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 16:09:40 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"

t_bool			parse_argv(t_server *serv, int argc, char **argv)
{
	int				i;

	i = 1;
	if (i >= argc)
		return (ft_fdprintf(2, ERR_NO_ARG), false);
	if (!ft_sisint(argv[i]))
		return (ft_fdprintf(2, ERR_BAD_PORT, argv[i]), false);
	serv->port = ft_atoi(argv[i]);
	return (true);
}
