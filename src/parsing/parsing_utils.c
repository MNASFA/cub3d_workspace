/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:07:17 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/20 16:48:41 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || is_player(c));
}

int	is_walkable_parsing(char c)
{
	return (c == '0' || is_player(c));
}

int	is_on_border(int x, int y, int row_len, int height)
{
	return (y == 0 || y == height - 1 || x == 0 || x == row_len - 1);
}

int	is_valid_integer(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (1);
}
