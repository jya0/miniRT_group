# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyao <jyao@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 13:01:55 by fkhan             #+#    #+#              #
#    Updated: 2023/06/03 14:52:43 by jyao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= libft.a
CC 					= gcc
REMOVE_THIS_FLAG	= -Wno-unused-result
OPTIMISE_FLAGS		:=	-Ofast -march=native
FLAGS 				= -Wall -Werror -Wextra $(OPTIMISE_FLAGS) $(REMOVE_THIS_FLAG)
LIB					= ar -rcs
INCLUDES 			= -I$(HEADERS_DIRECTORY)

HEADERS_DIRECTORY 	= ./includes/
HEADERS_LIST 		= libft.h
HEADERS 			= $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY 	= ./sources/
SOURCES_LIST 		= ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
						ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
						ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
						ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
						ft_memcmp.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c \
						ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
						ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
						ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
						ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
						ft_lstmap.c
SOURCES 			= $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY 	= ./objects/
OBJECTS_LIST 		= $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS				= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(LIB) $(NAME) $(OBJECTS)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re