NAME	= fdf
SRC		= dot.c main.c
OBJ		= $(SRC:.c=.o)


CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CPPFLAGS = -Iincludes

LIBXINCLUDES = -I /usr/local/include
XFLAGS = -framework OpenGL -framework AppKit
LIBX = -L /usr/local/lib/ -lmlx

LIBFLAGS = -I libft/includes
LIBFT	= -L libft -lft


GREEN = \033[0;32m
RED = \033[0;31m
WHITE = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBXINCLUDES) $(LIBFLAGS) $(LIBX) $(XFLAGS) $(LIBFT) -o $@ $(SRC) && echo "$(GREEN)$@ compiled to date$(WHITE)"

$(LIBFT) :
	$(MAKE) -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LIBFLAGS)  -o $@ -c $^ && echo "$(GREEN)$@$(WHITE)"

clean:
	$(MAKE) -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

//.SILENT: all $(NAME) clean fclean re

run: $(NAME)
	./$(NAME) run
