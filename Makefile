NAME = cub3D

HEADER = cub3D.h

SRC =	./parser/check_links.c\
		./parser/color_data.c\
		./parser/color_utils.c\
		./parser/parser_init.c\
		./parser/parser_main.c\
		./parser/parser_map.c\
		./parser/parser_map_end.c\
		./parser/side_links.c\
		./parser/texture_data.c\
		./parser/utils_and_errors.c\
		./gnl/get_next_line.c\
		./gnl/get_next_line_utils.c\
		./graphics/main.c\
		./graphics/player_movement.c\
		./graphics/print_background.c\
		./graphics/raycasting.c\
		./graphics/prepare_to_print.c\
		./graphics/find_texture.c\
		./graphics/print3D.c\
		./graphics/utils.c\

OBJ = $(patsubst %.c, %.o, $(SRC))

CC = gcc

FLAGS = -Wall -Wextra -Werror

MLX_DIR = ./minilibx_macos/

LIBFT = Libft/libft.a

MLX = -lmlx  -L./minilibx_macos/ -framework OpenGL -framework AppKit

$(NAME):	$(OBJ)
	make -C ./Libft/
	$(CC) $(FLAGS) $(LIBFT) $(MLX) $(OBJ) -o $@

%.o : %.c	$(HEADER)
	$(CC)  -c $< -o $@

play:
	./cub3D ./maps/map2.cub

clean:
	@rm -f $(OBJ)
	@make -C ./Libft/ clean

fclean:
	@rm -f $(OBJ) $(NAME)
	@make -C ./Libft/ fclean

re: fclean all

.PHONY: clean fclean re all