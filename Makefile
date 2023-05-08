# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 13:03:29 by jyao              #+#    #+#              #
#    Updated: 2023/05/08 19:05:25 by jyao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile for MiniRT -*-

#DECLARE DEFINE PROJECT FILE NAME
NAME 				=	minirt

#DECLARE DEFINE COMPILATION RULES
CC 					=	gcc
CFLAGS 				=	-Wall -Wextra -Werror

#DECLARE DEFINE INCLUDE DIRECTORIES
INCLUDES 			=	-I$(HEADERS_FOLDER) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)
LIBRARIES_FLAGS 	=	-L$(LIBFT_FOLDER) -L$(MINILIBX_FOLDER) -lmlx -lm -lft -lXext -lX11 -lz
LIBRARY_FILES		=	$(LIBFT_FILE)	$(MINILIBX_FILE)

#DECLARE DEFINE ALL LIB PATHS
LIBS_FOLDER 		=	./libs/

LIBFT_FOLDER 		=	$(LIBS_FOLDER)libft/
LIBFT_FILE 			=	$(LIBFT_FOLDER)libft.a
LIBFT_HEADERS 		=	$(LIBFT_FOLDER)includes/

MINILIBX_FOLDER 	=	$(LIBS_FOLDER)minilibx-linux/
MINILIBX_FILE 		=	$(MINILIBX_FOLDER)libmlx.a
MINILIBX_HEADERS	=	$(MINILIBX_FOLDER)

#DECLARE DEFINE ALL INTERNAL HEADERS
HEADERS_FOLDER 		=	./includes/
HEADERS_LIST 		=	minirt.h
HEADERS 			=	$(addprefix $(HEADERS_FOLDER), $(HEADERS_LIST))

#DECLARE DEFINE ALL SRCS FOLDER PATHS
SRCS_FOLDER			:=	./srcs/
ERROR_FOLDER		=	error/
EXIT_FOLDER			=	exit/
FLOAT_FOLDER		=	float/
PARSE_FOLDER		=	parse/
RENDER_FOLDER		=	render/
TEST_FOLDER			=	test/
TUPLE_FOLDER		=	tuple/

SRCS_LIST			=	main	\
						$(ERROR_FOLDER)rt_error	\
						$(EXIT_FOLDER)rt_exit	$(EXIT_FOLDER)rt_free	\
						$(FLOAT_FOLDER)rt_float	\
						$(PARSE_FOLDER)rt_parse	$(PARSE_FOLDER)rt_gnl	$(PARSE_FOLDER)rt_parse_load	$(PARSE_FOLDER)rt_parse_check	\
						$(RENDER_FOLDER)rt_render	\
						$(TEST_FOLDER)rt_tuple_test	$(TEST_FOLDER)rt_file_test	\
						$(TUPLE_FOLDER)rt_tuple_make	$(TUPLE_FOLDER)rt_tuple_maths	$(TUPLE_FOLDER)rt_vector_maths	\

SRCS = $(addprefix $(SRCS_FOLDER), $(addsuffix .c, $(SRCS_LIST)))

#DECLARE DEFINE ALL OBJS FOLDER PATHS
OBJS_FOLDER := ./objs/
OBJS = $(addprefix $(OBJS_FOLDER), $(addsuffix .o, $(SRCS_LIST)))

#DEFINE RULE FOR COMPILING OBJS
$(OBJS_FOLDER)%.o : $(SRCS_FOLDER)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

## apt install xorg libxext-dev zlib1g-dev libbsd-dev
## this is to install the required libraries for linux environment

#DEFINE RULE FOR COMPILING NAME
$(NAME): $(LIBRARY_FILES) $(OBJS_FOLDER) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARIES_FLAGS) -o $@

$(LIBRARY_FILES):
	make -C $(LIBFT_FOLDER)
	make -C $(MINILIBX_FOLDER)

$(OBJS_FOLDER):
	mkdir $(OBJS_FOLDER)
	mkdir $(OBJS_FOLDER)$(ERROR_FOLDER)
	mkdir $(OBJS_FOLDER)$(EXIT_FOLDER)
	mkdir $(OBJS_FOLDER)$(FLOAT_FOLDER)
	mkdir $(OBJS_FOLDER)$(PARSE_FOLDER)
	mkdir $(OBJS_FOLDER)$(RENDER_FOLDER)
	mkdir $(OBJS_FOLDER)$(TEST_FOLDER)
	mkdir $(OBJS_FOLDER)$(TUPLE_FOLDER)

clean:
	make -C $(LIBFT_FOLDER) clean
	make -C $(MINILIBX_FOLDER) clean
	rm -rf $(OBJS_FOLDER)

fclean: clean
	make -C $(LIBFT_FOLDER) fclean
	make -C $(MINILIBX_FOLDER) clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
