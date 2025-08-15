/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:39:09 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/08/14 21:39:15 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

int	is_map_line(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
    while (line[i])
    {
        if (line[i] != '0' && line[i] != '1' && line[i] != 'N' &&
            line[i] != 'S' && line[i] != 'E' && line[i] != 'W' &&
            line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return (0);
        i++;
    }
	return (1);
}

int	find_map_start(char **lines)
{
	int	i = 0;

	while (lines[i])
	{
		if (is_map_line(lines[i]) && !is_empty_line(lines[i]))
			return (i); // This is where map starts
		i++;
	}
	return (-1); // No map found
}

int process_line(char *line, t_game *game, int *map_started)
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

    if (is_map_line(line))
	{
		if (!game->no_parsed || !game->so_parsed || !game->we_parsed ||
			!game->ea_parsed || !game->f_parsed || !game->c_parsed)
		{
			print_error("Missing texture or color before map");
			return (0);
		}
		*map_started = 1;
		return (1);
	}

	if (is_texture_line(line))
		return (parse_texture_line(line, game));

	if (is_color_line(line))
		return (parse_color_line(line, game));

	print_error("Invalid line in .cub file");
	return (0);
}

int parse_cub_file(char *filename, t_game *game)
{
    int     fd;
    char    **lines;
    int     line_count;
    int     map_started;
    int     i;
    int     map_start;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("open file failed !!");
        return (0);
    }

    lines = read_all_lines(fd, &line_count);
    close(fd);
    if (!lines)
    {
        print_error("Error reading file");
        return (0);
    }

    map_started = 0;
    i = 0;
    while (lines[i] && !map_started)
    {
        if (!process_line(lines[i], game, &map_started))
        {
            free_lines(lines);
            return (0);
        }
        i++;
    }
    
	map_start = find_map_start(lines);
	if (map_start == -1)
	{
		print_error("No valid map found");
		free_lines(lines);
		return (0);
	}

	if (!parse_map(lines, map_start, game))
	{
		free_lines(lines);
		return (0);
	}

	if (!validate_map(game))
	{
		free_lines(lines);
		return (0);
	}

	// Cleanup and success
	free_lines(lines);
	printf("File parsed successfully!\n");
	printf("Map size: %dx%d\n", game->map.width, game->map.height);
	printf("Player at: (%.1f, %.1f)\n", game->player.x, game->player.y);
	return (1); 
}
