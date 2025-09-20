/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:56:16 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/18 13:44:16 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3d.h"

void exit_game(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img);
    mlx_destroy_window(game->mlx, game->win);
    // free at exit
    exit(0);
}

int is_walkable(t_game *game, double new_x, double new_y)
{
    int map_x = (int)new_x;
    int map_y = (int)new_y;
    double buffer = 0.2; // Adjusted buffer for precision

    // Check if the new position is valid
    if (map_x < 0 || map_x >= game->map.width || map_y < 0 || map_y >= game->map.height)
        return (0);
    if (game->map.grid[map_y][map_x] == '1')
        return (0);

    // Check positions around the player with buffer
    int check_positions[8][2] = {
        {(int)(new_x + buffer), (int)new_y},      // Right
        {(int)(new_x - buffer), (int)new_y},      // Left  
        {(int)new_x, (int)(new_y + buffer)},      // Down
        {(int)new_x, (int)(new_y - buffer)},      // Up
        {(int)(new_x + buffer), (int)(new_y + buffer)}, // Bottom-right diagonal
        {(int)(new_x - buffer), (int)(new_y + buffer)}, // Bottom-left diagonal
        {(int)(new_x + buffer), (int)(new_y - buffer)}, // Top-right diagonal
        {(int)(new_x - buffer), (int)(new_y - buffer)}  // Top-left diagonal
    };

    for (int i = 0; i < 8; i++) {
        int check_x = check_positions[i][0];
        int check_y = check_positions[i][1];

        if (check_x < 0 || check_x >= game->map.width || check_y < 0 || check_y >= game->map.height)
            return (0);
        if (game->map.grid[check_y][check_x] == '1')
            return (0);
    }

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

void process_all_inputs(t_game *game)
{
    double new_x;
    double new_y;
    int moved;

    new_x = game->player.x;
    new_y = game->player.y;
    moved = 0;
    if (game->key_w_pressed)
    {
        new_x += game->player.dir_x * MOVE_SPEED;
        new_y += game->player.dir_y * MOVE_SPEED;
        moved = 1;
    }
    if (game->key_s_pressed) 
    {
        new_x -= game->player.dir_x * MOVE_SPEED;
        new_y -= game->player.dir_y * MOVE_SPEED;
        moved = 1;
    }
    if (game->key_a_pressed) 
    {
        new_x += game->player.dir_y * MOVE_SPEED;  
        new_y -= game->player.dir_x * MOVE_SPEED;
        moved = 1;
    }
    if (game->key_d_pressed) 
    {
        new_x -= game->player.dir_y * MOVE_SPEED;
        new_y += game->player.dir_x * MOVE_SPEED;
        moved = 1;
    }
    if (game->key_left_pressed)
    {
        rotate_player(&game->player, -ROT_SPEED);
    }
    if (game->key_right_pressed)
    {
        rotate_player(&game->player, ROT_SPEED);
    }
    if (moved && is_walkable(game, new_x, new_y))
    {
        game->player.x = new_x;
        game->player.y = new_y;
    }
}

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == KEY_W)
        game->key_w_pressed = 1;
    if (keycode == KEY_S)
        game->key_s_pressed = 1;
    if (keycode == KEY_A)
        game->key_a_pressed = 1;
    if (keycode == KEY_D)
        game->key_d_pressed = 1;
    if (keycode == KEY_LEFT)
        game->key_left_pressed = 1;
    if (keycode == KEY_RIGHT)
        game->key_right_pressed = 1;
    if (keycode == KEY_ESC)
        exit_game(game);
    if (keycode == KEY_SPACE)
        game->space_pressed = 1;
    return (0);
}

int handle_keyrelease(int keycode, t_game *game)
{
    if (keycode == KEY_W)
        game->key_w_pressed = 0;
    if (keycode == KEY_S)
        game->key_s_pressed = 0;
    if (keycode == KEY_A)
        game->key_a_pressed = 0;
    if (keycode == KEY_D)
        game->key_d_pressed = 0;
    if (keycode == KEY_LEFT)
        game->key_left_pressed = 0;
    if (keycode == KEY_RIGHT)
        game->key_right_pressed = 0;
    return (0);
}

int game_loop(t_game *game)
{
    process_all_inputs(game);
    render_game_with_minimap(game);   
    return (0);
}

int handle_mouse_move(int x, int y, t_game *game)
{
    static int  last_x;
    static int  center_x;
    double      rotation_angle;
    int         delta_x;
    (void) y;
    
    if (last_x == 0)
    {
        center_x = game->win_width / 2;
        last_x = center_x;
        return (0);
    }
    delta_x = x - center_x;
    if (abs(delta_x) > 2)
    {
        rotation_angle = delta_x * SENSITIVITY;
        rotate_player(&game->player, rotation_angle);
        mlx_mouse_move(game->mlx, game->win, center_x, game->win_heigth / 2);
    }
    last_x = x;
    return (0);
}

