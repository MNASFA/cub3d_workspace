/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:15:07 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/18 15:15:08 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int get_map_width(char **lines, int start)
{
    int max;
    int len;

    max = 0;
    while (lines[start])
    {
        len = ft_strlen(lines[start]);
        if (len > max)
            max = len;
        start++;
    }
    return (max);
}

static int get_map_height(char **lines, int start)
{
    int count;

    count = 0;
    while (lines[start])
    {
        if (!is_empty_line(lines[start]))
            count++;
        start++;
    }
    return (count);
}

int parse_map(char **lines, int start, t_game *game)
{
    int height;
    int width;
    int i;

    height = get_map_height(lines, start);
    width = get_map_width(lines, start);
    i = 0;
    game->map.grid = malloc(sizeof(char *) * (height + 1));
    if (!game->map.grid)
        return(print_error("Memory allocation failed in map"), 0);
    
    while (lines[start] && i < height)
    {
        game->map.grid[i] = ft_strdup(lines[start]);
        if (!game->map.grid[i])
        {
            print_error("Memory allocation failed in map row");
            return (0);
        }
        i++;
        start++;
    }
    game->map.grid[i] = NULL;
    game->map.width = width - 1;
    game->map.height = height;
    game->win_width = 1024;
    game->win_heigth = 768;
    return (1);
}
