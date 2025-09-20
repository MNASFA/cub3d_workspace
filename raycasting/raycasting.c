/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:23:08 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/09/20 17:52:22 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_background(t_game *game)
{
	int		x;
	int		y;
	char	*pixel;
	int		color;

	x = 0;
	while (x < game->win_width)
	{
		y = 0;
		while (y < game->win_heigth)
		{
			pixel = game->add + (y * game->line_length + \
				x * (game->bits_per_pixel / 8));
			if (y < game->win_heigth / 2)
				color = game->ceiling_color;
			else
				color = game->floor_color;
			*(unsigned int *)pixel = color;
			y++;
		}
		x++;
	}
}

int	get_wall_direction(t_ray *ray, int side)
{
	if (side == 0)
	{
		if (ray->dir_x > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray->dir_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

static void	load_texture(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path,
			&texture->width, &texture->height);
	if (!texture->img)
	{
		printf("error in opening texture\n");
		exit(3);
	}
	texture->add = mlx_get_data_addr(texture->img,
			&texture->bits_per_pexel, &texture->line_height, &texture->endian);
}

void	setup_textures(t_game *game)
{
	load_texture(game, &game->east, "textures/east_wall.xpm");
	load_texture(game, &game->north, "textures/north_wall.xpm");
	load_texture(game, &game->south, "textures/south_wall.xpm");
	load_texture(game, &game->west, "textures/west_wall.xpm");
}

void	cast_rays(t_game *game, int x)
{
	t_ray		ray;
	t_dda		dda;
	t_wall_calc	calc;
	t_wall_data	wall;
	int			text;

	calculate_ray_direction(game, x, &ray);
	perform_dda(game, &ray, &dda);
	calculate_wall_dimensions(game, &ray, &dda, &calc);
	text = get_wall_direction(&ray, dda.side);
	wall.game = game;
	wall.x = x;
	wall.start = calc.draw_start;
	wall.end = calc.draw_end;
	wall.texture_x = calc.texture_x;
	wall.real_line_height = calc.line_height;
	draw_wall_line_text(&wall, text);
}
