/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 18:08:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/03/27 19:38:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# include <libft.h>

/*
** ========================================================================== **
** ft_p
*/

/*
** ========================================================================== **
** Protocol
** ---
** Command:
**  c:			CMD <arg ...><EOF>
**  s (ok):		0\n<data><EOF>
**  s (ko):		1\n<error msg><EOF>
** -
** Command list:
**  LS <args ...>
**  CD <path>
**  PWD
**  MKDIR <name>
** ---
** get:
**  c:			GET <file name><EOF>
**  s (ok):		0\n<file size><EOF><data>
**  s (ko):		1\n<error msg><EOF>
** ---
** put:
**  c:			PUT <file name><EOF>
**  s (ok):		0<EOF>
**  s (ko):		1\n<error msg><EOF>
**  c:			UPLOAD <file size><EOF><data>
**  s (ok):		0<EOF>
**  s (ko):		1\n<error msg><EOF>
** ---
*/

#endif
