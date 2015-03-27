/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_msg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 19:14:06 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 16:12:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_MSG_H
# define SERVER_MSG_H

# include "msg.h"

# define USAGE			INFO "Usage: %s <port>" ENDL

# define INFO_LISTEN	INFO "Server running on port %d" ENDL
# define INFO_STOPPED	INFO "Server stopped" ENDL

# define INFO_NEW		INFO "New connexion" ENDL
# define INFO_CLOSED	INFO "Connexion closed" ENDL

# define ERR_NO_ARG		ERROR "Please specify an argument" ENDL
# define ERR_BAD_PORT	ERROR "Not a valid port: %s" ENDL

# define ERR_CANT_PORT	ERROR "Cannot listen port %d" ENDL
# define ERR_NO_FORK	ERROR "Cannot connect client (Fork failed)" ENDL

#endif
