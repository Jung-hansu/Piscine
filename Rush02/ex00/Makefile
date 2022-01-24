# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 22:10:02 by sueshin           #+#    #+#              #
#    Updated: 2022/01/23 22:11:34 by sueshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
SRCS = rush01_1.c rush01_2.c rush01_3.c rush01_4.c
OBJS = ${SRC:.c=.o}
FLAGS = -Wall -Werror -Wextra
all: ${NAME}
${NAME}: ${OBJS}
	cc -o ${NAME} ${SRCS} -Iincludes ${FLAGS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean
