/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:46:05 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/20 16:36:33 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	has_consecutive_commas(char *str)
{
	int	i;

	i = 0;
	if (str[0] == ',' || str[ft_strlen(str) - 1] == ',')
		return (1);
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == ',')
			return (1);
		i++;
	}
	return (0);
}

static int	parse_rgb(char *str, int *value)
{
	int	num;

	if (!is_valid_integer(str))
		return (0);
	num = ft_atoi(str);
	if (num < 0 || num > 255)
		return (0);
	*value = num;
	return (1);
}

static int	extract_rgb(char *str, int *r, int *g, int *b)
{
	char	**parts;
	int		count;

	if (has_consecutive_commas(str))
		return (0);
	parts = ft_split(str, ',');
	if (!parts)
		return (0);
	count = 0;
	while (parts[count])
		count++;
	if (count != 3 || !parse_rgb(parts[0], r)
		|| !parse_rgb(parts[1], g)
		|| !parse_rgb(parts[2], b))
	{
		free_split(parts);
		return (0);
	}
	free_split(parts);
	return (1);
}

static int	set_color(char *line, int *parsed, int *color, char *err_msg)
{
	char	*trimmed;
	int		r;
	int		g;
	int		b;

	if (*parsed)
		return (print_error(err_msg), 0);
	trimmed = ft_strchr(line, ' ');
	if (!trimmed)
		return (print_error("Missing RGB values"), 0);
	trimmed++;
	if (!extract_rgb(trimmed, &r, &g, &b))
		return (print_error("Invalid color format"), 0);
	*color = (r << 16) | (g << 8 | b);
	*parsed = 1;
	return (1);
}

int	parse_color_line(char *line, t_game *game)
{
	char	*newline_pos;

	newline_pos = ft_strchr(line, '\n');
	if (newline_pos)
		*newline_pos = '\0';
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == 'F')
		return (set_color(line, &game->f_parsed,
				&game->floor_color, "Duplicate F color"));
	else if (*line == 'C')
		return (set_color(line, &game->c_parsed,
				&game->ceiling_color, "Duplicate C color"));
	return (0);
}
