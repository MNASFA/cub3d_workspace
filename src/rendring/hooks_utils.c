/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:23:35 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/20 20:25:05 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

static int	is_position_valid(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return (0);
	return (game->map.grid[y][x] != '1');
}

int	is_walkable(t_game *game, double new_x, double new_y)
{
	double	buffer;

	buffer = 0.2;
	if (!is_position_valid(game, (int)new_x, (int)new_y))
		return (0);
	if (!is_position_valid(game, (int)(new_x + buffer), (int)new_y)
		|| !is_position_valid(game, (int)(new_x - buffer), (int)new_y)
		|| !is_position_valid(game, (int)new_x, (int)(new_y + buffer))
		|| !is_position_valid(game, (int)new_x, (int)(new_y - buffer)))
		return (0);
	if (!is_position_valid(game, (int)(new_x + buffer),
		(int)(new_y + buffer))
		|| !is_position_valid(game, (int)(new_x - buffer),
		(int)(new_y + buffer))
		|| !is_position_valid(game, (int)(new_x + buffer),
		(int)(new_y - buffer))
		|| !is_position_valid(game, (int)(new_x - buffer),
		(int)(new_y - buffer)))
		return (0);
	return (1);
}

void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(angle)
		- player->plane_y * sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}

void	calculate_movement(t_game *game, double *new_x,
	double *new_y, int *moved)
{
	if (game->key_w_pressed)
	{
		*new_x += game->player.dir_x * MOVE_SPEED;
		*new_y += game->player.dir_y * MOVE_SPEED;
		*moved = 1;
	}
	if (game->key_s_pressed)
	{
		*new_x -= game->player.dir_x * MOVE_SPEED;
		*new_y -= game->player.dir_y * MOVE_SPEED;
		*moved = 1;
	}
	if (game->key_a_pressed)
	{
		*new_x += game->player.dir_y * MOVE_SPEED;
		*new_y -= game->player.dir_x * MOVE_SPEED;
		*moved = 1;
	}
	if (game->key_d_pressed)
	{
		*new_x -= game->player.dir_y * MOVE_SPEED;
		*new_y += game->player.dir_x * MOVE_SPEED;
		*moved = 1;
	}
}
