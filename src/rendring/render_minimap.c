/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:51:16 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/08/14 16:45:01 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void draw_minimap_pixel(t_game *game, int screen_x, int screen_y, int color)
{
    int pixel;

    if (screen_x >= MINIMAP_MARGIN && screen_x < MINIMAP_MARGIN + MINIMAP_SIZE &&
        screen_y >= MINIMAP_MARGIN && screen_y < MINIMAP_MARGIN + MINIMAP_SIZE)
    {
        pixel = screen_y * game->line_length + screen_x * (game->bits_per_pixel / 8);
        *(unsigned int *)(game->add + pixel) = color;
    }
}

static void draw_minimap_square(t_game *game, int map_x, int map_y, int color)
{
    int py; 
    int px;
    int screen_x;
    int screen_y;
    int tile_size;
    int center_offset_x;
    int center_offset_y;
    
    tile_size = TILE_SIZE * MINIMAP_SCALE;
    center_offset_x = MINIMAP_SIZE / 2 - (game->player.x * tile_size);
    center_offset_y = MINIMAP_SIZE / 2 - (game->player.y * tile_size);
    screen_x = MINIMAP_MARGIN + (map_x * tile_size) + center_offset_x;
    screen_y = MINIMAP_MARGIN + (map_y * tile_size) + center_offset_y;
    py = 0;
    while (py < tile_size)
    {
        px = 0;
        while (px < tile_size)
        {
            draw_minimap_pixel(game, screen_x + px, screen_y + py, color);
            px++;
        }
        py++;
    }
}

static void draw_minimap_player(t_game *game)
{
    int py;
    int px;
    int player_size;
    int center_x;
    int center_y;
    
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

// static void draw_minimap_direction(t_game *game)
// {
//     t_line line;
//     int i;
//     int line_length = 15;
    
//     line.center_x = MINIMAP_MARGIN + MINIMAP_SIZE / 2;
//     line.center_y = MINIMAP_MARGIN + MINIMAP_SIZE / 2;
//     line.end_x = line.center_x + (int)(game->player.dir_x * line_length);
//     line.end_y = line.center_y + (int)(game->player.dir_y * line_length);
    
//     i = 0;
//     while (i <= line_length)
//     {
//         line.ratio = (double)i / line_length;
//         line.px = line.center_x + (line.end_x - line.center_x) * line.ratio;
//         line.py = line.center_y + (line.end_y - line.center_y) * line.ratio;
//         draw_minimap_pixel(game, line.px, line.py, 0x00FF00);
//         i++;
//     }
// }

// static void draw_minimap_background(t_game *game)
// {
//     int py, px;
    
//     py = MINIMAP_MARGIN;
//     while (py < MINIMAP_MARGIN + MINIMAP_SIZE)
//     {
//         px = MINIMAP_MARGIN;
//         while (px < MINIMAP_MARGIN + MINIMAP_SIZE)
//         {
//             draw_minimap_pixel(game, px, py, game->ceiling_color);
//             px++;
//         }
//         py++;
//     }
//     py = MINIMAP_MARGIN - 1;
//     while (py <= MINIMAP_MARGIN + MINIMAP_SIZE)
//     {
//         draw_minimap_pixel(game, MINIMAP_MARGIN - 1, py, 0x888888);
//         draw_minimap_pixel(game, MINIMAP_MARGIN + MINIMAP_SIZE, py, 0x888888);
//         py++;
//     }
//     px = MINIMAP_MARGIN - 1;
//     while (px <= MINIMAP_MARGIN + MINIMAP_SIZE)
//     {
//         draw_minimap_pixel(game, px, MINIMAP_MARGIN - 1, 0x888888);
//         draw_minimap_pixel(game, px, MINIMAP_MARGIN + MINIMAP_SIZE, 0x888888);
//         px++;
//     }
// }

void render_minimap_corner(t_game *game)
{
    int x;
    int y;
    int visible_range;
    int player_map_x;
    int player_map_y;

    visible_range = (MINIMAP_SIZE / (TILE_SIZE * MINIMAP_SCALE)) / 2 + 1;
    player_map_x = (int)game->player.x;
    player_map_y = (int)game->player.y;
    y = player_map_y - visible_range;
    while (y <= player_map_y + visible_range)
    {
        x = player_map_x - visible_range;
        while (x <= player_map_x + visible_range)
        {
            if (y >= 0 && y < game->map.height && x >= 0 && x < (int)ft_strlen(game->map.grid[y]))
            {
                if (game->map.grid[y][x] == '1')
                    draw_minimap_square(game, x, y, GRAY);
                else if (game->map.grid[y][x] == '0' || is_player(game->map.grid[y][x]))
                    draw_minimap_square(game, x, y, WHITE);
            }
            x++;
        }
        y++;
    }
    draw_minimap_player(game);
}
