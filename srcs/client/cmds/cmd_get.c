/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:55:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/01 19:48:40 by jaguillo         ###   ########.fr       */
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
	if (!ft_parsedata(SIN(client), file->name, tmp) || !BIS(SIN(client), '\n'))
		return (free(file->name), false);
	file->name[tmp] = '\0';
	if (!ft_parseint(SIN(client), &(file->size)) || !BIS(SIN(client), '\n'))
		return (free(file->name), false);
	return (true);
}

void			cmd_get(t_client *client, char **args)
{
	t_file			file;

	send_request(client, args);
	BG(SIN(client));
	if (!parse_response(client))
		return ;
	if (!parse_resp(client, &file))
	{
		ft_fdprintf(2, ERR_BAD_RESP);
		ft_buffclear(SIN(client));
		return ;
	}
	if (retrieve_file(client, &file))
		ft_printf(SUCCS_GET, args[1]);
	free(file.name);
	if (!parse_response(client))
		ft_buffclear(SIN(client));
}
