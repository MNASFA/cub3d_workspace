/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:28:35 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/20 20:28:53 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	process_all_inputs(t_game *game)
{
	double	new_x;
	double	new_y;
	int		moved;

	new_x = game->player.x;
	new_y = game->player.y;
	moved = 0;
	calculate_movement(game, &new_x, &new_y, &moved);
	if (game->key_left_pressed)
		rotate_player(&game->player, -ROT_SPEED);
	if (game->key_right_pressed)
		rotate_player(&game->player, ROT_SPEED);
	if (moved && is_walkable(game, new_x, new_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

int	handle_keypress(int keycode, t_game *game)
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

int	handle_keyrelease(int keycode, t_game *game)
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

int	game_loop(t_game *game)
{
	process_all_inputs(game);
	render_game_with_minimap(game);
	return (0);
}

int	handle_mouse_move(int x, int y, t_game *game)
{
	static int	last_x;
	static int	center_x;
	double		rotation_angle;
	int			delta_x;

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
