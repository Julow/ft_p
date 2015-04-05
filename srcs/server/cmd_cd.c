/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 23:41:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 14:57:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

static void		cd_root(t_server *serv)
{
	if (chdir(serv->root) != 0)
	{
		ft_writestr(SOUT(serv), RESP_ERROR);
		ft_writestr(SOUT(serv), RESP_ABORT);
		write_eor(serv, 255);
		ft_fdprintf(2, ERR_CANT_PATH);
		ft_fdprintf(2, ERR_ABORTED);
		exit(255);
	}
}

int				cmd_cd(t_server *serv, const t_cmd *cmd, char **args)
{
	char			*dir;

	dir = (args[1] == NULL) ? serv->root : args[1];
	if (chdir(dir) != 0)
	{
		if (errno == EACCES)
			ft_writestr(SOUT(serv), ERR_FILE_RIGHT);
		else if (errno == ENOENT)
			ft_writestr(SOUT(serv), ERR_FILE_NO);
		else if (errno == ELOOP)
			ft_writestr(SOUT(serv), ERR_FILE_LOOP);
		else if (errno == ENOTDIR)
			ft_writestr(SOUT(serv), ERR_FILE_NODIR);
		else
			ft_writestr(SOUT(serv), ERR_FILE_ERR);
		return (1);
	}
	if ((dir = getcwd(NULL, 0)) == NULL)
		return (cd_root(serv), ft_writestr(SOUT(serv), ERR_FILE_ERR), 2);
	if ((dir = ft_strstart(dir, serv->root)) == NULL)
		return (cd_root(serv), ft_writestr(SOUT(serv), ERR_CD_ROOT), 1);
	ft_writef(SOUT(serv), "Path: %s", dir);
	(void)cmd;
	return (0);
}
