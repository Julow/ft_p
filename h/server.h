/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:39:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 00:10:11 by jaguillo         ###   ########.fr       */
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
	char			*root;
}				t_server;

typedef struct	s_cmd
{
	char			*name;
	int				(*f)(t_server*, const struct s_cmd*, char**);
	char			*path;
}				t_cmd;

int				ft_servcreate(int port);
void			ft_writefile(t_out *dst, int fd);

char			*ft_strstart(char *str, const char *start);

t_bool			parse_argv(t_server *serv, int argc, char **argv);

void			handle_client(t_server *serv);

void			write_eor(t_server *serv, int status);

int				exec_cmd(t_server *serv, const char *cmd);

int				cmd_refresh(t_server *serv, const t_cmd *cmd, char **args);
int				cmd_cd(t_server *serv, const t_cmd *cmd, char **args);
int				cmd_put(t_server *serv, const t_cmd *cmd, char **args);
int				cmd_get(t_server *serv, const t_cmd *cmd, char **args);
int				system_cmd(t_server *serv, const t_cmd *cmd, char **args);

#endif
