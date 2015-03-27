/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsewrite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 19:33:49 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 19:36:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_bool			ft_parsewrite(t_buff *buff, t_out *out, char end)
{
	while (!BEOF(buff))
	{
		if (BG(buff) == end)
			return (true);
		ft_writechar(out, BR(buff));
	}
	return (false);
}
