/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_response.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 19:28:19 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 19:52:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

void			wait_response(t_client *client)
{
	int				status;

	if (!ft_parseint(SIN(client), &status))
		return ;
	if (status > 0)
		PS(ERROR);
	else
		PS(SUCCESS);
	if (BIS(SIN(client), EOF))
		PC('\n');
	else if (BIS(SIN(client), '\n'))
		ft_parsewrite(SIN(client), FTOUT, EOF);
	FL;
}
