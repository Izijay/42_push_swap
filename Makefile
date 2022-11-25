# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 12:46:21 by mdupuis           #+#    #+#              #
#    Updated: 2021/12/21 15:42:35 by mdupuis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD = \033[1m
BLUE = \033[0;34m
CYAN = \x1b[36m
GREEN = \x1b[32m
ORANGE = \033[93m
PURPLE = \033[0;95m
RED = \033[0;91m
END = \033[0m

NAME	        =		push_swap

SRCS            =		srcs/algo_five.c\
						srcs/algo.c\
						srcs/is_sort.c\
						srcs/list_utils.c\
						srcs/main.c\
						srcs/operations.c\
						srcs/parsing.c\
						srcs/radix_sort.c\
						srcs/split_args.c

INCLUDES_DIR     =       includes/

LIB_DIR         =       libft//

LIBFT           =       libft/libft.a

CC              =       gcc

OBJS            =       ${SRCS:.c=.o}

RM          =       rm -rf

FLAGS       =       -Wall -Wextra -Werror

.c.o:
					@${CC} ${FLAGS} -I${INCLUDES_DIR} -c $< -o ${<:.c=.o}
					@echo "\t\t${BOLD}${GREEN} [[ LOADED ]]${END} ${PURPLE}${<:.s=.o}${END}"

all:			${NAME}

${NAME}:		${OBJS}
						@make -C ${LIB_DIR} 2>/dev/null
						@make -C ${LIB_DIR} bonus 2>/dev/null
						@${CC} ${FLAGS} -I${INCLUDES_DIR} -o ${NAME} ${OBJS} ${LIBFT}
						@echo "\t\t${BOLD}${CYAN} libft.a${END}   ${GREEN}[ OK ]${END}"
						@echo "\t\t${BOLD}${CYAN} push_swap${END} ${GREEN}[ OK ]${END}"

clean:
						@make -C ${LIB_DIR} clean
						@${RM} ${OBJS} ${OBJS_B}
						@echo "\n${BOLD}${RED}\t\t *.o files deleted.${END}"

fclean:		clean
						@make -C ${LIB_DIR} fclean
						@${RM} ${NAME} ${NAME_B}
						@echo "\t\t${BOLD}${RED}Program libft deleted.${END}"
						@echo "\t\t${BOLD}${RED}Program push_swap deleted.${END}\n"

re:		fclean all

.PHONY:           all     clean   fclean  re
