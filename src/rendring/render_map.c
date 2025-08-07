/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:49:06 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/08/05 14:15:48 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_square(t_game *game, int x, int y, int color)
{
	int py;
	int px;
	int pixel;

	py = y * TILE_SIZE;
	while (py < (y + 1) * TILE_SIZE)
	{
		px = x * TILE_SIZE;
		while (px < (x + 1) * TILE_SIZE)
		{
			if (px >= 0 && px < game->win_width && py >= 0 && py < game->win_width)
			{
				pixel = py * game->line_length + px * (game->bits_per_pixel / 8);
				*(unsigned int *)(game->add + pixel) = color;
			}
			px++;
		}
		py++;
	}
}

void draw_direction_line(t_game *game)
{
	t_line	line;
	int i;
	
    line.center_x = (int)(game->player.x * TILE_SIZE);
    line.center_y = (int)(game->player.y * TILE_SIZE);
    line.end_x = line.center_x + (int)(game->player.dir_x * 20);
    line.end_y = line.center_y + (int)(game->player.dir_y * 20);
    i = 0;
	while(i <= 20)
    {
        line.ratio = (double)i / 20;
        line.px = line.center_x + (line.end_x - line.center_x) * line.ratio;
        line.py = line.center_y + (line.end_y - line.center_y) * line.ratio;
        if (line.px >= 0 && line.px < game->win_width && line.py >= 0 && line.py < game->win_heigth)
        {
            line.pixel = line.py * game->line_length + line.px * (game->bits_per_pixel / 8);
            *(unsigned int*)(game->add + line.pixel) = RED;
        }
		i++;
    }
}

void render_map(t_game *game)
{
	int x;
	int y;

    ft_memset(game->add, 0, game->win_width * game->win_heigth * (game->bits_per_pixel / 8));
	y = 0;
    while (y < game->map.height)
    {
		x = 0;
        while(x < (int)ft_strlen(game->map.grid[y]))
        {
            if (game->map.grid[y][x] == '1')
                draw_square(game, x, y, GRAY);
            else if (game->map.grid[y][x] == '0' || is_player(game->map.grid[y][x]))
                draw_square(game, x, y, WHITE);
			x++;
        }
		y++;
    }
    draw_direction_line(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
