/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:15:17 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/20 16:49:58 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	if (!lines)
		return ;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}

static char	**resize_lines(char **lines, int count, int new_capacity)
{
	char	**new_lines;
	int		i;

	new_lines = malloc(sizeof(char *) * new_capacity);
	if (!new_lines)
		return (NULL);
	i = 0;
	while (i < count)
	{
		new_lines[i] = lines[i];
		i++;
	}
	free(lines);
	return (new_lines);
}

char	**read_all_lines(int fd, int *line_count, int capacity)
{
	char	**lines;
	char	*line;
	int		count;

	lines = malloc(sizeof(char *) * capacity);
	if (!lines)
		return (NULL);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (count >= capacity - 1)
		{
			capacity *= 2;
			lines = resize_lines(lines, count, capacity);
			if (!lines)
				return (free(line), NULL);
		}
		lines[count++] = line;
		line = get_next_line(fd);
	}
	lines[count] = NULL;
	*line_count = count;
	return (lines);
}
