/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 19:08:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/02 20:19:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"
#include <stdlib.h>

const t_cmd		g_cmds[] = {
	{"ls", &serv_cmd, NULL},
	{"cd", &serv_cmd, NULL},
	{"pwd", &serv_cmd, NULL},
	{"mkdir", &serv_cmd, NULL},
	{"get", &cmd_get, NULL},
	{"put", &cmd_put, NULL},
	{"lls", &sys_cmd, "/bin/ls"},
	{"lpwd", &sys_cmd, "/bin/pwd"},
	{NULL, NULL, NULL}
};

void			exec_cmd(t_client *client, t_sub *line)
{
	char			**split;
	int				i;

	if ((split = ft_strsplit(line->str, ' ')) == NULL)
		return ;
	i = -1;
	while (g_cmds[++i].name != NULL)
	{
		if (ft_strcase(g_cmds[i].name, split[0]))
		{
			ft_strupper(split[0]);
			g_cmds[i].f(client, g_cmds + i, split);
			break ;
		}
	}
	if (g_cmds[i].name == NULL)
		ft_fdprintf(2, ERR_BAD_CMD, split[0]);
	i = -1;
	while (split[++i] != NULL)
		free(split[i]);
	free(split);
}
