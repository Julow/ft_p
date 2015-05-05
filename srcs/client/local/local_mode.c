/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 12:13:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/05/05 16:58:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

const t_lcmd	g_lcmds[] = {
	{"LS", &sys_cmd, "/bin/ls"},
	{"PWD", &sys_cmd, "/bin/pwd"},
	{"MKDIR", &sys_cmd, "/bin/mkdir"},
	{"RMDIR", &sys_cmd, "/bin/rmdir"},
	{"TOUCH", &sys_cmd, "/bin/touch"},
	{"RM", &sys_cmd, "/bin/rm"},
	{"MV", &sys_cmd, "/bin/mv"},
	{"CD", &lcmd_cd, NULL},
	{"REFRESH", &lcmd_refresh, NULL},
	{"H", &lcmd_help, NULL},
	{"HELP", &lcmd_help, NULL},
	{NULL, NULL, NULL}
};

static void		exec_cmd(t_client *client, char **args)
{
	int				i;

	i = -1;
	while (g_lcmds[++i].name != NULL)
		if (ft_strequ(g_lcmds[i].name, args[0]))
		{
			g_lcmds[i].f(client, g_lcmds + i, args);
			break ;
		}
	if (g_lcmds[i].name == NULL)
		ft_fdprintf(2, ERR_BAD_CMD, args[0]);
}

void			local_mode(t_client *client, char **nope)
{
	t_sub			line;
	char			**args;

	lcmd_refresh(client, NULL, NULL);
	while (true)
	{
		ft_printf(LOCAL_PROMPT, client->lpwd);
		if (get_next_line(0, &line) <= 0)
			break ;
		if ((args = ft_strsplit(line.str, ' ')) == NULL || args[0] == NULL)
		{
			if (args[0] == NULL)
				ft_splitfree(args);
			continue ;
		}
		ft_strupper(args[0]);
		if (ft_strequ(args[0], "QUIT") || ft_strequ(args[0], "Q"))
			return (ft_splitfree(args));
		exec_cmd(client, args);
		ft_splitfree(args);
	}
	NL;
	(void)nope;
}
