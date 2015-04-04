/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 19:07:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/04 16:32:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int				system_cmd(t_server *serv, const t_cmd *cmd, char **args)
{
	pid_t			pid;
	int				status;

	if ((pid = fork()) < 0)
		return (ft_writestr(SOUT(serv), RESP_ERROR), -1);
	if (pid == 0)
	{
		dup2(serv->sock.fd, 1);
		dup2(serv->sock.fd, 2);
		execv(cmd->path, args);
		ft_writestr(SOUT(serv), RESP_ERROR);
		exit(-1);
	}
	wait4(pid, &status, 0, NULL);
	if (WIFSIGNALED(status))
		return (-100 - WTERMSIG(status));
	return (WEXITSTATUS(status));
}
