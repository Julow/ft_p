/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sisip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 19:26:04 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/26 19:56:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_bool			ft_sisip(const char *str)
{
	int				i;

	i = 0;
	while (i < 3)
	{
		if (!ft_isdigit(*(str++)))
			return (false);
		while (ft_isdigit(*str))
			str++;
		i++;
		if (i < 3 && *(str++) != '.')
			return (false);
	}
	if (*str != '\0')
		return (false);
	return (true);
}
