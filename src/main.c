/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:56:23 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/08/20 22:25:24 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
    mlx_hook(game.win, 2, 1L<<0, handle_keypress, &game);
    mlx_loop(game.mlx);
    return (0);
}
