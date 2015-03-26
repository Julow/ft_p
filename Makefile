# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/26 15:19:19 by jaguillo          #+#    #+#              #
#    Updated: 2015/03/26 15:28:31 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: client server

client:
	@make -f client.Makefile

server:
	@make -f server.Makefile

clean:
	@make -f client.Makefile clean
	@make -f server.Makefile clean

fclean:
	@make -f client.Makefile fclean
	@make -f server.Makefile fclean

re: fclean all
