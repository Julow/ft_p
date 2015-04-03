/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 15:30:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/02 15:43:42 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

void			send_request(t_client *client, char **args)
{
	int				i;

	ft_buffclear(SIN(client));
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
}

t_bool			parse_response(t_client *client, int *status)
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
	if (status != NULL)
		*status = c;
	return (true);
}
