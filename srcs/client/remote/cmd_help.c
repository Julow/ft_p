/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 16:00:47 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 16:11:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			cmd_help(t_client *client, char **args)
{
	(void)client;
	(void)args;
	ft_putstr(" -------------- ft_p -------------- \n"
		" - Remote mode -\n"
		" Commands:\n"
		"   LS (dir)      List current directory or arguments dirs\n"
		"   CD <dir>      Change directory\n"
		"   PWD           Print current working directory\n"
		"   MKDIR <dir>   Create a directory\n"
		"   GET <file>    Download a file at the local directory\n"
		"   PUT <file>    Put a file from the local directory to the server\n"
		"   L             Switch local mode\n"
		"   Q(UIT)        Quit ft_p\n");
}
