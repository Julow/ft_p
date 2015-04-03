/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 15:01:03 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 12:29:23 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "client_msg.h"

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

void			cmd_put(t_client *client, char **args)
{
	int				status;

	send_request(client, args);
	if (!parse_response(client, &status))
		return ;
	if (status == 2 && !prompt_overwrite(client, &status))
		return ;
	if (status != 0)
	{
		ft_fdprintf(2, ERR_CMD, args[0], status);
		return ;
	}
}
