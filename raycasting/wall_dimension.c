/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_dimension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:06:36 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/09/20 17:52:43 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	calculate_ray_direction(t_game *game, int x, t_ray *ray)
{
	double	camera_x;

	camera_x = 2 * x / (double)game->win_width - 1;
	ray->dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	ray->dir_y = game->player.dir_y + game->player.plane_y * camera_x;
}

static double	calculate_perp_wall_dist(t_game *game, t_ray *ray, t_dda *dda)
{
	double	perp_wall_dist;

	if (dda->side == 0)
		perp_wall_dist = (dda->map_x - game->player.x + \
			(1 - dda->step_x) / 2) / ray->dir_x;
	else
		perp_wall_dist = (dda->map_y - game->player.y + \
			(1 - dda->step_y) / 2) / ray->dir_y;
	if (perp_wall_dist < 0.1)
		perp_wall_dist = 0.1;
	return (perp_wall_dist);
}

static void	calculate_draw_bounds(t_game *game, double perp_wall_dist,
	t_wall_calc *calc)
{
	calc->line_height = (int)(game->win_heigth / perp_wall_dist);
	calc->draw_start = -(calc->line_height) / 2 + game->win_heigth / 2;
	if (calc->draw_start < 0)
		calc->draw_start = 0;
	calc->draw_end = (calc->line_height) / 2 + game->win_heigth / 2;
	if (calc->draw_end >= game->win_heigth)
		calc->draw_end = game->win_heigth - 1;
}

void	calculate_wall_dimensions(t_game *game, t_ray *ray,
	t_dda *dda, t_wall_calc *calc)
{
	double	wall_x;
	double	perp_wall_dist;

	perp_wall_dist = calculate_perp_wall_dist(game, ray, dda);
	if (dda->side == 0)
		wall_x = game->player.y + perp_wall_dist * ray->dir_y;
	else
		wall_x = game->player.x + perp_wall_dist * ray->dir_x;
	wall_x = wall_x - floor(wall_x);
	calc->texture_x = (int)(wall_x * game->north.width);
	if (calc->texture_x >= game->north.width)
		calc->texture_x = game->north.width - 1;
	if (calc->texture_x < 0)
		calc->texture_x = 0;
	calculate_draw_bounds(game, perp_wall_dist, calc);
}
