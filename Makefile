NAME = a.out

CFLAGS = -Wall -Wextra -Werror -g -ggdb3

SRC = main_arg.c check_map.c

MLXFLAGS = -Imlx -lX11 -lXext
LIBFT = libs/libft/libft.a
MLX = libs/mlx/libmlx_Linux.a



OBJ =		$(SRC:.c=.o)
RM =	rm -f


all:	$(OBJ)

$(OBJ): $(SRC) $(LIBFT) $(MLX)
	gcc $(CFLAGS) $(SRC) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	make -C libs/libft

run:
	valgrind --leak-check=full ./$(NAME) map/invalidchar.ber

clean:
	$(RM) $(OBJ)
	make fclean -C libs/libft

fclean: clean
		$(RM) $(NAME)

re: 	fclean all