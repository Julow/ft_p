/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_refresh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 23:17:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/06 17:49:47 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"
#include <stdlib.h>

static t_bool	parse_pwd(t_client *client)
{
	char			*path;
	int				len;

	if (!ft_parseint(SIN(client), &len) || !BIS(SIN(client), '\n'))
		return (false);
	path = MAL(char, len + 1);
	if (!ft_parsen(SIN(client), path, len))
		return (free(path), false);
	path[len] = '\0';
	if (client->pwd != NULL)
		free(client->pwd);
	client->pwd = path;
	return (true);
}

void			cmd_refresh(t_client *client, char **args)
{
	const char		*request[] = {"REFRESH", NULL};
	int				status;

	send_request(client, (char**)request);
	if (!parse_response(client, &status))
		return ;
	if (status != 0)
		return (ft_fdprintf(2, ERR_CMD, "REFRESH", status), VOID);
	if (!parse_pwd(client))
		ft_fdprintf(2, ERR_BAD_RESP);
	if (parse_response(client, NULL))
		ft_printf(SUCCS_CMD, "REFRESH");
	(void)args;
}
