/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_msg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 19:14:39 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 19:05:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_MSG_H
# define CLIENT_MSG_H

# include "msg.h"

# define USAGE			INFO "Usage: %s <ip> <port>" ENDL

# define REMOTE_PROMPT	C_RESET "remote > "
# define LOCAL_PROMPT	C_RESET "local > "

# define EXISTS_PROMPT	C_RESET "File already exists. Overwrite ? "
# define EXS_PMPT_HELP	"(y/n) "
# define EXS_PMPT_RE	"(Please type 'y' or 'n') "

# define RESP_PREFIX	C_GRAY "> "

# define INFO_CONN		INFO "Connecting to %s:%d..." ENDL
# define INFO_CONNTED	INFO "Connected." ENDL

# define INFO_REQUEST	REQUEST "%s" ENDL

# define SUCCS_GET		SUCCESS "File '%s' succefully retrieved!" ENDL

# define SUCCS_CMD		SUCCESS "Request '%s' succefully executed!" ENDL
# define ERR_CMD		ERROR "Request '%s' failed. (Code %d)" ENDL
# define ERR_BAD_RESP	ERROR "Bad response." ENDL

# define ERR_NO_ARG		ERROR "Not enougth argument." ENDL
# define ERR_BAD_PORT	ERROR "Not a valid port: %s" ENDL

# define ERR_CANT_CON	ERROR "Cannot connect to %s:%d" ENDL

# define ERR_BAD_CMD	ERROR "Unknown command: %s" ENDL

# define ERR_OPN_NO		ERROR "%s: " ERR_FILE_NO
# define ERR_OPN_RIGHT	ERROR "%s: " ERR_FILE_RIGHT
# define ERR_OPN_DIR	ERROR "%s: " ERR_FILE_DIR
# define ERR_OPN_LOOP	ERROR "%s: " ERR_FILE_LOOP
# define ERR_OPN_ERR	ERROR "%s: " ERR_FILE_ERR

# define ERR_RETV_RIGHT	ERROR "%s: File exists: " ERR_FILE_RIGHT
# define ERR_RETV_DIR	ERROR "%s: File exists: " ERR_FILE_DIR
# define ERR_RETV_LOOP	ERROR "%s: " ERR_FILE_LOOP
# define ERR_RETV_ERR	ERROR "%s: Cannot acces: " ERR_FILE_ERR

#endif
