/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:57:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/01 13:32:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

static t_bool	parse_response(t_client *client, const char *cmd_name)
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
	if (!BIS(SIN(client), EOF) || !ft_parseint(SIN(client), &c)
		|| !BIS(SIN(client), EOF))
	{
		ft_fdprintf(2, ERR_BAD_RESP);
		ft_buffclear(SIN(client));
		return (false);
	}
	if (c == 0)
		return (ft_printf(SUCCS_CMD, cmd_name), true);
	else
	{
		ft_buffclear(SIN(client));
		ft_fdprintf(2, ERR_CMD, cmd_name, c);
		return (false);
	}
}

t_bool			send_request(t_client *client, char **args)
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
	return (parse_response(client, args[0]));
}
