/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:14:33 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/21 11:58:39 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	check_identifiers(t_game *game)
{
	if (!game->no_parsed || !game->so_parsed || !game->we_parsed
		|| !game->ea_parsed || !game->f_parsed || !game->c_parsed)
	{
		print_error("Missing texture or color before map");
		return (0);
	}
	return (1);
}

int	process_line(char *line, t_game *game, int *map_started)
{
	if (is_empty_line(line))
		return (1);
	if (*map_started)
	{
		if (!is_map_line(line))
		{
			print_error("Invalid line after map has started");
			return (0);
		}
		return (1);
	}
	if (is_texture_line(line))
		return (parse_texture_line(line, game));
	if (is_color_line(line))
		return (parse_color_line(line, game));
	if (is_map_line(line))
	{
		if (!check_identifiers(game))
			return (0);
		*map_started = 1;
		return (1);
	}
	print_error("Invalid line in .cub file");
	return (0);
}

static char	**load_lines(char *filename, int *line_count)
{
	int		fd;
	char	**lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("open file failed !!"), NULL);
	lines = read_all_lines(fd, line_count, 64);
	close(fd);
	if (!lines)
		print_error("Error reading file");
	return (lines);
}

static int	check_header(char **lines, t_game *game)
{
	int	i;
	int	map_started;

	i = 0;
	map_started = 0;
	while (lines[i])
	{
		if (!process_line(lines[i], game, &map_started))
			return (0);
		i++;
	}
	return (1);
}

int	parse_cub_file(char *filename, t_game *game)
{
	char	**lines;
	int		line_count;
	int		map_start;

	lines = load_lines(filename, &line_count);
	if (!lines)
		return (0);
	if (!check_header(lines, game))
		return (free_lines(lines), 0);
	map_start = find_map_start(lines);
	if (map_start == -1)
		return (print_error("No valid map found"), free_lines(lines), 0);
	if (!parse_map(lines, map_start, game))
		return (free_lines(lines), 0);
	if (!validate_map(game))
		return (free_lines(lines), 0);
	free_lines(lines);
	return (1);
}
