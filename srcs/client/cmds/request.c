/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:57:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/01 19:00:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"
#include <unistd.h>

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
