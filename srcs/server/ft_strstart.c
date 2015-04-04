/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 00:08:33 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 00:09:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char			*ft_strstart(char *str, const char *start)
{
	while (*str == *start && *start != '\0')
	{
		str++;
		start++;
	}
	if (*start != '\0')
		return (NULL);
	return (str);
}
