/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_msg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 19:14:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/01 15:22:03 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_MSG_H
# define CLIENT_MSG_H

# include "msg.h"

# define USAGE			INFO "Usage: %s <ip> <port>" ENDL

# define PROMPT			C_RESET "$> "

# define RESP_PREFIX	C_GRAY "> "

# define INFO_CONN		INFO "Connecting to %s:%d..." ENDL
# define INFO_CONNTED	INFO "Connected." ENDL

# define INFO_REQUEST	REQUEST "%s" ENDL

# define SUCCS_GET		SUCCESS "File '%s' succefully retrieved!" ENDL

# define SUCCS_CMD		SUCCESS "Request succefully executed!" ENDL
# define ERR_CMD		ERROR "Request failed. (Code %d)" ENDL
# define ERR_BAD_RESP	ERROR "Bad response." ENDL

# define ERR_NO_ARG		ERROR "Not enougth argument." ENDL
# define ERR_BAD_PORT	ERROR "Not a valid port: %s" ENDL

# define ERR_CANT_CON	ERROR "Cannot connect to %s:%d" ENDL

# define ERR_BAD_CMD	ERROR "Unknown command: %s" ENDL

#endif
