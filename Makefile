NAME	= fdf
SRC		= main.c 
OBJ		= $(SRC:.c=.o)


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBXINCLUDES = -I /usr/local/include
XFLAGS = -framework OpenGL -framework AppKit
LIBX = -L /usr/local/lib/ -lmlx

LIBFLAGS = -I libft/includes
LIBFT	= -L libft -lft

GREEN = \033[0;32m
RED = \033[0;31m
WHITE = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) header.h
	$(CC) $(CFLAGS) $(LIBXINCLUDES) $(LIBFLAGS) $(LIBX) $(XFLAGS) $(LIBFT) -o $@ $(SRC) && echo "$(GREEN)$@ compiled to date$(WHITE)"

$(LIBFT) :
	$(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(LIBXINCLUDES) $(LIBFLAGS) $(LIBX) $(XFLAGS) $(LIBFT) -o $@ $^ && echo "$(GREEN)$@$(WHITE)"

clean:
	$(MAKE) -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

//.SILENT: all $(NAME) clean fclean re

run:
	$(CC) $(CCFLAGS) $(MINILIBXFLAGS) $(LIBFLAGS) $(MINILIBX) $(LIBFT) main.c  -o $(NAME) && ./$(NAME)
