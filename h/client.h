/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 15:39:56 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 19:35:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "ft_p.h"

typedef struct	s_socket
{
	int				fd;
	t_buff			in;
	t_out			out;
}				t_socket;

typedef struct	s_client
{
	t_socket		sock;
	char			*serv_addr;
	int				serv_port;
}				t_client;

typedef struct	s_cmd
{
	char			*name;
	void			(*f)(t_client*, char **);
}				t_cmd;

# define SIN(c)		(&((c)->sock.in))
# define SOUT(c)	(&((c)->sock.out))

# define BUFF_SIZE	512

int				ft_clientcreate(const char *addr, int port);

t_bool			parse_argv(t_client *client, int argc, char **argv);

void			print_prompt(void);

t_bool			ft_parsewrite(t_buff *buff, t_out *out, char end);

/*
** cmd
*/

void			exec_cmd(t_client *client, t_sub *line);
void			wait_response(t_client *client);

void			cmd_ls(t_client *client, char **argv);

#endif
