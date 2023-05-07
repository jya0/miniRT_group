# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 13:03:29 by jyao              #+#    #+#              #
#    Updated: 2023/05/07 14:30:07 by jyao             ###   ########.fr        #
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
LIBRARIES_FLAGS 	=	-L$(LIBFT_FOLDER) -L$(MINILIBX_FOLDER) -lmlx -lm -lft
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
HEADERS_LIST 		=	minirt.h	rt_error.h	rt_float.h	rt_test.h	rt_tuple.h
HEADERS 			=	$(addprefix $(HEADERS_FOLDER), $(HEADERS_LIST))

#DECLARE DEFINE ALL SRCS FOLDER PATHS
SRCS_FOLDER			:=	./srcs
ERROR_FOLDER		=	$(SRCS_FOLDER)/error/
FLOAT_FOLDER		=	$(SRCS_FOLDER)/float/
PARSE_FOLDER		=	$(SRCS_FOLDER)/parse/
TEST_FOLDER			=	$(SRCS_FOLDER)/test/
TUPLE_FOLDER		=	$(SRCS_FOLDER)/tuple/

SRCS_LIST			=	$(ERROR_FOLDER)rt_error	\
						$(FLOAT_FOLDER)rt_float	\
						$(PARSE_FOLDER)rt_parse	\
						$(TEST_FOLDER)rt_test	\
						$(TUPLE_FOLDER)rt_tuple

SRCS = $(addprefix $(SRCS_FOLDER), $(addsuffix .c, $(SRCS_LIST)))

#DECLARE DEFINE ALL OBJS FOLDER PATHS
OBJS_FOLDER := ./objs
OBJS = $(addprefix $(OBJS_FOLDER), $(addsuffix .o, $(SRCS_LIST)))

#DEFINE RULE FOR COMPILING OBJS
$(OBJS_FOLDER)%.o : $(SRCS_FOLDER)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#DEFINE RULE FOR COMPILING NAME

$(NAME): $(LIBRARY_FILES) $(OBJS_FOLDER) $(OBJS)
	$(CC) $(CFLAGS) $(LIBRARIES_FLAGS) -o $@

$(LIBRARY_FILES):
	make -C $(LIBFT_FOLDER)
	make -C $(MINILIBX_FOLDER)

$(OBJS_FOLDER):
	mkdir $(OBJS_FOLDER)

clean:
	make -C $(LIBFT_FOLDER) clean
	make -C $(MINILIBX_FOLDER) clean
	rm -rf $(OBJS_FOLDER)

fclean: clean
	make -C $(LIBFT_FOLDER) fclean
	make -C $(MINILIBX_FOLDER) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
