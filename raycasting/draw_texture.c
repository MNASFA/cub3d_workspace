/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:11:30 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/09/20 17:30:11 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static t_texture	get_texture_by_direction(t_game *game, int texture)
{
	if (texture == NORTH)
		return (game->north);
	else if (texture == EAST)
		return (game->east);
	else if (texture == WEST)
		return (game->west);
	else
		return (game->south);
}

static void	calculate_texture_params(t_wall_data *wall, t_texture *text)
{
	wall->step = (double)text->height / (double)wall->real_line_height;
	wall->wall_center = wall->game->win_heigth / 2;
	wall->wall_start = wall->wall_center - wall->real_line_height / 2;
	wall->tex_pos = (wall->start - wall->wall_start) * wall->step;
}

static void	draw_texture_pixel(t_wall_data *wall, t_texture *text, int y)
{
	char	*pixel;
	char	*addresse_color;
	int		texture_y;

	texture_y = (int)wall->tex_pos;
	if (texture_y >= text->height)
		texture_y = text->height - 1;
	if (texture_y < 0)
		texture_y = 0;
	addresse_color = text->add + (texture_y * text->line_height) + \
		wall->texture_x * (text->bits_per_pexel / 8);
	pixel = wall->game->add + (y * wall->game->line_length) + \
		wall->x * (wall->game->bits_per_pixel / 8);
	*(unsigned int *)pixel = *(unsigned int *)addresse_color;
	wall->tex_pos += wall->step;
}

void	draw_wall_line_text(t_wall_data *wall, int texture)
{
	int			y;
	t_texture	text;

	text = get_texture_by_direction(wall->game, texture);
	calculate_texture_params(wall, &text);
	y = wall->start;
	while (y <= wall->end)
	{
		draw_texture_pixel(wall, &text, y);
		y++;
	}
}
