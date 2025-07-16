NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -I$(MLX_DIR)
SRC_DIR = src
MLX_DIR = minilibx
HEADER = cub3D.h

# MLX = $(MLX_DIR)/libmlx.a

SRCS = src/main.c src/parsing/parse_file.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
OBJS = $(SRCS:.c=.o)

LINK_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) #$(MLX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# $(MLX):
# 	$(MAKE) -C $(MLX_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	# $(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all
