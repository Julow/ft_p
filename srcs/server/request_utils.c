/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 15:23:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 15:24:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <errno.h>

void			write_eor(t_server *serv, int status)
{
	ft_writechar(SOUT(serv), EOF);
	ft_writeint(SOUT(serv), status);
	ft_writechar(SOUT(serv), EOF);
	ft_flush(SOUT(serv));
}

void			write_errno(t_server *serv)
{
	if (errno == EACCES)
		ft_writestr(SOUT(serv), ERR_FILE_RIGHT);
	else if (errno == ENOENT)
		ft_writestr(SOUT(serv), ERR_FILE_NO);
	else if (errno == ELOOP)
		ft_writestr(SOUT(serv), ERR_FILE_LOOP);
	else if (errno == ENOTDIR)
		ft_writestr(SOUT(serv), ERR_FILE_NODIR);
	else if (errno == EISDIR)
		ft_writestr(SOUT(serv), ERR_FILE_DIR);
	else
		ft_writestr(SOUT(serv), ERR_FILE_ERR);
}
