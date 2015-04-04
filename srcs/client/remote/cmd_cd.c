/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 17:03:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 00:39:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			cmd_cd(t_client *client, char **args)
{
	serv_cmd(client, args);
	cmd_refresh(client, NULL);
}
