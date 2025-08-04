/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:56:16 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/08/04 18:13:40 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void exit_game(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img);
    mlx_destroy_window(game->mlx, game->win);
    // free later
    exit(0);
}

static int is_walkable(t_game *game, double new_x, double new_y)
{
	int map_x;
	int map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (map_x < 0 || map_x >= game->map.width)
		return (0);
	if (map_y < 0 || map_y >= game->map.height)
		return (0);
	if (game->map.grid[map_y][map_x] == '1')
		return (0);
	return (1);
}

void rotate_player(t_player *player, double angle)
{
    double old_dir_x;

    old_dir_x = player->dir_x;
    player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
    player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
}

int handle_keypress(int keycode, t_game *game)
{
    double new_x = game->player.x;
    double new_y = game->player.y;

    if (keycode == KEY_W)
    {
        new_x += game->player.dir_x * MOVE_SPEED;
        new_y += game->player.dir_y * MOVE_SPEED;
    }
    else if (keycode == KEY_S) 
    {
        new_x -= game->player.dir_x * MOVE_SPEED;
        new_y -= game->player.dir_y * MOVE_SPEED;
    }
    else if (keycode == KEY_A) 
    {
        new_x += game->player.dir_y * MOVE_SPEED;  
        new_y -= game->player.dir_x * MOVE_SPEED;
    }
    else if (keycode == KEY_D) 
    {
        new_x -= game->player.dir_y * MOVE_SPEED;
        new_y += game->player.dir_x * MOVE_SPEED;
    }
    if (keycode == KEY_LEFT)
        rotate_player(&game->player, ROT_SPEED);
    if (keycode == KEY_RIGHT)
        rotate_player(&game->player, -ROT_SPEED);
    else if (keycode == KEY_ESC)
        exit_game(game);

    // Update position if movement is valid
    if (is_walkable(game, new_x, new_y))
    {
        game->player.x = new_x;
        game->player.y = new_y;
        render_map(game);
    }
    return (0);
}