#include "../../cub3d.h"

// Convert a string to int and check range

static int parse_rgb(char *str, int *value)
{
    int num;

    num = ft_atoi(str);
    if (num < 0 || num > 255)
        return (0);
    *value = num;
    return (1); 
}

// extract rgb values from "255,255,255"

static int extract_rgb(char *str, int *r, int *g, int *b)
{
    char    **parts;
    int     count;

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

// Parse a color line and save it on t_game

int parse_color_line(char *line, t_game *game)
{
    char    *trimmed;
    int     r;
    int     g;
    int     b;

    while (*line == ' ' || *line == '\t')
        line++;
    
    if (*line == 'F')
    {
        if (game->f_parsed)
            return (print_error("Duplicate f color"), 0);
        trimmed = ft_strchr(line, ' ');
        if (!trimmed)
            return (print_error("Missing RGB values"), 0);
        trimmed++; // Skip the space
        if (!extract_rgb(trimmed, &r, &g, &b))
            return (print_error("Invalid floor color"), 0);
        game->floor_color = (r << 16) | (g << 8) | b; // Need to understand more
        game->f_parsed = 1;
    }
    else if (*line == 'C')
    {
        if (game->c_parsed)
            return (print_error("Duplicate C color"), 0);
        trimmed = ft_strchr(line, ' ');
        if (!trimmed || !extract_rgb(trimmed, &r, &g, &b))
            return (print_error("Invalid ceiling color"), 0);
        game->ceiling_color = (r << 16) | (g << 8) | b;
        game->c_parsed = 1;
    }
    else 
        return (print_error("hadchi rah makaynch"), 0);
    
    return (1);
}
