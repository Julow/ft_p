/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcmd_refresh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 23:30:20 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/04 23:36:48 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <stdlib.h>
#include <unistd.h>

void			lcmd_refresh(t_client *client, const t_lcmd *cmd, char **args)
{
	if (client->lpwd != NULL)
		free(client->lpwd);
	client->lpwd = getcwd(NULL, 0);
	(void)cmd;
	(void)args;
}
