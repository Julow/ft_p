/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsedata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:41:52 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/01 15:43:13 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_bool			ft_parsedata(t_buff *buff, char *dst, int len)
{
	int				i;

	i = 0;
	while (i < len && !BEOF(buff))
		dst[i++] = BR(buff);
	if (i == len)
		return (true);
	return (false);
}
