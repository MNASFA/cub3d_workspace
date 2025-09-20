/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:43:05 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/09/20 17:30:18 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	draw_sun_frame(t_game *game, int frame)
{
	int		texture_x;
	int		texture_y;

	texture_x = 0;
	while (texture_x < game->sun[frame].width)
	{
		texture_y = 0;
		while (texture_y < game->sun[frame].height)
		{
			set_pixel(game, texture_x, texture_y, frame);
			texture_y++;
		}
		texture_x++;
	}
}

void	draw_sun(t_game *game)
{
	if (game->sun_frame < 44)
	{
		draw_sun_frame(game, game->sun_frame);
		game->sun_frame++;
	}
	else
	{
		game->sun_frame = 0;
		draw_sun_frame(game, game->sun_frame);
	}
}
