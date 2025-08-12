/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:56:16 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/08/12 09:32:11 by hmnasfa          ###   ########.fr       */
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
    double old_plane_x;

    old_dir_x = player->dir_x;
    player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
    player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);

    old_plane_x = player->plane_x;
    player->plane_x = player->plane_x * cos(angle) - player->plane_y * sin(angle);
    player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
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
        rotate_player(&game->player, -ROT_SPEED);
    if (keycode == KEY_RIGHT)
        rotate_player(&game->player, ROT_SPEED);
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
int mouse_movement(void *param)
{
    t_game *game = (t_game *)param;
    int mouse_x;
    int mouse_y;
    int center_x = game->win_width / 2;
    int center_y = game->win_heigth / 2;

    // Get current mouse position
    mlx_mouse_get_pos(game->win, &mouse_x, &mouse_y);

    // Calculate horizontal movement
    int delta_x = mouse_x - center_x;

    if (delta_x != 0)
    {
        // Rotate player
        game->player.dir_x += delta_x * SENSITIVITY;

        // Keep dir within 0..2π
        if (game->player.dir_x < 0)
            game->player.dir_x += 2 * M_PI;
        else if (game->player.dir_x >= 2 * M_PI)
            game->player.dir_x -= 2 * M_PI;

        // Reset mouse to center
        mlx_mouse_move(game->win, center_x, center_y);
    }
    return (0);
}
