/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 18:08:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/04/03 18:26:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# include <libft.h>

/*
** ========================================================================== **
** ft_p
*/

typedef struct	s_socket
{
	int				fd;
	t_buff			in;
	t_out			out;
}				t_socket;

# define SIN(c)		(&((c)->sock.in))
# define SOUT(c)	(&((c)->sock.out))

# define BUFF_SIZE	512

# define VOID		((void)0)

typedef struct stat		t_stat;

/*
** ========================================================================== **
** Protocol
** ---
** Command:
**  c:			CMD <arg ...><EOF>
**  s (ok):		<data><EOF>0<EOF>
**  s (ko):		<data><EOF>1<EOF>
** -
** Command list:
**  LS <args ...>
**  CD <path>
**  PWD
**  MKDIR <name>
** ---
** get:
**  c:			GET <file name><EOF>
**  s (ok):		<info><EOF>0<EOF><name_len>\n<name>\n<size><EOF>
**  s (ko):		<error msg><EOF>1<EOF>
**  c:			<1 or 0><EOF>
**  s (1):		<data><EOF>0<EOF>
**  s (0):		<EOF>1<EOF>
** ---
** put:
**  c:			PUT <file name><EOF>
**  s (ko):		<error msg><EOF>1<EOF>
**  s (ovwr):	<msg><EOF>2<EOF>
**  c (ovwr):	<1 or 0><EOF>
**  s (ok):		<EOF>0<EOF>
**  s (ko):		<error msg><EOF>1<EOF>
**  c:			<file size><EOF><data>
**  s (ok):		0<EOF>
**  s (ko):		1\n<error msg><EOF>
** ---
*/

#endif
