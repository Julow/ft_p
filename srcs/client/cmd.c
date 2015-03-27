/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 19:08:11 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 20:00:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"
#include <stdlib.h>

const t_cmd		g_cmds[] = {
	{"LS", &cmd_ls},
	{NULL, NULL}
};

void			exec_cmd(t_client *client, t_sub *line)
{
	char			**split;
	int				i;

	ft_printf(INFO_REQUEST, line->str);
	if ((split = ft_strsplit(line->str, ' ')) == NULL)
		return ;
	i = -1;
	while (g_cmds[++i].name != NULL)
	{
		if (ft_strcase(g_cmds[i].name, split[0]))
		{
			g_cmds[i].f(client, split);
			return ;
		}
	}
	ft_fdprintf(2, ERR_BAD_CMD, split[0]);
	i = -1;
	while (split[++i] != NULL)
		free(split[i]);
	free(split);
}
