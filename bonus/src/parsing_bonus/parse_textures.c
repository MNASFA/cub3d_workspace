/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:39:27 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/08/14 21:41:11 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d_bonus.h"

static char *extract_path(char *line)
{
    char *path;
    int len;
    
    line += 2;
    while (*line == ' ' || *line == '\t')
        line++;
    path = ft_strdup(line);
    if (!path)
        return (NULL);
    len = ft_strlen(path);
    if (len > 0 && path[len - 1] == '\n')
        path[len - 1] = '\0';
    return (path);
}

int parse_texture_line(char *line, t_game *game)
{
    char *path;

    if (ft_strncmp(line, "NO", 2) == 0)
    {
        if (game->no_parsed)
            return(print_error("Duplicate NO texture"), 0);
        path = extract_path(line);
        if (!path)
            return(print_error("invalid NO texture path"), 0);
        game->north.img = NULL;
        game->north.path = path;
        game->no_parsed = 1;
    }
    else if (ft_strncmp(line, "SO", 2) == 0)
    {
        if (game->so_parsed)
            return(print_error("Duplicate SO texture"), 0);
        path = extract_path(line);
        if (!path)
            return(print_error("invalid SO texture path"), 0);
        game->south.img = NULL;
        game->south.path = path;
        game->so_parsed = 1;
    }
    else if (ft_strncmp(line, "WE", 2) == 0)
    {
        if (game->we_parsed)
            return(print_error("Duplicate WE texture"), 0);
        path = extract_path(line);
        if (!path)
            return(print_error("invalid WE texture path"), 0);
        game->west.img = NULL;
        game->west.path = path;
        game->we_parsed = 1;
    }
    else if (ft_strncmp(line, "EA", 2) == 0)
    {
        if (game->ea_parsed)
            return(print_error("Duplicate EA texture"), 0);
        path = extract_path(line);
        if (!path)
            return(print_error("invalid EA texture path"), 0);
        game->east.img = NULL;
        game->east.path = path;
        game->ea_parsed = 1;
    }
    else
        return (print_error("makaynch hadchi"), 0);
    return (1);
}
