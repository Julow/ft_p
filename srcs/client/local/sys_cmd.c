/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 12:23:05 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 12:23:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void			sys_cmd(t_client *client, const t_lcmd *cmd, char **args)
{
	pid_t			pid;
	int				status;

	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0)
	{
		execv(cmd->path, args);
		exit(1);
	}
	wait4(pid, &status, 0, NULL);
	(void)client;
}
