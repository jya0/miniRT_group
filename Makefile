# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 13:03:29 by jyao              #+#    #+#              #
#    Updated: 2023/01/31 14:08:29 by jyao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile for MiniRT -*-

#DECLARE DEFINE PROJECT FILE NAME
NAME 				= minirt

#DECLARE DEFINE COMPILATION RULES
CC 					= gcc
CFLAGS 				= -Wall -Wextra -Werror

#DECLARE DEFINE INCLUDE DIRECTORIES
INCLUDES 			= -I$(HEADERS_FOLDER) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)
LIBRARIES 			= -lmlx -lm -lft -L$(LIBFT_FOLDER) -L$(MINILIBX_FOLDER)

#DECLARE DEFINE ALL LIB PATHS
LIBS_FOLDER 		= ./libs/

LIBFT_FOLDER 		= $(LIBS_FOLDER)libft/
LIBFT_FILE 			= $(LIBFT_FOLDER)libft.a
LIBFT_HEADERS 		= $(LIBFT_FOLDER)includes/

MINILIBX_FOLDER 	= $(LIBS_FOLDER)minilibx-linux/
MINILIBX_FILE 		= $(MINILIBX_FOLDER)libmlx.a
MINILIBX_HEADERS	= $(MINILIBX_FOLDER)

#DECLARE DEFINE ALL INTERNAL HEADERS
HEADERS_FOLDER 		= ./includes/
HEADERS_LIST 		= minirt.h
HEADERS 			= $(addprefix $(HEADERS_FOLDER), $(HEADERS_LIST))

#DECLARE DEFINE ALL SRCS FOLDER PATHS
SRCS_FOLDER := ./srcs
PARSE_FOLDER = $(SRCS_FOLDER)/parse
RAYTRACE_FOLDER = $(SRCS_FOLDER)/raytrace

SRCS_LIST = $(PARSE_FOLDER)/parse	\
			$(RAYTRACE_FOLDER)/raytrace	\

SRCS = $(addprefix $(SRCS_FOLDER), $(addsuffix .c, $(SRCS_LIST)))

#DECLARE DEFINE ALL OBJS FOLDER PATHS
OBJS_FOLDER := ./objs
OBJS = $(addprefix $(OBJS_FOLDER), $(addsuffix .o, $(SRCS_LIST)))

#DEFINE RULE FOR COMPILING OBJS
$(OBJS_FOLDER)%.o : $(SRCS_FOLDER)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

#DEFINE RULE FOR COMPILING NAME

$(NAME): $(OBJS_FOLDER) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(LIBRARIES)

$(OBJS_FOLDER):
	mkdir -p $(OBJS_FOLDER)
