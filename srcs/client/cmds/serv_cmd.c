/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 13:42:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/01 15:21:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

void			serv_cmd(t_client *client, char **args)
{
	send_request(client, args);
	if (parse_response(client))
	{
		ft_printf(SUCCS_CMD, args[1]);
		ft_buffclear(SIN(client));
	}
}