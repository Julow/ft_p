/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:54:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/01 13:25:29 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

# include <string.h> // tmp
# include <errno.h> // tmp

int				cmd_get(t_server *serv, const t_cmd *cmd, char **args)
{
	int				fd;
	struct stat		stats;

	if (args[1] == NULL)
		return (ft_writestr(SOUT(serv), RESP_NEEDARG), 2);
	if ((fd = open(args[1], O_RDONLY)) < 0)
		return (ft_writestr(SOUT(serv), strerror(errno)), 1);
	if (fstat(fd, &stats) < 0)
		return (ft_writestr(SOUT(serv), strerror(errno)), 1);
	ft_writechar(SOUT(serv), EOF);
	ft_writechar(SOUT(serv), '0');
	ft_writechar(SOUT(serv), EOF);
	ft_writeint(SOUT(serv), stats.st_size);
	ft_writechar(SOUT(serv), EOF);
	ft_flush(SOUT(serv));
	dup2(SOUT(serv)->fd, fd);
	close(fd);
	(void)cmd;
	return (0);
}
