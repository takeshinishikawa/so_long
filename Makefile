NAME = so_long

CFLAGS = -Wall -Wextra -Werror -g -ggdb3

SRC = so_long.c $(addprefix src/, check_map.c get_map.c create_map.c get_fd.c \
	get_first_line.c check_wall_line.c get_other_lines.c check_mid_line.c \
	check_line_len.c check_last_line.c check_min_config.c parse_map.c \
	init_game_struct.c load_img.c init_img.c game_default.c print_map.c \
	print_img.c draw_image.c mlx_draw_pixel.c mlx_get_pixel.c mlx_rgb_to_int.c \
	check_key.c move.c validate_move.c find_p_position.c min_window.c \
	close_game.c erase_images.c refresh_p_img.c refresh_map.c)

INC = ./inc/so_long.h
MLXFLAGS = -Imlx -lX11 -lXext
LIBFT = ./libs/libft/libft.a
MLX = ./libs/mlx/libmlx_Linux.a

OBJ =	$(SRC:.c=.o)
RM =	rm -f


all:	 $(SRC) $(LIBFT) $(MLX)
	gcc $(CFLAGS) $(SRC) $(LIBFT) $(MLX) $(MLXFLAGS) $(INC) -o $(NAME)

$(LIBFT):
	make -C libs/libft

clean:
	$(RM) $(OBJ)
	make fclean -C libs/libft

fclean: clean
		$(RM) $(NAME)

re: 	fclean all

run:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -v ./$(NAME) map/map.ber
