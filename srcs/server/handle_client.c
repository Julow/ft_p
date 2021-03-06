/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:29:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/02 16:15:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <stdlib.h>

void			handle_client(t_server *serv)
{
	t_string		tmp;
	int				error;

	ft_stringini(&tmp);
	while (!BEOF(SIN(serv)))
	{
		ft_stringclr(&tmp);
		ft_parsesubf(SIN(serv), &tmp, &ft_isascii);
		ft_buffclear(SIN(serv));
		ft_printf(INFO_REQUEST, tmp.content);
		error = exec_cmd(serv, tmp.content);
		if (error == 0)
			ft_printf(SUCCS_CMD, tmp.content);
		else
			ft_printf(ERR_CMD, tmp.content, error);
		write_eor(serv, error);
		ft_buffclear(SIN(serv));
	}
	free(tmp.content);
}
