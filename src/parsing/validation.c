/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:35:37 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/21 14:30:05 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	validate_characters_and_player(t_game *game, int y)
{
	int		x;
	int		row_len;
	char	c;

	while (++y < game->map.height)
	{
		row_len = get_row_length(game->map.grid[y]);
		x = -1;
		while (++x < row_len)
		{
			c = game->map.grid[y][x];
			if (!is_valid_char(c))
				return (print_error("Invalid character in map"), 0);
			if (is_player(c))
			{
				game->map.player_count++;
				if (game->map.player_count > 1)
					return (print_error("Multiple player positions"), 0);
				set_player_data(game, c, x, y);
			}
		}
	}
	if (game->map.player_count != 1)
		return (print_error("Player start missing"), 0);
	return (1);
}

int	last_validation(t_game *game, int y)
{
	int		x;
	int		row_len;
	char	c;

	while (++y < game->map.height)
	{
		row_len = get_row_length(game->map.grid[y]);
		x = -1;
		while (++x < row_len)
		{
			c = game->map.grid[y][x];
			if (c == ' ')
				continue ;
			if (is_walkable_parsing(c))
			{
				if (!check_map_enclosure(game->map.grid,
						game->map.height, x, y))
					return (print_error("Map not enclosed by walls"), 0);
			}
		}
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!validate_characters_and_player(game, -1))
		return (0);
	if (!last_validation(game, -1))
		return (0);
	return (1);
}
