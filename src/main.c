/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:56:23 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/18 09:32:30 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

void print_map_grid(t_game *game)
{
	int i = 0;

	printf("🗺️ Map Grid:\n");
	while (game->map.grid[i])
	{
		printf("MAP[%d]: %s\n", i, game->map.grid[i]);
		i++;
	}
}

void render_game_with_minimap(t_game *game)
{
    render_map(game);
    render_minimap_corner(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
    {
        write (2, "Usage : ./cub3D <map.cub>\n", 27);
        return (1);
    }

    init_game(&game);
    
    if (parse_cub_file(av[1], &game) == 0)
    {
        write (2, "error parsing map\n", 19);
        return (1);
    }
    init_player_direction(&(game.player), game.dir);
    init_mlx(&game);
    setup_textures(&game);
    setup_weapon(&game);
    setup_sun(&game);
    mlx_loop_hook( game.mlx,render_map, &game);
    render_game_with_minimap(&game);
    mlx_hook(game.win, 2, 1L<<0, handle_keypress, &game);
    // mlx_hook(game.win, 6, 1L<<0, handle_mouse_move, &game);
    // mlx_mouse_hide();
    mlx_mouse_move(game.mlx,game.win,(int)game.win_width/2, (int)game.win_heigth/2);
    mlx_loop(game.mlx);
    return (0);
}
