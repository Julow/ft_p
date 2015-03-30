# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/26 15:19:19 by jaguillo          #+#    #+#              #
#    Updated: 2015/03/30 19:36:05 by jaguillo         ###   ########.fr        #
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

_clean:
	@make -f client.Makefile _clean
	@make -f server.Makefile _clean

fclean:
	@make -f client.Makefile fclean
	@make -f server.Makefile fclean

_fclean:
	@make -f client.Makefile _fclean
	@make -f server.Makefile _fclean

debug:
	@make -f client.Makefile debug
	@make -f server.Makefile debug

rebug:
	@make -f client.Makefile rebug
	@make -f server.Makefile rebug

_rebug:
	@make -f client.Makefile _rebug
	@make -f server.Makefile _rebug

re: fclean all

_re:
	@make -f client.Makefile _re
	@make -f server.Makefile _re

.PHONY: all client server clean _clean fclean _fclean debug rebug _rebug re _re
