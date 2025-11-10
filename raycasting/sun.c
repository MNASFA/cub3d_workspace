/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:00:20 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/09/20 16:44:20 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	set_path_0(char path[25])
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
	path[10] = 's';
}

void	set_path(char path[25], int n)
{
	set_path_0(path);
	if (n >= 10)
	{
		path[11] = '0' + (n / 10);
		path[12] = '0' + (n % 10);
		path[13] = '.';
		path[14] = 'x';
		path[15] = 'p';
		path[16] = 'm';
		path[17] = '\0';
	}
	else
	{
		path[11] = '0' + n;
		path[12] = '.';
		path[13] = 'x';
		path[14] = 'p';
		path[15] = 'm';
		path[16] = '\0';
	}
}

void	setup_sun(t_game *game)
{
	int		i;
	char	path[25];

	i = 0;
	while (i < 45)
	{
		set_path(path, i + 1);
		game->sun[i].img = mlx_xpm_file_to_image(game->mlx, path,
				&game->sun[i].width, &game->sun[i].height);
		game->sun[i].add = mlx_get_data_addr(game->sun[i].img,
				&game->sun[i].bits_per_pixel, &game->sun[i].line_length,
				&game->sun[i].endian);
		i++;
	}
}

void	set_pixel(t_game *game, int texture_x, int texture_y, int frame)
{
	char	*pixel;
	char	*address_color;
	int		start_x;
	int		start_y;
	t_help	help;

	start_x = game->win_width / 2 - game->sun[frame].width / 2 - 300;
	start_y = -100;
	help.x = start_x + texture_x;
	help.y = start_y + texture_y;
	if (help.x >= 0 && help.x < game->win_width
		&& help.y >= 0 && help.y < game->win_heigth)
	{
		pixel = game->add + (help.y * game->line_length + \
			help.x * (game->bits_per_pixel / 8));
		address_color = game->sun[frame].add + \
			(texture_y * game->sun[frame].line_length + \
			texture_x * (game->sun[frame].bits_per_pixel / 8));
		if (*(unsigned int *)address_color != 0xff000000
			&& *(unsigned int *)address_color != 0)
			*(unsigned int *)pixel = *(unsigned int *)address_color;
	}
}

// void	draw_sun_frame(t_game *game, int frame)
// {
// 	int		texture_x;
// 	int		texture_y;

// 	texture_x = 0;
// 	while (texture_x < game->sun[frame].width)
// 	{
// 		texture_y = 0;
// 		while (texture_y < game->sun[frame].height)
// 		{
// 			set_pixel(game, texture_x, texture_y, frame);
// 			texture_y++;
// 		}
// 		texture_x++;
// 	}
// }

// void	draw_sun(t_game *game)
// {
// 	if (game->sun_frame < 44)
// 	{
// 		draw_sun_frame(game, game->sun_frame);
// 		game->sun_frame++;
// 	}
// 	else
// 	{
// 		game->sun_frame = 0;
// 		draw_sun_frame(game, game->sun_frame);
// 	}
// }
