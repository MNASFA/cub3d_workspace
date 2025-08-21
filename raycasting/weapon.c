/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:20:25 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/08/21 16:19:07 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#  include "raycasting.h"

void setup_weapon(t_game *game)
{
    game->weapon[0].img = mlx_xpm_file_to_image(game->mlx, "animation/0.xpm", &game->weapon[0].width, &game->weapon[0].height);
    game->weapon[0].add = mlx_get_data_addr(game->weapon[0].img, &game->weapon[0].bits_per_pixel, &game->weapon[0].line_length, &game->weapon[0].endian);
    game->weapon[1].img = mlx_xpm_file_to_image(game->mlx, "animation/1.xpm", &game->weapon[1].width, &game->weapon[1].height);
    game->weapon[1].add = mlx_get_data_addr(game->weapon[1].img, &game->weapon[1].bits_per_pixel, &game->weapon[1].line_length, &game->weapon[1].endian);
    game->weapon[2].img = mlx_xpm_file_to_image(game->mlx, "animation/2.xpm", &game->weapon[2].width, &game->weapon[2].height);
    game->weapon[2].add = mlx_get_data_addr(game->weapon[2].img, &game->weapon[2].bits_per_pixel, &game->weapon[2].line_length, &game->weapon[2].endian);
    game->weapon[3].img = mlx_xpm_file_to_image(game->mlx, "animation/3.xpm", &game->weapon[3].width, &game->weapon[3].height);
    game->weapon[3].add = mlx_get_data_addr(game->weapon[3].img, &game->weapon[3].bits_per_pixel, &game->weapon[3].line_length, &game->weapon[3].endian);
    game->weapon[4].img = mlx_xpm_file_to_image(game->mlx, "animation/4.xpm", &game->weapon[4].width, &game->weapon[4].height);
    game->weapon[4].add = mlx_get_data_addr(game->weapon[4].img, &game->weapon[4].bits_per_pixel, &game->weapon[4].line_length, &game->weapon[4].endian);
    game->weapon[5].img = mlx_xpm_file_to_image(game->mlx, "animation/5.xpm", &game->weapon[5].width, &game->weapon[5].height);
    game->weapon[5].add = mlx_get_data_addr(game->weapon[5].img, &game->weapon[5].bits_per_pixel, &game->weapon[5].line_length, &game->weapon[5].endian);
    game->weapon[6].img = mlx_xpm_file_to_image(game->mlx, "animation/6.xpm", &game->weapon[6].width, &game->weapon[6].height);
    game->weapon[6].add = mlx_get_data_addr(game->weapon[6].img, &game->weapon[6].bits_per_pixel, &game->weapon[6].line_length, &game->weapon[6].endian);
    game->weapon[7].img = mlx_xpm_file_to_image(game->mlx, "animation/7.xpm", &game->weapon[7].width, &game->weapon[7].height);
    game->weapon[7].add = mlx_get_data_addr(game->weapon[7].img, &game->weapon[7].bits_per_pixel, &game->weapon[7].line_length, &game->weapon[7].endian);
    game->weapon[8].img = mlx_xpm_file_to_image(game->mlx, "animation/8.xpm", &game->weapon[8].width, &game->weapon[8].height);
    game->weapon[8].add = mlx_get_data_addr(game->weapon[8].img, &game->weapon[8].bits_per_pixel, &game->weapon[8].line_length, &game->weapon[8].endian);
    game->weapon[9].img = mlx_xpm_file_to_image(game->mlx, "animation/9.xpm", &game->weapon[9].width, &game->weapon[9].height);
    game->weapon[9].add = mlx_get_data_addr(game->weapon[9].img, &game->weapon[9].bits_per_pixel, &game->weapon[9].line_length, &game->weapon[9].endian);
    game->weapon[10].img = mlx_xpm_file_to_image(game->mlx, "animation/10.xpm", &game->weapon[10].width, &game->weapon[10].height);
    game->weapon[10].add = mlx_get_data_addr(game->weapon[10].img, &game->weapon[10].bits_per_pixel, &game->weapon[10].line_length, &game->weapon[10].endian);
    game->weapon[11].img = mlx_xpm_file_to_image(game->mlx, "animation/11.xpm", &game->weapon[11].width, &game->weapon[11].height);
    game->weapon[11].add = mlx_get_data_addr(game->weapon[11].img, &game->weapon[11].bits_per_pixel, &game->weapon[11].line_length, &game->weapon[11].endian);
    game->weapon[12].img = mlx_xpm_file_to_image(game->mlx, "animation/12.xpm", &game->weapon[12].width, &game->weapon[12].height);
    game->weapon[12].add = mlx_get_data_addr(game->weapon[12].img, &game->weapon[12].bits_per_pixel, &game->weapon[12].line_length, &game->weapon[12].endian);
    game->weapon[13].img = mlx_xpm_file_to_image(game->mlx, "animation/13.xpm", &game->weapon[13].width, &game->weapon[13].height);
    game->weapon[13].add = mlx_get_data_addr(game->weapon[13].img, &game->weapon[13].bits_per_pixel, &game->weapon[13].line_length, &game->weapon[13].endian);
    game->weapon[14].img = mlx_xpm_file_to_image(game->mlx, "animation/14.xpm", &game->weapon[14].width, &game->weapon[14].height);
    game->weapon[14].add = mlx_get_data_addr(game->weapon[14].img, &game->weapon[14].bits_per_pixel, &game->weapon[14].line_length, &game->weapon[14].endian);
    if (!game->weapon[0].img || !game->weapon[1].img || !game->weapon[2].img || !game->weapon[3].img ||
        !game->weapon[4].img || !game->weapon[5].img || !game->weapon[6].img || !game->weapon[7].img ||
        !game->weapon[8].img || !game->weapon[9].img || !game->weapon[10].img || !game->weapon[11].img ||
        !game->weapon[12].img || !game->weapon[13].img || !game->weapon[14].img)
    {
        print_error("Failed to load weapon textures");
        exit(EXIT_FAILURE);
    }
}

void handle_weapon(t_game *game, int frame)
{
    int x;
    int y;
    char *pixel;
    char *address_color;
    int texture_x, texture_y;

    texture_x = 0;
    texture_y = 0;
    x = game->win_width / 2 - game->weapon[frame].width / 2;
    while (texture_x < game->weapon[frame].width - 1)
    {
        y = game->win_heigth - game->weapon[frame].height;
        while (texture_y < game->weapon[frame].height - 1)
        {
            pixel = game->add + (y * game->line_length + x * (game->bits_per_pixel / 8));
            address_color = game->weapon[frame].add + (texture_y * game->weapon[frame].line_length + texture_x * (game->weapon[frame].bits_per_pixel / 8));
            if (*(unsigned int*)address_color != 0xff000000)
            {
                *(unsigned int*)pixel = *(unsigned int*)address_color;
            }
            texture_y++;
            y++;
            pixel += (game->bits_per_pixel / 8);
        }
        texture_y = 0;
        x++;
        texture_x ++;
    }
}

void handle_weapon_animation(t_game *game)
{

    if (game->space_pressed == 1)
    {
        handle_weapon(game, game->weapon_frame);
        if (game->next_frame ==5)
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