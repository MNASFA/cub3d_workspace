/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:06:16 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/21 14:11:59 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	set_player_orientation(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (dir == 'S')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (dir == 'E')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
}

int	get_row_length(char *row)
{
	int	len;

	len = ft_strlen(row);
	if (len > 0 && row[len - 1] == '\n')
		return (len - 1);
	return (len);
}

int	is_cell_accessible(char **grid, int height, int x, int y)
{
	int	row_len;

	if (y < 0 || y >= height || x < 0)
		return (1);
	row_len = get_row_length(grid[y]);
	if (x >= row_len)
		return (1);
	if (grid[y][x] == ' ')
		return (1);
	return (0);
}

int	check_map_enclosure(char **grid, int height, int x, int y)
{
	if (is_cell_accessible(grid, height, x, y - 1)
		|| is_cell_accessible(grid, height, x, y + 1)
		|| is_cell_accessible(grid, height, x - 1, y)
		|| is_cell_accessible(grid, height, x + 1, y))
		return (0);
	return (1);
}

void	set_player_data(t_game *game, char direction, int x, int y)
{
	game->dir = direction;
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	set_player_orientation(game, direction);
}
