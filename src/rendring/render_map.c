/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:49:06 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/20 17:51:06 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_square(t_game *game, int x, int y, int color)
{
	int	py;
	int	px;
	int	pixel;

	py = y * TILE_SIZE;
	while (py < (y + 1) * TILE_SIZE)
	{
		px = x * TILE_SIZE;
		while (px < (x + 1) * TILE_SIZE)
		{
			if (px >= 0 && px < game->win_width && py
				>= 0 && py < game->win_width)
			{
				pixel = py * game->line_length + px
					* (game->bits_per_pixel / 8);
				*(unsigned int *)(game->add + pixel) = color;
			}
			px++;
		}
		py++;
	}
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	ft_memset(game->add, 0, game->win_width * game->win_heigth
		* (game->bits_per_pixel / 8));
	y = 0;
	draw_background(game);
	draw_sun(game);
	x = 0;
	while (x < game->win_width)
	{
		cast_rays(game, x);
		x++;
	}
	handle_weapon_animation(game);
	return (0);
}
