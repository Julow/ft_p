/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_mkdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 18:08:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/06 18:34:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <sys/stat.h>
#include <errno.h>

t_bool			make_dir(t_server *serv, const char *path)
{
	if (ft_strchr(path, '/') != NULL)
		return (ft_writestr(SOUT(serv), ERR_MKD_ABS), false);
	if (mkdir(path, 0664) < 0)
	{
		if (errno == EACCES)
			ft_writef(SOUT(serv), ERR_F_RIGHT, path);
		else if (errno == EEXIST)
			ft_writef(SOUT(serv), ERR_F_EXIST, path);
		else if (errno == ELOOP)
			ft_writef(SOUT(serv), ERR_F_LOOP, path);
		else if (errno == ENOENT)
			ft_writef(SOUT(serv), ERR_F_NO, path);
		else if (errno == ENOTDIR)
			ft_writef(SOUT(serv), ERR_F_NODIR, path);
		else
			ft_writef(SOUT(serv), ERR_F_ERR, path);
		return (false);
	}
	return (true);
}

int				cmd_mkdir(t_server *serv, const t_cmd *cmd, char **args)
{
	int				i;

	i = 1;
	while (args[i] != NULL)
	{
		if (!make_dir(serv, args[i]))
			return (2);
		i++;
	}
	if (i <= 1)
		return (ft_writestr(SOUT(serv), RESP_NEEDARG), 1);
	return (0);
	(void)cmd;
}
