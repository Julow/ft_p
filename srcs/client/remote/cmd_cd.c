/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 17:03:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 19:58:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"
#include <stdlib.h>

void			cmd_cd(t_client *client, char **args)
{
	int				len;

	send_request(client, args);
	if (!parse_response(client, &len))
		return ;
	if (len != 0)
		return (ft_fdprintf(2, ERR_CMD, args[0], len), VOID);
	if (!ft_parseint(SIN(client), &len) || !BIS(SIN(client), '\n'))
		return (ft_fdprintf(2, ERR_BAD_RESP), VOID);
	if (client->pwd != NULL)
		free(client->pwd);
	client->pwd = MAL(char, len + 1);
	if (!ft_parsen(SIN(client), client->pwd, len))
		return ((client->pwd[0] = '\0'), ft_fdprintf(2, ERR_BAD_RESP), VOID);
	client->pwd[len] = '\0';
	if (parse_response(client, NULL))
		ft_printf(SUCCS_CMD, args[0]);
}
