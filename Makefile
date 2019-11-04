# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 10:38:35 by mbenhass          #+#    #+#              #
#    Updated: 2019/11/04 14:11:01 by mbenhass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

LIBFT = libft/libft.a

CC = gcc
CGLAGS := -Wall -Wextra -Werror -Ofast -march=native
LCFLAGS := -L./minilibx_macos -lmlx -framework OpenGL -framework Appkit


INCLUDES := -I./minilibx_macos -I./includes -I./libft/includes

SRCS := main.c \
		ft_parse.c \
		ft_map.c \
		ft_process_line.c \
		ft_hook_keys.c

SRCSP := $(addprefix ./srcs/,  $(SRCS))
#OBJS = $(SRCS:.c=.o)
OBJS = $(SRCSP:.c=.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS) ./includes/fdf.h ./includes/key_codes_macos.h
	$(CC) $(CFLAGS) $(INCLUDES) $(LCFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT) :
	$(MAKE) -C libft/
	$(MAKE) -C minilibx_macos/

%.o : %.c
	$(CC) $(CFLAGS)  $(INCLUDES) -c -o $@ $<

clean :
	$(MAKE) -C libft/ clean
	$(MAKE) -C minilibx_macos/ clean
	/bin/rm -rf $(OBJSP) $(OBJS)

fclean : clean
	$(MAKE) -C libft/ fclean
	/bin/rm -rf $(NAME)

re : fclean all

.SILENT : all $(NAME) $(LIBFT) clean fclean  
