/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   response.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:19:43 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/01 15:48:30 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

t_bool			parse_response(t_client *client)
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
	if (c != 0)
	{
		ft_buffclear(SIN(client));
		ft_fdprintf(2, ERR_CMD, c);
		return (false);
	}
	return (true);
}
