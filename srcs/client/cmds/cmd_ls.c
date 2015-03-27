/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 19:20:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 19:52:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			cmd_ls(t_client *client, char **argv)
{
	int				i;

	ft_writestr(SOUT(client), "LS");
	i = 0;
	while (argv[++i] != NULL)
	{
		ft_writechar(SOUT(client), ' ');
		ft_writestr(SOUT(client), argv[i]);
	}
	ft_writechar(SOUT(client), EOF);
	ft_flush(SOUT(client));
	wait_response(client);
}
