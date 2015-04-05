/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 15:05:27 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 15:10:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <unistd.h>
#include <stdlib.h>

int				cmd_pwd(t_server *serv, const t_cmd *cmd, char **args)
{
	char			*dir;
	char			*pwd;

	if ((dir = getcwd(NULL, 0)) == NULL)
		return (ft_writestr(SOUT(serv), RESP_ERROR), 1);
	if ((pwd = ft_strstart(dir, serv->root)) == NULL)
		return (ft_writestr(SOUT(serv), RESP_ERROR), 1);
	if (*pwd == '\0')
		ft_writestr(SOUT(serv), "/");
	else
		ft_writestr(SOUT(serv), pwd);
	free(dir);
	return (0);
	(void)cmd;
	(void)args;
}
