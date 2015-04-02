/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 19:19:14 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/02 15:14:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

static int		prompt_get_fd(t_file *file)
{
	t_sub			sub;

	PS(EXISTS_PROMPT), PS(EXS_PMPT_HELP), FL;
	while (get_next_line(0, &sub) > 0)
	{
		if (ft_match(sub.str, "n*"))
			return (-2);
		if (ft_match(sub.str, "y*"))
			return (open(file->name, O_WRONLY | O_TRUNC, 0644));
		PS(EXISTS_PROMPT), PS(EXS_PMPT_RE), FL;
	}
	NL;
	return (-2);
}

static int		get_fd(t_file *file)
{
	int				fd;

	if ((fd = open(file->name, O_WRONLY | O_CREAT | O_EXCL, 0644)) >= 0)
		return (fd);
	if (errno == EEXIST)
	{
		if ((fd = prompt_get_fd(file)) != -1)
			return (fd);
	}
	if (errno == EACCES)
		ft_fdprintf(2, ERR_RETV_RIGHT, file->name);
	else if (errno == EISDIR)
		ft_fdprintf(2, ERR_RETV_DIR, file->name);
	else if (errno == ELOOP)
		ft_fdprintf(2, ERR_RETV_LOOP, file->name);
	else
		ft_fdprintf(2, ERR_RETV_ERR, file->name);
	return (-1);
}

t_bool			retrieve_file(t_client *client, t_file *file)
{
	int				fd;
	char			buff[BUFF_SIZE];
	t_out			out;
	int				i;

	if ((fd = get_fd(file)) < 0)
		return (false);
	out = OUT(fd, buff, BUFF_SIZE);
	i = file->size;
	while (i-- > 0)
		ft_writechar(&out, BR(SIN(client)));
	ft_flush(&out);
	close(fd);
	return (true);
}
