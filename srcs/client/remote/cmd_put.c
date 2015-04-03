/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 15:01:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 20:16:31 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

static t_bool	prompt_overwrite(t_client *client, int *status)
{
	t_sub			sub;

	PS(EXISTS_PROMPT), PS(EXS_PMPT_HELP), FL;
	sub.str = NULL;
	ft_writechar(SOUT(client), '0');
	while (get_next_line(0, &sub) > 0)
	{
		if (ft_match(sub.str, "n*"))
			break ;
		if (ft_match(sub.str, "y*"))
		{
			ft_writechar(SOUT(client), '1');
			break ;
		}
		PS(EXISTS_PROMPT), PS(EXS_PMPT_RE), FL;
		sub.str = NULL;
	}
	if (sub.str == NULL)
		NL;
	ft_writechar(SOUT(client), EOF);
	ft_flush(SOUT(client));
	return (parse_response(client, status));
}

static t_bool	get_file(t_file *file, char *name)
{
	struct stat		stats;

	file->name = name;
	if ((file->fd = open(name, O_RDONLY)) < 0)
	{
		if (errno == ENOENT)
			ft_fdprintf(2, ERR_OPN_NO, name);
		else if (errno == EACCES)
			ft_fdprintf(2, ERR_OPN_RIGHT, name);
		else if (errno == EISDIR)
			ft_fdprintf(2, ERR_OPN_DIR, name);
		else if (errno == ELOOP)
			ft_fdprintf(2, ERR_OPN_LOOP, name);
		else
			ft_fdprintf(2, ERR_OPN_ERR, name);
		return (false);
	}
	if (fstat(file->fd, &stats) < 0)
		return (ft_fdprintf(2, ERR_OPN_ERR, name), false);
	file->size = stats.st_size;
	return (true);
}

void			cmd_put(t_client *client, char **args)
{
	int				status;
	t_file			file;

	if (args[1] == NULL || !get_file(&file, args[1]))
		return ;
	send_request(client, args);
	if (!parse_response(client, &status))
		return ;
	if (status == 2 && !prompt_overwrite(client, &status))
		return ;
	if (status != 0)
		return (ft_fdprintf(2, ERR_CMD, args[0], status), VOID);
	ft_printf("GIVE FILE\n");
	ft_writef(SOUT(client), "%d%{eof}", file.size);
	ft_flush(SOUT(client));
	ft_writefile(SOUT(client), file.fd);
	close(file.fd);
	if (!parse_response(client, NULL))
		ft_fdprintf(2, ERR_BAD_RESP);
}
