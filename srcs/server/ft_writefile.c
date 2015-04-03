/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writefile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 19:25:00 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 19:40:46 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <unistd.h>

void			ft_writefile(t_out *dst, int fd)
{
	char			buff[BUFF_SIZE];
	int				len;

	while ((len = read(fd, buff, BUFF_SIZE)) > 0)
		ft_write(dst, buff, len);
	ft_flush(dst);
}
