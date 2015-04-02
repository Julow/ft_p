/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 15:23:36 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/02 16:15:26 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void			write_eor(t_server *serv, int status)
{
	ft_writechar(SOUT(serv), EOF);
	ft_writeint(SOUT(serv), status);
	ft_writechar(SOUT(serv), EOF);
	ft_flush(SOUT(serv));
}
