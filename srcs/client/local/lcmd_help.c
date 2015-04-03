/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcmd_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 15:59:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 16:11:20 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			lcmd_help(t_client *client, const t_lcmd *cmd, char **args)
{
	(void)client;
	(void)cmd;
	(void)args;
	ft_putstr(" -------------- ft_p -------------- \n"
		" - Local mode -\n"
		" Commands:\n"
		"   LS (dir)      List current directory or arguments dirs\n"
		"   CD <dir>      Change directory\n"
		"   PWD           Print current working directory\n"
		"   MKDIR <dir>   Create a directory\n"
		"   RMDIR <dir>   Remove a directory\n"
		"   TOUCH <dir>   Create/modify a file\n"
		"   RM <dir>      Remove a file\n"
		"   MV <dir>      Move a file\n"
		"   Q(UIT)        Switch remote move\n");
}
