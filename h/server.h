/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:39:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 18:09:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "ft_p.h"

# define MAX_CLIENTS	32

typedef struct	s_server
{
	int				socket;
	int				port;
	int				client;
}				t_server;

int				ft_servcreate(int port);

t_bool			parse_argv(t_server *serv, int argc, char **argv);

#endif
