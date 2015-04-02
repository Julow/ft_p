/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 15:00:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/02 16:41:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

static int		ask_overwrite(t_server *serv, const char *file)
{
	int				status;

	ft_writestr(SOUT(serv), RESP_OVRWRITE);
	ft_buffclear(SIN(serv));
	write_eor(serv, 2);
	if (!ft_parseint(SIN(serv), &status) || !BIS(SIN(serv), EOF))
		return (-2);
	if (status == 0)
		return (-2);
	return (open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644));
}

static int		get_fd(t_server *serv, const char *file)
{
	int				fd;

	if ((fd = open(file, O_WRONLY | O_CREAT | O_EXCL, 0644)) >= 0)
		return (fd);
	if (errno == EEXIST)
	{
		if ((fd = ask_overwrite(serv, file)) != -1)
			return (fd);
	}
	if (errno == EACCES)
		ft_writestr(SOUT(serv), ERR_FILE_RIGHT);
	else if (errno == EISDIR)
		ft_writestr(SOUT(serv), ERR_FILE_DIR);
	else if (errno == ELOOP)
		ft_writestr(SOUT(serv), ERR_FILE_LOOP);
	else
		ft_writestr(SOUT(serv), ERR_FILE_ERR);
	return (-1);
}

int				cmd_put(t_server *serv, const t_cmd *cmd, char **args)
{
	int				fd;

	if ((fd = get_fd(serv, args[1])) < 0)
		return (1);
	ft_writestr(SOUT(serv), "fd: ");
	ft_writeint(SOUT(serv), fd);
	(void)cmd;
	// ft_writestr(SOUT(serv), "OK\n");
	close(fd);
	return (0);
}
