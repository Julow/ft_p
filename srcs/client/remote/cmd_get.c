/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:55:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/06 17:57:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"
#include <stdlib.h>

static t_bool	parse_resp(t_client *client, t_file *file)
{
	int				tmp;

	if (!ft_parseint(SIN(client), &tmp) || !BIS(SIN(client), '\n'))
		return (false);
	if ((file->name = MAL(char, tmp + 1)) == NULL)
		return (false);
	if (!ft_parsen(SIN(client), file->name, tmp) || !BIS(SIN(client), '\n'))
		return (free(file->name), false);
	file->name[tmp] = '\0';
	if (!ft_parseint(SIN(client), &(file->size)) || !BIS(SIN(client), EOF))
		return (free(file->name), false);
	return (true);
}

void			cmd_get(t_client *client, char **args)
{
	t_file			file;
	int				status;

	send_request(client, args);
	if (!parse_response(client, &status))
		return ;
	if (status != 0)
		return (ft_fdprintf(2, ERR_CMD, args[0], status), VOID);
	if (!parse_resp(client, &file))
		return (ft_fdprintf(2, ERR_BAD_RESP), ft_buffclear(SIN(client)), VOID);
	if (retrieve_file(client, &file))
		ft_printf(SUCCS_GET, args[1]);
	free(file.name);
	if (!parse_response(client, &status) || status != 0)
		ft_fdprintf(2, ERR_BAD_RESP);
}
