/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_msg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 19:14:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/05 14:57:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_MSG_H
# define SERVER_MSG_H

# include "msg.h"

# define USAGE			INFO "Usage: %s <port> [path]" ENDL

# define INFO_LISTEN	INFO "Server running on port %d" ENDL
# define INFO_STOPPED	INFO "Server stopped" ENDL

# define INFO_NEW		INFO "New connexion" ENDL
# define INFO_CLOSED	INFO "Connexion closed" ENDL

# define INFO_REQUEST	REQUEST "%s" ENDL

# define SUCCS_CMD		SUCCESS "'%s' executed." ENDL
# define ERR_CMD		ERROR "'%s' failed. (Code %d)" ENDL

# define ERR_NO_ARG		ERROR "Please specify an argument" ENDL
# define ERR_BAD_PORT	ERROR "Not a valid port: %s" ENDL
# define ERR_BAD_PATH	ERROR "Not a valid path: %s" ENDL

# define ERR_CANT_PORT	ERROR "Cannot listen port: %d" ENDL
# define ERR_CANT_PATH	ERROR "Cannot find root directory." ENDL
# define ERR_NO_FORK	ERROR "Cannot connect client (Fork failed)" ENDL
# define ERR_ABORTED	ERROR RESP_ABORT

# define ERR_CD_ROOT	"Cannot go before the root."

# define RESP_ABORT		"Connexion aborted" ENDL
# define RESP_ERROR		"Unexpected error" ENDL
# define RESP_UNSUPTED	"Unsupported command" ENDL
# define RESP_NEEDARG	"Please specify an argument" ENDL
# define RESP_OVRWRITE	"File already exists. Overwrite ?" ENDL

#endif
