/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:56:23 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/21 19:38:38 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_game_with_minimap(t_game *game)
{
	render_map(game);
	render_minimap_corner(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		write (2, "Usage : ./cub3D <map.cub>\n", 27);
		return (1);
	}
	init_game(&game);
	init_key_states(&game);
	if (parse_cub_file(av[1], &game) == 0)
		return (1);
	init_player_direction(&(game.player), game.dir);
	init_mlx(&game);
	setup_textures(&game);
	setup_weapon(&game);
	setup_sun(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 3, 1L << 1, handle_keyrelease, &game);
	mlx_hook(game.win, 6, 1L << 6, handle_mouse_move, &game);
	mlx_mouse_hide(game.mlx, game.win);
	mlx_mouse_move(game.mlx, game.win, (int)game.win_width / 2,
		(int)game.win_heigth / 2);
	mlx_loop(game.mlx);
	return (0);
}
