/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 17:16:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/06 18:32:07 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

# include <ft_colors.h>

# define NAME			"ft_p"

# define ENDL			"\n"
# define INFO			C_CYAN "[INFO]" C_RESET " "
# define REQUEST		C_LGRAY "[Request]" C_RESET " "
# define SUCCESS		C_GREEN "[Success]" C_RESET " "
# define ERROR			C_RED "[Error]" C_RESET " "

# define ERR_FILE_EXIST	"File exists." ENDL
# define ERR_FILE_NO	"No such file or directory." ENDL
# define ERR_FILE_RIGHT	"Permission denied." ENDL
# define ERR_FILE_DIR	"Is a directory." ENDL
# define ERR_FILE_NODIR	"Not a directory." ENDL
# define ERR_FILE_LOOP	"Symbolic link loop detected." ENDL
# define ERR_FILE_ERR	"Unexpected error." ENDL

# define ERR_F_EXIST	"%s: " ERR_FILE_EXIST
# define ERR_F_NO		"%s: " ERR_FILE_NO
# define ERR_F_RIGHT	"%s: " ERR_FILE_RIGHT
# define ERR_F_DIR		"%s: " ERR_FILE_DIR
# define ERR_F_NODIR	"%s: " ERR_FILE_NODIR
# define ERR_F_LOOP		"%s: " ERR_FILE_LOOP
# define ERR_F_ERR		"%s: " ERR_FILE_ERR

#endif
