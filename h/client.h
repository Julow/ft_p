/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:39:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/30 16:31:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "ft_p.h"

typedef struct	s_client
{
	t_socket		sock;
	char			*serv_addr;
	int				serv_port;
}				t_client;

typedef struct	s_cmd
{
	char			*name;
	void			(*f)(t_client*, char**);
}				t_cmd;

int				ft_clientcreate(const char *addr, int port);

t_bool			parse_argv(t_client *client, int argc, char **argv);

void			ft_buffclear(t_buff *buff);

/*
** cmd
*/
void			prompt_user(t_client *client);

void			exec_cmd(t_client *client, t_sub *line);

void			serv_cmd(t_client *client, char **args);

#endif
