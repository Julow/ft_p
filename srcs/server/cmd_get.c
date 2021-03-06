/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 12:54:50 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/06 17:57:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "server_msg.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int				open_file(t_server *serv, const char *file, t_stat *stats)
{
	int				fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (write_errno(serv), -1);
	if (fstat(fd, stats) < 0)
		return (ft_writestr(SOUT(serv), ERR_FILE_ERR), close(fd), -1);
	if (S_ISDIR(stats->st_mode))
		return (ft_writestr(SOUT(serv), ERR_FILE_DIR), close(fd), -1);
	return (fd);
}

int				cmd_get(t_server *serv, const t_cmd *cmd, char **args)
{
	int				fd;
	struct stat		stats;
	int				tmp;

	if (args[1] == NULL)
		return (ft_writestr(SOUT(serv), RESP_NEEDARG), 2);
	if ((fd = open_file(serv, args[1], &stats)) < 0)
		return (1);
	ft_writef(SOUT(serv), "Name: %s\nSize: %d", args[1], stats.st_size);
	write_eor(serv, 0);
	ft_writef(SOUT(serv), "%d\n%s\n%d%c%{fl}",
		ft_strlen(args[1]), args[1], stats.st_size, EOF);
	if (!ft_parseint(SIN(serv), &tmp) || !BIS(SIN(serv), EOF))
		return (ft_writestr(SOUT(serv), RESP_ERROR), close(fd), 2);
	if (tmp == 0)
		return (close(fd), 0);
	ft_writefile(SOUT(serv), fd);
	ft_flush(SOUT(serv));
	close(fd);
	return (0);
	(void)cmd;
}
