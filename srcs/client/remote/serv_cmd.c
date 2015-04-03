/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 13:42:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 12:29:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

void			serv_cmd(t_client *client, char **args)
{
	int				status;

	send_request(client, args);
	if (parse_response(client, &status))
	{
		if (status == 0)
			ft_printf(SUCCS_CMD, args[0]);
		else
			ft_printf(ERR_CMD, args[0], status);
		ft_buffclear(SIN(client));
	}
}
