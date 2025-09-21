/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:15:12 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/20 16:47:20 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	parse_no(char *line, t_game *game)
{
	char	*path;

	if (game->no_parsed)
		return (print_error("Duplicate NO texture"), 0);
	path = extract_path(line);
	if (path[0] == '\0')
		return (print_error("invalid NO texture path"), 0);
	game->north.img = NULL;
	game->north.path = path;
	game->no_parsed = 1;
	return (1);
}

static int	parse_so(char *line, t_game *game)
{
	char	*path;

	if (game->so_parsed)
		return (print_error("Duplicate SO texture"), 0);
	path = extract_path(line);
	if (path[0] == '\0')
		return (print_error("invalid SO texture path"), 0);
	game->south.img = NULL;
	game->south.path = path;
	game->so_parsed = 1;
	return (1);
}

static int	parse_we(char *line, t_game *game)
{
	char	*path;

	if (game->we_parsed)
		return (print_error("Duplicate WE texture"), 0);
	path = extract_path(line);
	if (path[0] == '\0')
		return (print_error("invalid WE texture path"), 0);
	game->west.img = NULL;
	game->west.path = path;
	game->we_parsed = 1;
	return (1);
}

static int	parse_ea(char *line, t_game *game)
{
	char	*path;

	if (game->ea_parsed)
		return (print_error("Duplicate EA texture"), 0);
	path = extract_path(line);
	if (path[0] == '\0')
		return (print_error("invalid EA texture path"), 0);
	game->east.img = NULL;
	game->east.path = path;
	game->ea_parsed = 1;
	return (1);
}

int	parse_texture_line(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (parse_no(line, game));
	if (ft_strncmp(line, "SO", 2) == 0)
		return (parse_so(line, game));
	if (ft_strncmp(line, "WE", 2) == 0)
		return (parse_we(line, game));
	if (ft_strncmp(line, "EA", 2) == 0)
		return (parse_ea(line, game));
	return (print_error("Invalid texture identifier"), 0);
}
