/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:49:06 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/08/07 13:24:04 by hmnasfa          ###   ########.fr       */
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

void draw_vertical_line(t_game *game, int x, int start, int end, int color)
{
    int y;
    char *pixel;
    
    y = start;
    while (y <= end)
    {
        pixel = game->add + (y * game->line_length + x * (game->bits_per_pixel / 8));
        *(unsigned int*)pixel = color;
        y++;
    }
}

void cast_rays(t_game *game, int x)
{
    double camera_x;
    double ray_dir_x;
    double ray_dir_y ;
    double perp_wall_dist;
    double delta_dist_x;
    double delta_dist_y;
    double side_dist_x;
    double  side_dist_y;
    int map_x;
    int map_y;
    int step_x;
    int step_y;
    int hit;
    int side;
    int line_height;
    int draw_start;
    int draw_end;
    int color;

    hit = 0;
    camera_x = 2 * x / (double)game->win_width - 1; 
    ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
    ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;
    map_x = (int)game->player.x;
    map_y = (int)game->player.y;
    delta_dist_x = fabs(1 / ray_dir_x);
    delta_dist_y = fabs(1 / ray_dir_y);
    if (ray_dir_x < 0)
    {
        step_x = -1;
        side_dist_x = (game->player.x - map_x) * delta_dist_x;
    }
    else
    {
        step_x = 1;
        side_dist_x = (map_x + 1.0 - game->player.x) * delta_dist_x;
    }
    
    if (ray_dir_y < 0)
    {
        step_y = -1;
        side_dist_y = (game->player.y - map_y) * delta_dist_y;
    }
    else
    {
        step_y = 1;
        side_dist_y = (map_y + 1.0 - game->player.y) * delta_dist_y;
    }
    while (hit == 0)
    {
        if (side_dist_x < side_dist_y)
        {
            side_dist_x += delta_dist_x;
            map_x += step_x;
            side = 0;
        }
        else
        {
            side_dist_y += delta_dist_y;
            map_y += step_y;
            side = 1;
        }
        if (game->map.grid[map_y][map_x] == '1')
            hit = 1;
    }
    if (side == 0)
        perp_wall_dist = (map_x - game->player.x + (1 - step_x) / 2) / ray_dir_x;
    else
        perp_wall_dist = (map_y - game->player.y + (1 - step_y) / 2) / ray_dir_y;
    line_height = (int)(game->win_heigth / perp_wall_dist);
    draw_start = -line_height / 2 + game->win_heigth / 2;
    if (draw_start < 0)
        draw_start = 0;
    draw_end = line_height / 2 + game->win_heigth / 2;
    if (draw_end >= game->win_heigth)
        draw_end = game->win_heigth - 1;
    if (side == 1)
        color = 0xFF0000;
    else
        color = 0x00FF00; 
    draw_vertical_line(game, x, draw_start, draw_end, color);
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
        while(x < game->win_width)
        {
            cast_rays(game, x);
			x++;
        }
		y++;
    }
    // draw_direction_line(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}
