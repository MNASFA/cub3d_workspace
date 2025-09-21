/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 10:10:49 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/21 10:30:02 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_animation(t_game *game)
{
	game->space_pressed = 0;
	game->weapon_frame = 0;
	game->next_frame = 0;
	game->sun_frame = 0;
}

void	init_game(t_game *game)
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
	game->east.path = ft_strdup("textures/east_wall.xpm");
	game->no_parsed = 0;
	game->so_parsed = 0;
	game->ea_parsed = 0;
	game->we_parsed = 0;
	game->f_parsed = 0;
	game->c_parsed = 0;
	init_animation(game);
}

void	init_key_states(t_game *game)
{
	game->key_w_pressed = 0;
	game->key_s_pressed = 0;
	game->key_a_pressed = 0;
	game->key_d_pressed = 0;
	game->key_left_pressed = 0;
	game->key_right_pressed = 0;
}

void	init_square(t_square *square, t_game *game,
	int map_x, int map_y)
{
	square->tile_size = TILE_SIZE * MINIMAP_SCALE;
	square->center_offset_x = MINIMAP_SIZE / 2 - (game->player.x
			* square->tile_size);
	square->center_offset_y = MINIMAP_SIZE / 2 - (game->player.y
			* square->tile_size);
	square->screen_x = MINIMAP_MARGIN + (map_x * square->tile_size)
		+ square->center_offset_x;
	square->screen_y = MINIMAP_MARGIN + (map_y * square->tile_size)
		+ square->center_offset_y;
	square->py = 0;
}
