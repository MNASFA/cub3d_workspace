NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra  -Iinclude -I$(MLX_DIR) -Ofast -fsanitize=address -g3
SRC_DIR = src
MLX_DIR = minilibx
HEADER = cub3d.h raycasting/raycasting.h
HEADER_BONUS = bonus/cub3d_bonus.h bonus/raycasting/raycasting_bonus.h

MLX = $(MLX_DIR)/libmlx.a

SRCS = src/main.c src/parsing/parse_file.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c src/init.c \
		src/parsing/parse_colors.c src/parsing/parse_map.c src/parsing/parse_textures.c src/parsing/read_all_lines.c src/parsing/validation.c \
		spliiit.c utils.c \
		src/rendring/render_minimap.c \
		src/rendring/init_mlx.c src/rendring/render_map.c src/rendring/hooks.c raycasting/raycasting.c raycasting/weapon.c  raycasting/sun.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LINK_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LINK_FLAGS) -o $(NAME)

bonus: $(NAME)_bonus

$(NAME)_bonus: $(OBJS_BONUS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LINK_FLAGS) -o $(NAME)_bonus

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	# $(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME)_bonus

re: fclean all