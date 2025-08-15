/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:33:45 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/08/14 21:38:26 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		print_error("Failed to initialize mlx");
		return (0);
	}

    game->win = mlx_new_window(game->mlx, game->win_width, game->win_heigth, WIN_TITLE);
    if (!game->win)
    {
        print_error("Failed to create window");
        return (0);
    }

    game->img = mlx_new_image(game->mlx, game->win_width, game->win_heigth);
    if (!game->img)
    {
        print_error("Failed to create image buffer");
        return (0);
    }

    game->add = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
    if (!game->add)
    {
        print_error("Failed to get image data address");
        return (0);
    }

    return (1);
}

