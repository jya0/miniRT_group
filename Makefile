# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooutabac <ooutabac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 13:03:29 by jyao              #+#    #+#              #
#    Updated: 2023/07/13 16:15:51 by ooutabac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile for MiniRT -*-

#DECLARE DEFINE PROJECT FILE NAME
NAME 				=	minirt

#DECLARE DEFINE COMPILATION RULES
CC 					=	gcc
CFLAGS 				=	-Wall -Wextra -Werror -g3 -fsanitize=address

#DECLARE DEFINE INCLUDE DIRECTORIES
INCLUDES 			=	-I$(HEADERS_FOLDER) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS)
LIBRARIES_FLAGS 	=	-L$(LIBFT_FOLDER) -lft $(MINILIBX_FLAGS)
LIBRARY_FILES		=	$(LIBFT_FILE)	$(MINILIBX_FILE)

#DECLARE DEFINE ALL LIB PATHS
LIBS_FOLDER 		=	./libs/

LIBFT_FOLDER 		=	$(LIBS_FOLDER)libft/
LIBFT_FILE 			=	$(LIBFT_FOLDER)libft.a
LIBFT_HEADERS 		=	$(LIBFT_FOLDER)includes/

#a better way than the one below
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
MINILIBX_FOLDER 	=	$(LIBS_FOLDER)minilibx/
MINILIBX_FILE 		=	$(MINILIBX_FOLDER)libmlx.a
MINILIBX_HEADERS	=	$(MINILIBX_FOLDER)osx/src
MINILIBX_FLAGS		=	-L$(MINILIBX_FOLDER) -lmlx -framework OpenGL -framework AppKit
else
MINILIBX_FOLDER 	=	$(LIBS_FOLDER)minilibx/
MINILIBX_FILE 		=	$(MINILIBX_FOLDER)libmlx.a
MINILIBX_HEADERS	=	$(MINILIBX_FOLDER)linux/src
MINILIBX_FLAGS		=	-L$(MINILIBX_FOLDER) -lmlx -lXext -lX11 -lm -lz
endif

# this is for linux version
# MINILIBX_FOLDER 	=	$(LIBS_FOLDER)minilibx-linux/
# MINILIBX_FILE 		=	$(MINILIBX_FOLDER)libmlx.a
# MINILIBX_HEADERS	=	$(MINILIBX_FOLDER)/linux/src
# MINILIBX_FLAGS		=	-L$(MINILIBX_FOLDER) -lmlx -lXext -lX11 -lm -lz

# this is for macos version
# MINILIBX_FOLDER 	=	$(LIBS_FOLDER)minilibx/
# MINILIBX_FILE 		=	$(MINILIBX_FOLDER)libmlx.a
# MINILIBX_HEADERS	=	$(MINILIBX_FOLDER)/osx/src
# MINILIBX_FLAGS		=	-L$(MINILIBX_FOLDER) -lmlx -framework OpenGL -framework AppKit

#DECLARE DEFINE ALL INTERNAL HEADERS
HEADERS_FOLDER 		=	./includes/
HEADERS_LIST 		=	minirt.h
HEADERS 			=	$(addprefix $(HEADERS_FOLDER), $(HEADERS_LIST))

#DECLARE DEFINE ALL SRCS FOLDER PATHS
SRCS_FOLDER			:=	./srcs/
COLOR_FOLDER		=	color/
ERROR_FOLDER		=	error/
EXIT_FOLDER			=	exit/
FLOAT_FOLDER		=	float/
GEOMETRY_FOLDER		=	geometry/
MATRIX_FOLDER		=	matrix/
PARSE_FOLDER		=	parse/
RAY_FOLDER			=	ray/
RENDER_FOLDER		=	render/
SCENE_FOLDER		=	scene/
TEST_FOLDER			=	test/
TUPLE_FOLDER		=	tuple/

SRCS_LIST			=	main	main_tests				\
						$(COLOR_FOLDER)rt_color			$(COLOR_FOLDER)rt_color_math	\
						$(ERROR_FOLDER)rt_error			\
						$(EXIT_FOLDER)rt_exit			$(EXIT_FOLDER)rt_free			\
						$(FLOAT_FOLDER)rt_float			$(FLOAT_FOLDER)rt_float_maths	\
						$(GEOMETRY_FOLDER)rt_shape		$(GEOMETRY_FOLDER)rt_sphere		$(GEOMETRY_FOLDER)rt_shape_transform	\
						$(MATRIX_FOLDER)rt_matrix		$(MATRIX_FOLDER)rt_matrix_get	$(MATRIX_FOLDER)rt_matrix_times			\
						$(MATRIX_FOLDER)rt_matrix_transpose								$(MATRIX_FOLDER)rt_matrix_clone			\
						$(MATRIX_FOLDER)rt_matrix_determinant							$(MATRIX_FOLDER)rt_matrix_submatrix		\
						$(MATRIX_FOLDER)rt_matrix_minor									$(MATRIX_FOLDER)rt_matrix_cofactor		\
						$(MATRIX_FOLDER)rt_matrix_inverse								$(MATRIX_FOLDER)rt_matrix_translate		\
						$(MATRIX_FOLDER)rt_matrix_tuple									$(MATRIX_FOLDER)rt_matrix_scale			\
						$(MATRIX_FOLDER)rt_matrix_rotate								$(MATRIX_FOLDER)rt_matrix_sheer			\
						$(PARSE_FOLDER)rt_parse			$(PARSE_FOLDER)rt_gnl			$(PARSE_FOLDER)rt_atoi					\
						$(PARSE_FOLDER)rt_parse_load	$(PARSE_FOLDER)rt_parse_and_check										\
						$(PARSE_FOLDER)rt_parse_element_utils							\
						$(PARSE_FOLDER)rt_parse_element_set_1							$(PARSE_FOLDER)rt_parse_element_set_2	\
						$(PARSE_FOLDER)rt_check_range	$(PARSE_FOLDER)rt_split			\
						$(RAY_FOLDER)rt_ray				$(RAY_FOLDER)rt_ray_maths		$(RAY_FOLDER)rt_ray_intersect			\
						$(RAY_FOLDER)rt_ray_intersect_sphere							$(RAY_FOLDER)rt_intersect				\
						$(RAY_FOLDER)rt_intersect_list	$(RAY_FOLDER)rt_ray_transform	$(RAY_FOLDER)rt_ray_normal				\
						$(RAY_FOLDER)rt_ray_normal_sphere								$(RAY_FOLDER)rt_ray_reflect				\
						$(RAY_FOLDER)rt_ray_intersect_plane								$(RAY_FOLDER)rt_ray_normal_plane		\
						$(RENDER_FOLDER)rt_render		$(RENDER_FOLDER)rt_img			$(RENDER_FOLDER)rt_lighting				\
						$(SCENE_FOLDER)rt_scene			$(SCENE_FOLDER)rt_scene_obj		$(SCENE_FOLDER)rt_scene_load			\
						$(SCENE_FOLDER)rt_camera		$(SCENE_FOLDER)rt_scene_intersect							\
						$(SCENE_FOLDER)rt_scene_load_set_1								\
						$(TEST_FOLDER)rt_tuple_test		$(TEST_FOLDER)rt_file_test		$(TEST_FOLDER)rt_matrix_test			\
						$(TEST_FOLDER)rt_intersect_test	\
						$(TUPLE_FOLDER)rt_tuple			$(TUPLE_FOLDER)rt_tuple_maths	$(TUPLE_FOLDER)rt_vector_maths			\

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
	mkdir $(OBJS_FOLDER)$(COLOR_FOLDER)
	mkdir $(OBJS_FOLDER)$(ERROR_FOLDER)
	mkdir $(OBJS_FOLDER)$(EXIT_FOLDER)
	mkdir $(OBJS_FOLDER)$(FLOAT_FOLDER)
	mkdir $(OBJS_FOLDER)$(GEOMETRY_FOLDER)
	mkdir $(OBJS_FOLDER)$(MATRIX_FOLDER)
	mkdir $(OBJS_FOLDER)$(PARSE_FOLDER)
	mkdir $(OBJS_FOLDER)$(RAY_FOLDER)
	mkdir $(OBJS_FOLDER)$(RENDER_FOLDER)
	mkdir $(OBJS_FOLDER)$(SCENE_FOLDER)
	mkdir $(OBJS_FOLDER)$(TEST_FOLDER)
	mkdir $(OBJS_FOLDER)$(TUPLE_FOLDER)

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
