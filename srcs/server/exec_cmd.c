/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 19:01:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 15:06:39 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <stdlib.h>

const t_cmd		g_cmds[] = {
	{"ls", &system_cmd, "/bin/ls"},
	{"refresh", &cmd_refresh, NULL},
	{"pwd", &cmd_pwd, NULL},
	{"cd", &cmd_cd, NULL},
	{"get", &cmd_get, NULL},
	{"put", &cmd_put, NULL},
	{NULL, NULL, NULL}
};

int				exec_cmd(t_server *serv, const char *cmd)
{
	char			**args;
	int				error;
	int				i;

	if ((args = ft_strsplit(cmd, ' ')) == NULL || *args == NULL)
		return (ft_writestr(SOUT(serv), RESP_ERROR), -1);
	i = -1;
	while (g_cmds[++i].name != NULL)
	{
		if (ft_strcase(g_cmds[i].name, args[0]))
		{
			error = g_cmds[i].f(serv, g_cmds + i, args);
			break ;
		}
	}
	if (g_cmds[i].name == NULL)
	{
		error = -2;
		ft_writestr(SOUT(serv), RESP_UNSUPTED);
	}
	i = -1;
	while (args[++i] != NULL)
		free(args[i]);
	free(args);
	return (error);
}
