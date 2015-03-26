/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 17:16:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/26 19:02:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# include <ft_colors.h>

# define NAME			"ft_p"

# define ENDL			"\n"
# define INFO			C_CYAN "[INFO]" C_RESET " "
# define ERROR			C_RED "[Error]" C_RESET " "

/*
** ========================================================================== **
** client
*/

/*
** ========================================================================== **
** server
*/

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
