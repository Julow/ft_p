/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 17:13:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 23:45:44 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <unistd.h>

t_bool			parse_argv(t_server *serv, int argc, char **argv)
{
	if (argc <= 1)
		return (ft_fdprintf(2, ERR_NO_ARG), false);
	if (!ft_sisint(argv[1]))
		return (ft_fdprintf(2, ERR_BAD_PORT, argv[1]), false);
	serv->port = argv[1];
	if (argc > 2 && chdir(argv[2]) != 0)
		return (ft_fdprintf(2, ERR_BAD_PATH, argv[2]), false);
	return (true);
}
