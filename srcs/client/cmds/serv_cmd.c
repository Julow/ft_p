/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 13:42:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/30 19:45:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

static void		parse_response(t_client *client, const char *cmd_name)
{
	int				c;

	c = '\n';
	while (BG(SIN(client)) != EOF)
	{
		if (c == '\n')
			FL, PS(RESP_PREFIX);
		c = BR(SIN(client));
		PC(c);
	}
	if (c != '\n')
		PC('\n');
	FL;
	if (!BIS(SIN(client), EOF) || !ft_parseint(SIN(client), &c))
	{
		ft_fdprintf(2, ERR_BAD_RESP);
		ft_buffclear(SIN(client));
		return ;
	}
	if (c == 0)
		ft_printf(SUCCS_CMD, cmd_name);
	else
		ft_fdprintf(2, ERR_CMD, cmd_name, c);
	ft_buffclear(SIN(client));
}

void			serv_cmd(t_client *client, char **args)
{
	int				i;

	PS(REQUEST);
	i = -1;
	while (args[++i] != NULL)
	{
		if (i > 0)
		{
			PC(' ');
			ft_writechar(SOUT(client), ' ');
		}
		PS(args[i]);
		ft_writestr(SOUT(client), args[i]);
	}
	NL;
	ft_writechar(SOUT(client), EOF);
	ft_flush(SOUT(client));
	parse_response(client, args[0]);
}
