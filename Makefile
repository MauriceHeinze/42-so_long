# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:53:26 by aparedes          #+#    #+#              #
#    Updated: 2022/07/12 19:41:25 by mheinze          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
SRCS		=	so_long.c							\
				./GNL/get_next_line.c				\
				./GNL/get_next_line_utils.c			\
				./map_helpers/check_map.c			\
				./map_helpers/move_on_map_helper.c	\
				./map_helpers/movement_helper.c		\
				./map_helpers/movement.c			\
				./graphics/display_map.c			\
				./graphics/display_map_helpers.c	\
				./graphics/hooks.c					\
				./graphics/image.c					\
				./graphics/window.c					\
				./misc/error_handler.c				\
				./misc/helpers.c					\

OBJ			=	$(SRCS:.c=.o)
RM 			= rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./mlx/
	$(CC) -fsanitize=address -o $@ -Imlx $^ -g -Lmlx -lmlx -lm -framework OpenGL -framework AppKit

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) ./*.o
			$(RM) ./*/*.o
			$(RM) ./*/*.h.gch
			$(RM) *.out

fclean:		clean
			$(RM) ./*/*.a
			rm -f $(NAME)

re:			fclean all

.PHONY:		all test clean fclean re