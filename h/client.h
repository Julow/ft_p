/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:39:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 12:47:16 by jaguillo         ###   ########.fr       */
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

typedef struct	s_lcmd
{
	char			*name;
	void			(*f)(t_client*, const struct s_lcmd*, char**);
	char			*path;
}				t_lcmd;

typedef struct	s_file
{
	char			*name;
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

void			cmd_get(t_client *client, char **args);
t_bool			retrieve_file(t_client *client, t_file *file);

void			cmd_put(t_client *client, char **args);

/*
** local mode
*/
void			local_mode(t_client *client, char **args);

void			sys_cmd(t_client *client, const t_lcmd *cmd, char **args);

/*
** ft
*/
void			ft_splitfree(char **split);
int				ft_clientcreate(const char *addr, int port);
void			ft_buffclear(t_buff *buff);
t_bool			ft_parsedata(t_buff *buff, char *dst, int len);

#endif
