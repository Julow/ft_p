/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_msg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 19:14:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 20:00:01 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_MSG_H
# define CLIENT_MSG_H

# include "msg.h"

# define USAGE			INFO "Usage: %s <ip> <port>" ENDL

# define PROMPT			"$> "

# define INFO_CONN		INFO "Connecting to %s:%d" ENDL
# define INFO_CONNTED	INFO "Connected" ENDL

# define INFO_REQUEST	REQUEST "%s" ENDL

# define ERR_NO_ARG		ERROR "Not enougth argument" ENDL
# define ERR_BAD_PORT	ERROR "Not a valid port: %s" ENDL

# define ERR_CANT_CON	ERROR "Cannot connect to %s:%d" ENDL

# define ERR_BAD_CMD	ERROR "Unknown command: %s" ENDL

#endif
