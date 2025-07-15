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

/// for get next line
# define BUFFER_SIZE 42

typedef struct  s_texture
{
	void	*img;
	char	*add;
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
};


///////////////// Get Next Line ///////////////////////

char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strdup_gnl(const char *s1);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);
	
#endif