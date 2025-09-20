/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:16:37 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/18 15:16:38 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void init_game(t_game *game)
{
    game->floor_color = -1;
    game->ceiling_color = -1;

    game->map.grid = NULL;
    game->map.width = 0;
    game->map.height = 0;
    game->map.player_count = 0;

    game->player.x = 0;
    game->player.y = 0;

    game->north.img = NULL;
    game->north.path = ft_strdup("textures/north_wall.xpm");

    game->south.img = NULL;
    game->south.path = ft_strdup("textures/south_wall.xpm");

    game->west.img = NULL;
    game->west.path = ft_strdup("textures/west_wall.xpm");

    game->east.img = NULL;
    game->east.path =ft_strdup("textures/east_wall.xpm");
    // parsing flags
    game->no_parsed = 0;
    game->so_parsed = 0;
    game->ea_parsed = 0;
    game->we_parsed = 0;
    game->f_parsed = 0;
	game->c_parsed = 0;
    game->space_pressed = 0;
    game->weapon_frame = 0;
    game->next_frame = 0;
    game->sun_frame = 0;
}

void init_player_direction(t_player *player, char spawn_dir)
{
    if (spawn_dir == 'N') {
        player->dir_x = 0.0;
        player->dir_y = -1.0;
        player->plane_x= 0.66;
        player->plane_y = 0.0;
    }
    else if (spawn_dir == 'S') {
        player->dir_x = 0.0;
        player->dir_y = 1.0;
        player->plane_x = -0.66;
        player->plane_y = 0.0;
    }
    else if (spawn_dir == 'E') {
        player->dir_x = 1.0;
        player->dir_y = 0.0;
        player->plane_x = 0.0;
        player->plane_y = 0.66;
    }
    else if (spawn_dir == 'W') {
        player->dir_x = -1.0;
        player->dir_y = 0.0;
        player->plane_x = 0.0;
        player->plane_y = -0.66;
    }
}

void init_key_states(t_game *game)
{
    game->key_w_pressed = 0;
    game->key_s_pressed = 0;
    game->key_a_pressed = 0;
    game->key_d_pressed = 0;
    game->key_left_pressed = 0;
    game->key_right_pressed = 0;
}
