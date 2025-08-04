/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:49:06 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/08/04 12:50:59 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// void draw_square(t_game *game, int x, int y, int color)
// {
// 	int start_x;
// 	int start_y;
// 	int end_x;
// 	int end_y;
// 	int py;
// 	int px;
// 	int pixel;

// 	start_x = x * TILE_SIZE;
// 	start_y = y * TILE_SIZE;
// 	end_x = start_x + TILE_SIZE;
// 	end_y = start_y + TILE_SIZE;
// 	py = start_y;
// 	while (py < end_y)
// 	{
// 		px = start_x;
// 		while (px < end_x)
// 		{
// 			if (px >= 0 && px < WIN_WIDTH && py >= 0 && py < WIN_HEIGHT)
//             {
//                 pixel = py * game->line_length + px * (game->bits_per_pixel / 8);
//                 *(unsigned int *)(game->add + pixel) = color;
//             }
// 			px++;
// 		}
// 		py++;
// 	}
// }

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
			if (px >= 0 && px < WIN_WIDTH && py >= 0 && py < WIN_HEIGHT)
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
	int center_x;
	int center_y;
	int line_length;
	int end_x;
	int end_y;
	int i;
	float ratio;
	int px;
	int py;
	int pixel;
	
    center_x = (int)(game->player.x * TILE_SIZE);
    center_y = (int)(game->player.y * TILE_SIZE);
    line_length = 20;
    end_x = center_x + (int)(game->player.dir_x * line_length);
    end_y = center_y + (int)(game->player.dir_y * line_length);
    i = 0;
	while(i <= line_length)
    {
        ratio = (float)i / line_length;
        px = center_x + (end_x - center_x) * ratio;
        py = center_y + (end_y - center_y) * ratio;
        if (px >= 0 && px < WIN_WIDTH && py >= 0 && py < WIN_HEIGHT)
        {
            pixel = py * game->line_length + px * (game->bits_per_pixel / 8);
            *(unsigned int*)(game->add + pixel) = RED;
        }
		i++;
    }
}

void render_map(t_game *game)
{
	int x;
	int y;

    ft_memset(game->add, 0, WIN_WIDTH * WIN_HEIGHT * (game->bits_per_pixel / 8));
	y = 0;
    while (y < game->map.height)
    {
		x = 0;
        while(x < game->map.width)
        {
            if (game->map.grid[y][x] == '1')
                draw_square(game, x, y, 0x333333); 
            else if (game->map.grid[y][x] == '0' || is_player(game->map.grid[y][x]))
                draw_square(game, x, y, 0xFFFFFF);
			x++;
        }
		y++;
    }
    draw_direction_line(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
