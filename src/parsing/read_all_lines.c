/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:15:17 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/09/18 15:15:18 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void free_lines(char **lines)
{
    int i;

    i = 0;
    if (!lines)
        return ;
    while (lines[i])
        free(lines[i++]);
    free(lines);
}

char **read_all_lines(int fd, int *line_count)
{
    char    **lines;
    char    *line;
    int     count;
    int     capacity;
    char    **new_lines;
    int     i;

    capacity = 64;
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
            new_lines = malloc(sizeof(char *) * capacity);
            if (!new_lines)
            {
                free(line);
                free_lines(lines);
                return (NULL);
            }
            i = 0;
            while (i < count)
            {
                new_lines[i] = lines[i];
                i++;
            }
            free(lines);
            lines = new_lines;
        }
        lines[count++] = line;
        line = get_next_line(fd);
    }
    lines[count] = NULL;
    *line_count = count;
    return (lines);
}
