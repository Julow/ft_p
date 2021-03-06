/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remote_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 12:18:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/05 16:58:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

const t_cmd		g_cmds[] = {
	{"LS", &serv_cmd},
	{"CD", &cmd_cd},
	{"PWD", &serv_cmd},
	{"MKDIR", &serv_cmd},
	{"GET", &cmd_get},
	{"PUT", &cmd_put},
	{"L", &local_mode},
	{"REFRESH", &cmd_refresh},
	{"H", &cmd_help},
	{"HELP", &cmd_help},
	{NULL, NULL}
};

static void		exec_cmd(t_client *client, char **args)
{
	int				i;

	i = -1;
	while (g_cmds[++i].name != NULL)
		if (ft_strequ(g_cmds[i].name, args[0]))
		{
			g_cmds[i].f(client, args);
			break ;
		}
	if (g_cmds[i].name == NULL)
		ft_fdprintf(2, ERR_BAD_CMD, args[0]);
}

void			remote_mode(t_client *client)
{
	t_sub			line;
	char			**args;

	cmd_refresh(client, NULL);
	while (true)
	{
		ft_printf(REMOTE_PROMPT, client->serv_addr, client->serv_port,
			client->pwd);
		if (get_next_line(0, &line) <= 0)
			return (NL, VOID);
		if ((args = ft_strsplit(line.str, ' ')) == NULL || args[0] == NULL)
		{
			if (args[0] == NULL)
				ft_splitfree(args);
			continue ;
		}
		ft_strupper(args[0]);
		if (ft_strequ(args[0], "QUIT") || ft_strequ(args[0], "Q"))
			return (ft_splitfree(args));
		ft_buffclear(SIN(client));
		exec_cmd(client, args);
		ft_splitfree(args);
	}
	ft_printf(INFO_CLOSED);
}
