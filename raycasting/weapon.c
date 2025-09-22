/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:20:25 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/09/20 17:25:55 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_path_1(char path[25])
{
	path[0] = 'a';
	path[1] = 'n';
	path[2] = 'i';
	path[3] = 'm';
	path[4] = 'a';
	path[5] = 't';
	path[6] = 'i';
	path[7] = 'o';
	path[8] = 'n';
	path[9] = '/';
}

void	set_path_2(char path[25], int n)
{
	set_path_1(path);
	if (n >= 10)
	{
		path[10] = '0' + (n / 10);
		path[11] = '0' + (n % 10);
		path[12] = '.';
		path[13] = 'x';
		path[14] = 'p';
		path[15] = 'm';
		path[16] = '\0';
	}
	else
	{
		path[10] = '0' + n;
		path[11] = '.';
		path[12] = 'x';
		path[13] = 'p';
		path[14] = 'm';
		path[15] = '\0';
	}
}

void	setup_weapon(t_game *game)
{
	int		i;
	char	path[25];

	i = 0;
	while (i < 15)
	{
		set_path_2(path, i);
		game->weapon[i].img = mlx_xpm_file_to_image(game->mlx, path,
				&game->weapon[i].width, &game->weapon[i].height);
		game->weapon[i].add = mlx_get_data_addr(game->weapon[i].img,
				&game->weapon[i].bits_per_pixel,
				&game->weapon[i].line_length, &game->weapon[i].endian);
		i++;
	}
	if (!game->weapon[0].img || !game->weapon[1].img
		|| !game->weapon[2].img || !game->weapon[3].img || \
		!game->weapon[4].img || !game->weapon[5].img || \
		!game->weapon[6].img || !game->weapon[7].img || \
		!game->weapon[8].img || !game->weapon[9].img || \
		!game->weapon[10].img || !game->weapon[11].img || \
		!game->weapon[12].img || !game->weapon[13].img || !game->weapon[14].img)
	{
		print_error("Failed to load weapon textures");
		exit(EXIT_FAILURE);
	}
}

void	set_weap_pixel(t_game *game, t_weap *data)
{
	char	*address_color;
	char	*pixel;

	pixel = game->add + (data->y * game->line_length + \
			data->x * (game->bits_per_pixel / 8));
	address_color = game->weapon[data->frame].add + \
		(data->texture_y * game->weapon[data->frame].line_length + \
		data->texture_x * (game->weapon[data->frame].bits_per_pixel / 8));
	if (*(unsigned int *)address_color != 0xff000000)
		*(unsigned int *)pixel = *(unsigned int *)address_color;
}

// void	handle_weapon(t_game *game, int frame)
// {
// 	t_weap	*data;

// 	data->frame = frame;
// 	data->texture_x = 0;
// 	data->x = game->win_width / 2 - game->weapon[frame].width / 2;
// 	while (data->texture_x < game->weapon[frame].width)
// 	{
// 		data->texture_y = 0;
// 		data->y = game->win_heigth - game->weapon[frame].height;
// 		while (data->texture_y < game->weapon[frame].height)
// 		{
// 			set_weap_pixel(game, data);
// 			data->texture_y++;
// 			data->y++;
// 		}
// 		data->x++;
// 		data->texture_x++;
// 	}
// }

// void	handle_weapon_animation(t_game *game)
// {
// 	if (game->space_pressed == 1)
// 	{
// 		handle_weapon(game, game->weapon_frame);
// 		if (game->next_frame == 5)
// 		{
// 			game->weapon_frame++;
// 			game->next_frame = 0;
// 		}
// 		if (game->weapon_frame > 14)
// 		{
// 			game->space_pressed = 0;
// 			game->weapon_frame = 0;
// 		}
// 		game->next_frame++;
// 	}
// 	else
// 	{
// 		handle_weapon(game, 0);
// 	}
// }
