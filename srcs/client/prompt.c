/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 16:40:05 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/30 13:37:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

static void		print_prompt(void)
{
	ft_printf(PROMPT);
}

void			prompt_user(t_client *client)
{
	t_sub			line;

	while (true)
	{
		print_prompt();
		if (get_next_line(0, &line) <= 0)
			break ;
		if (line.length <= 0)
			continue ;
		exec_cmd(client, &line);
	}
	NL;
}
