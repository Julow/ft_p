/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_refresh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 23:41:35 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 00:38:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>
#include <stdlib.h>

int				cmd_refresh(t_server *serv, const t_cmd *cmd, char **args)
{
	char			*cwd;
	char			*user_cwd;

	if ((cwd = getcwd(NULL, 0)) == NULL)
		return (2);
	if ((user_cwd = ft_strstart(cwd, serv->root)) == NULL)
		return (2);
	write_eor(serv, 0);
	if (*user_cwd == '\0')
		user_cwd = "/";
	ft_writef(SOUT(serv), "%d\n%s", ft_strlen(user_cwd), user_cwd);
	free(cwd);
	(void)cmd;
	(void)args;
	return (0);
}
