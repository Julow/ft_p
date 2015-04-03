/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 12:13:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 12:48:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

const t_lcmd	g_lcmds[] = {
	{"LS", &sys_cmd, "/bin/ls"},
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

	while (true)
	{
		ft_printf(LOCAL_PROMPT);
		if (get_next_line(0, &line) <= 0)
			break ;
		if (line.length <= 0)
			continue ;
		if ((args = ft_strsplit(line.str, ' ')) == NULL)
			continue ;
		ft_strupper(args[0]);
		if (ft_strequ(args[0], "QUIT") || ft_strequ(args[0], "Q"))
			return (ft_splitfree(args));
		exec_cmd(client, args);
		ft_splitfree(args);
	}
	NL;
	(void)nope;
}