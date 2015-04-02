/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 19:08:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/02 16:35:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"
#include <stdlib.h>

const t_cmd		g_cmds[] = {
	{"ls", &serv_cmd},
	{"cd", &serv_cmd},
	{"pwd", &serv_cmd},
	{"mkdir", &serv_cmd},
	{"get", &cmd_get},
	{"put", &cmd_put},
	{NULL, NULL}
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
			g_cmds[i].f(client, split);
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
