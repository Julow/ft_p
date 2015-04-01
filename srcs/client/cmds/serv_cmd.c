/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serv_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 13:42:31 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/01 13:05:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			serv_cmd(t_client *client, char **args)
{
	if (send_request(client, args))
		ft_buffclear(SIN(client));
}
