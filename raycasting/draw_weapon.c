/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 17:24:24 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/09/20 17:50:01 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	handle_weapon(t_game *game, int frame)
{
	t_weap	data;

	data.frame = frame;
	data.texture_x = 0;
	data.x = game->win_width / 2 - game->weapon[frame].width / 2;
	while (data.texture_x < game->weapon[frame].width)
	{
		data.texture_y = 0;
		data.y = game->win_heigth - game->weapon[frame].height;
		while (data.texture_y < game->weapon[frame].height)
		{
			set_weap_pixel(game, &data);
			data.texture_y++;
			data.y++;
		}
		data.x++;
		data.texture_x++;
	}
}

void	handle_weapon_animation(t_game *game)
{
	if (game->space_pressed == 1)
	{
		handle_weapon(game, game->weapon_frame);
		if (game->next_frame == 5)
		{
			game->weapon_frame++;
			game->next_frame = 0;
		}
		if (game->weapon_frame > 14)
		{
			game->space_pressed = 0;
			game->weapon_frame = 0;
		}
		game->next_frame++;
	}
	else
	{
		handle_weapon(game, 0);
	}
}
