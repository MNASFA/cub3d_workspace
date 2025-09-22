/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:17:28 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/09/20 17:51:22 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../cub3d.h"
# define NORTH 19
# define EAST 20
# define SOUTH 21
# define WEST 22

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
}	t_ray;

typedef struct s_help
{
	int	x;
	int	y;
}	t_help;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
}	t_dda;

typedef struct s_wall_calc
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		texture_x;
}	t_wall_calc;

typedef struct s_wall_data
{
	t_game	*game;
	int		x;
	int		start;
	int		end;
	int		texture_x;
	int		real_line_height;
	double	step;
	int		wall_center;
	int		wall_start;
	double	tex_pos;
}	t_wall_data;

typedef struct s_weap
{
	int		texture_y;
	int		texture_x;
	int		frame;
	int		y;
	int		x;
}	t_weap;

void	cast_rays(t_game *game, int x);
void	calculate_wall_dimensions(t_game *game, t_ray *ray,
			t_dda *dda, t_wall_calc *calc);
void	perform_dda(t_game *game, t_ray *ray, t_dda *dda);
void	draw_wall_line_text(t_wall_data *wall, int texture);
void	draw_sun(t_game *game);
void	set_pixel(t_game *game, int texture_x, int texture_y, int frame);
void	setup_sun(t_game *game);
void	handle_weapon(t_game *game, int frame);
void	handle_weapon_animation(t_game *game);
void	set_weap_pixel(t_game *game, t_weap *data);
void	setup_weapon(t_game *game);
void	calculate_ray_direction(t_game *game, int x, t_ray *ray);

#endif