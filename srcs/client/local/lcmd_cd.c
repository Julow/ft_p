/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcmd_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 17:05:16 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/04 23:38:24 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"
#include <unistd.h>
#include <errno.h>

void			lcmd_cd(t_client *client, const t_lcmd *cmd, char **args)
{
	char			*dir;

	if (args[1] != NULL)
		dir = args[1];
	else if ((dir = ft_getenv("HOME")) == NULL)
		ft_fdprintf(2, ERR_CD_HOME);
	if (dir != NULL && chdir(dir) != 0)
	{
		if (errno == EACCES)
			ft_fdprintf(2, ERR_CD_RIGHT, dir);
		else if (errno == ENOTDIR)
			ft_fdprintf(2, ERR_CD_NODIR, dir);
		else if (errno == ELOOP)
			ft_fdprintf(2, ERR_CD_LOOP, dir);
		else
			ft_fdprintf(2, ERR_CD_NO, dir);
	}
	(void)cmd;
	lcmd_refresh(client, NULL, NULL);
}
