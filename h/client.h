/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:39:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 23:46:08 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "ft_p.h"

typedef struct	s_client
{
	t_socket		sock;
	char			*serv_addr;
	char			*serv_port;
	char			*pwd;
	char			*lpwd;
}				t_client;

typedef struct	s_cmd
{
	char			*name;
	void			(*f)(t_client*, char**);
}				t_cmd;

typedef struct	s_lcmd
{
	char			*name;
	void			(*f)(t_client*, const struct s_lcmd*, char**);
	char			*path;
}				t_lcmd;

typedef struct	s_file
{
	char			*name;
	int				fd;
	int				size;
}				t_file;

/*
** main
*/
t_bool			parse_argv(t_client *client, int argc, char **argv);

void			prompt_user(t_client *client);

/*
** remove mode
*/
void			remote_mode(t_client *client);

void			send_request(t_client *client, char **args);
t_bool			parse_response(t_client *client, int *status);

void			serv_cmd(t_client *client, char **args);

void			cmd_cd(t_client *client, char **args);
void			cmd_refresh(t_client *client, char **args);
void			cmd_help(t_client *client, char **args);

void			cmd_get(t_client *client, char **args);
t_bool			retrieve_file(t_client *client, t_file *file);

void			cmd_put(t_client *client, char **args);

/*
** local mode
*/
void			local_mode(t_client *client, char **args);

void			lcmd_help(t_client *client, const t_lcmd *cmd, char **args);
void			lcmd_cd(t_client *client, const t_lcmd *cmd, char **args);
void			lcmd_refresh(t_client *client, const t_lcmd *cmd, char **args);
void			sys_cmd(t_client *client, const t_lcmd *cmd, char **args);

/*
** ft
*/
int				ft_clientcreate(const char *addr, const char *port);
void			ft_writefile(t_out *dst, int fd);

#endif
