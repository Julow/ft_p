/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 23:41:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 19:57:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <unistd.h>
#include <stdlib.h>

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
	char			*pwd;

	dir = (args[1] == NULL) ? serv->root : args[1];
	if (chdir(dir) != 0)
		return (write_errno(serv), 1);
	if ((dir = getcwd(NULL, 0)) == NULL)
		return (cd_root(serv), ft_writestr(SOUT(serv), ERR_FILE_ERR), 2);
	if ((pwd = ft_strstart(dir, serv->root)) == NULL)
		return (cd_root(serv), ft_writestr(SOUT(serv), ERR_CD_ROOT), 1);
	if (*pwd == '\0')
		pwd = "/";
	ft_writef(SOUT(serv), "Path: %s", pwd);
	write_eor(serv, 0);
	ft_writef(SOUT(serv), "%d\n%s", ft_strlen(pwd), pwd);
	free(dir);
	return (0);
	(void)cmd;
}
