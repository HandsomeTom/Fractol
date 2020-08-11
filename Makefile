NAME = fractol

SOURCES =	main.c					\
			ft_exit.c				\
			normalize.c				\
			store_images.c			\
			mouse.c					\
			keyboard.c				\
			satan.c

OBJECTS = $(subst .c,.o,$(SOURCES))

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra
#Use this on school computer
#LINKS = -I libft -L libft -l ft -I /usr/local/include -L /usr/local/lib \
		-l mlx -l ft -framework OpenGL -framework Appkit
LINKS = -I libft -L libft -l ft -l ft -I /usr/X11/include -g -L /usr/X11/lib -framework OpenGL -framework AppKit -l mlx
MSG = \033[38;5;214m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)
	@echo "$(MSG)Done!$(END)"

$(OBJECTS): $(LIBFT) $(SOURCES)
	@echo "$(MSG)Compiling...$(END)"

$(LIBFT):
	@make -C libft

clean:
	@make -C libft clean
	@rm -f $(OBJECTS)
	@echo "$(MSG)Objects removed!$(END)"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "$(MSG)Targets removed!$(END)"

re: fclean all
