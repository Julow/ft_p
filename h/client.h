/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:39:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/01 15:43:22 by jaguillo         ###   ########.fr       */
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

typedef struct	s_file
{
	char			*name;
	int				size;
}				t_file;

int				ft_clientcreate(const char *addr, int port);

t_bool			parse_argv(t_client *client, int argc, char **argv);

void			ft_buffclear(t_buff *buff);
t_bool			ft_parsedata(t_buff *buff, char *dst, int len);

/*
** cmd
*/
void			prompt_user(t_client *client);

void			send_request(t_client *client, char **args);
t_bool			parse_response(t_client *client);

void			exec_cmd(t_client *client, t_sub *line);

void			cmd_get(t_client *client, char **args);
void			serv_cmd(t_client *client, char **args);

#endif
