/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:51:16 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/20 20:17:30 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	draw_minimap_pixel(t_game *game, int screen_x,
	int screen_y, int color)
{
	int	pixel;

	if (screen_x >= MINIMAP_MARGIN && screen_x < MINIMAP_MARGIN + MINIMAP_SIZE
		&& screen_y >= MINIMAP_MARGIN
		&& screen_y < MINIMAP_MARGIN + MINIMAP_SIZE)
	{
		pixel = screen_y * game->line_length + screen_x
			* (game->bits_per_pixel / 8);
		*(unsigned int *)(game->add + pixel) = color;
	}
}

static void	draw_minimap_square(t_game *game, int map_x, int map_y, int color)
{
	t_square	square;

	init_square(&square, game, map_x, map_y);
	while (square.py < square.tile_size)
	{
		square.px = 0;
		while (square.px < square.tile_size)
		{
			draw_minimap_pixel(game, square.screen_x + square.px,
				square.screen_y + square.py, color);
			square.px++;
		}
		square.py++;
	}
}

static void	draw_minimap_player(t_game *game)
{
	int	py;
	int	px;
	int	player_size;
	int	center_x;
	int	center_y;

	player_size = 4;
	center_x = MINIMAP_MARGIN + MINIMAP_SIZE / 2;
	center_y = MINIMAP_MARGIN + MINIMAP_SIZE / 2;
	py = center_y - player_size / 2;
	while (py < center_y + player_size / 2)
	{
		px = center_x - player_size / 2;
		while (px < center_x + player_size / 2)
		{
			draw_minimap_pixel(game, px, py, 0xFF0000);
			px++;
		}
		py++;
	}
}

static void	init_corner(t_corner *corner, t_game *game)
{
	corner->visible_range = (MINIMAP_SIZE / (TILE_SIZE
				* MINIMAP_SCALE)) / 2 + 1;
	corner->player_map_x = (int)game->player.x;
	corner->player_map_y = (int)game->player.y;
}

void	render_minimap_corner(t_game *game)
{
	t_corner	corner;
	int			x;
	int			y;

	init_corner(&corner, game);
	y = corner.player_map_y - corner.visible_range;
	while (y <= corner.player_map_y + corner.visible_range)
	{
		x = corner.player_map_x - corner.visible_range;
		while (x <= corner.player_map_x + corner.visible_range)
		{
			if (y >= 0 && y < game->map.height && x >= 0 && x
				< (int)ft_strlen(game->map.grid[y]))
			{
				if (game->map.grid[y][x] == '1')
					draw_minimap_square(game, x, y, GRAY_OPACITY);
				else if (game->map.grid[y][x] == '0'
						|| is_player(game->map.grid[y][x]))
					draw_minimap_square(game, x, y, WHITE_OPACITY);
			}
			x++;
		}
		y++;
	}
	draw_minimap_player(game);
}
