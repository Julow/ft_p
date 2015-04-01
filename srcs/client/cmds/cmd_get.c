/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:55:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/01 13:32:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			cmd_get(t_client *client, char **args)
{
	int				file_size;

	if (!send_request(client, args))
	{
		ft_printf("lolage total\n");
		return ;
	}
	if (ft_parseint(SIN(client), &file_size) && BIS(SIN(client), EOF))
	{
		ft_printf("// file_size: %d\n", file_size);
		while (file_size-- > 0)
			PC(BR(SIN(client)));
		FL;
	}
	else
		ft_printf("server loling, lol\n");
	ft_buffclear(SIN(client));
}
