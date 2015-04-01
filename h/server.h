/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:39:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/01 13:13:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "ft_p.h"

# define MAX_CLIENTS	42

typedef struct	s_server
{
	int				server;
	int				port;
	t_socket		sock;
}				t_server;

typedef struct	s_cmd
{
	char			*name;
	int				(*f)(t_server*, const struct s_cmd*, char**);
	char			*path;
}				t_cmd;

int				ft_servcreate(int port);

void			ft_buffclear(t_buff *buff);

t_bool			parse_argv(t_server *serv, int argc, char **argv);

void			handle_client(t_server *serv);

int				exec_cmd(t_server *serv, const char *cmd);

int				cmd_get(t_server *serv, const t_cmd *cmd, char **args);
int				system_cmd(t_server *serv, const t_cmd *cmd, char **args);

#endif
