/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 16:29:23 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/30 19:41:09 by jaguillo         ###   ########.fr       */
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
		ft_writechar(SOUT(serv), EOF);
		ft_writeint(SOUT(serv), error);
		ft_writechar(SOUT(serv), EOF);
		if (error == 0)
			ft_printf(SUCCS_CMD, tmp.content);
		else
			ft_printf(ERR_CMD, tmp.content, error);
		ft_flush(SOUT(serv));
	}
	free(tmp.content);
}
