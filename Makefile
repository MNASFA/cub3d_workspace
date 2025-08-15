NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(MLX_DIR) -Ofast -fsanitize=address -g3
SRC_DIR = src
MLX_DIR = minilibx
HEADER = cub3d.h raycasting/raycasting.h

MLX = $(MLX_DIR)/libmlx.a

SRCS = src/main.c src/parsing/parse_file.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c src/init.c \
		src/parsing/parse_colors.c src/parsing/parse_map.c src/parsing/parse_textures.c src/parsing/read_all_lines.c src/parsing/validation.c \
		spliiit.c utils.c \
		src/rendring/init_mlx.c src/rendring/render_map.c src/rendring/hooks.c raycasting/raycasting.c
OBJS = $(SRCS:.c=.o)

LINK_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LINK_FLAGS) -o $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	# $(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
