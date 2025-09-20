/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:08:49 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/09/20 17:30:31 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	init_dda_params(t_game *game, t_ray *ray, t_dda *dda)
{
	dda->map_x = (int)game->player.x;
	dda->map_y = (int)game->player.y;
	dda->delta_dist_x = fabs(1 / ray->dir_x);
	dda->delta_dist_y = fabs(1 / ray->dir_y);
	dda->hit = 0;
}

static void	calculate_step_and_side_dist_x(t_game *game, t_ray *ray, t_dda *dda)
{
	if (ray->dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (game->player.x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - game->player.x) * \
			dda->delta_dist_x;
	}
}

static void	calculate_step_and_side_dist_y(t_game *game, t_ray *ray, t_dda *dda)
{
	if (ray->dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (game->player.y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - game->player.y) * \
			dda->delta_dist_y;
	}
}

static void	perform_dda_step(t_game *game, t_dda *dda)
{
	if (dda->side_dist_x < dda->side_dist_y)
	{
		dda->side_dist_x += dda->delta_dist_x;
		dda->map_x += dda->step_x;
		dda->side = 0;
	}
	else
	{
		dda->side_dist_y += dda->delta_dist_y;
		dda->map_y += dda->step_y;
		dda->side = 1;
	}
	if (game->map.grid[dda->map_y][dda->map_x] == '1')
		dda->hit = 1;
}

void	perform_dda(t_game *game, t_ray *ray, t_dda *dda)
{
	init_dda_params(game, ray, dda);
	calculate_step_and_side_dist_x(game, ray, dda);
	calculate_step_and_side_dist_y(game, ray, dda);
	while (dda->hit == 0)
		perform_dda_step(game, dda);
}
