# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouali <iouali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 13:52:00 by iouali            #+#    #+#              #
#    Updated: 2022/01/19 19:46:29 by iouali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCFOLD		= src/

SRCS		= ${SRCFOLD}main.c \
				${SRCFOLD}init.c \
				${SRCFOLD}life.c \
				${SRCFOLD}utils.c \
				${SRCFOLD}debug.c \
				${SRCFOLD}clear.c

OBJS		= ${SRCS:.c=.o}

NAME		= philo

CC			= clang

CFLAGS		= -pthread -g3 -fsanitize=thread

RM			= rm -f

%.o: %.c
	${CC} ${CFLAGS} -Iincludes -c $< -o ${<:.c=.o}

${NAME}:		 ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -pthread -o ${NAME}

all:			${NAME}

clean:
	${RM} ${OBJS}

fclean:			clean
	${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re