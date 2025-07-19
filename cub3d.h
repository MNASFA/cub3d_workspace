/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:08:39 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/07/15 14:13:19 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
	
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>
# include <string.h>

/// for get next line
# define BUFFER_SIZE 42


//////////////////////////////////   START COLORS   ///////////////////////////

# define BLACK		0X000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define MAGENTA	0xFF00FF
# define CYAN		0x00FFFF

# define MAX_COLOR_VALUE 255
# define MIN_COLOR_VALUE 0

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define WIN_TITLE	"cub3D"

/* Key codes (adjust based on your system) */
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

/* Map characters */
# define WALL '1'
# define EMPTY '0'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

/* Movement speed */
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05

//////////////////////////////////   END COLORS   ///////////////////////////

typedef struct  s_texture
{
	void	*img;
	char	*add;
	char	*path;
	int		bits_per_pexel;
	int		line_height;
	int		endian;
	int		width;
	int		height;
}	t_texture;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_count;
}	t_map;

typedef	struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*add;
	int		bits_per_pixel;
	int 	line_length;
	int		endian;

	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	
	int		floor_color;
	int		ceiling_color;

	t_map		map;
	t_player	player;

	// flags
	int no_parsed;
	int so_parsed;
	int we_parsed;
	int ea_parsed;
	int f_parsed;
	int c_parsed;
}	t_game;

///////////////// Init ///////////////////////

void init_game(t_game *game);

///////////////// Get Next Line ///////////////////////

char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strdup_gnl(const char *s1);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen_gnl(const char *s);
char	*get_next_line(int fd);

///////////////// Utils ///////////////////////

char	*ft_strdup(const char *str);
int		ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *str, int ch, size_t n);
int		ft_atoi(const char *str);
char	**ft_split(char *s, char c);
void	free_split(char **arr);
char	*ft_strchr(const char *s, int c);
void	print_error(const char *message);
int		is_empty_line(char *line);
int		is_color_line(char *line);
int		is_texture_line(char *line);


///////////////// Parse files ///////////////////////

int		parse_cub_file(char *filename, t_game *game);
int		parse_map(char **lines, int start, t_game *game);
int		validate_map(t_game *game);
void	free_lines(char **lines);
char	**read_all_lines(int fd, int *line_count);
int		parse_texture_line(char *line, t_game *game);
int		parse_color_line(char *line, t_game *game);

#endif