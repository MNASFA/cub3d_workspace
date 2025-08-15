#include "../../cub3d.h"

int is_player(char c)
{
    return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void set_player_orientation(t_game *game, char dir)
{
    if (dir == 'N')
    {
        game->player.dir_x = 0;
        game->player.dir_y = -1;
    }
    else if (dir == 'S')
    {
        game->player.dir_x = 0;
        game->player.dir_y = 1;
    }
    else if (dir == 'E')
    {   
        game->player.dir_x = 1;
        game->player.dir_y = 0;
    }
    else if (dir == 'W')
    {
        game->player.dir_x = -1;
        game->player.dir_y = 0;
    }
}

int is_valid_position(char **grid, int height, int x, int y)
{
    if (y > 0)
    {
        if (x >= ft_strlen(grid[y - 1]) || grid[y - 1][x] == ' ')
            return (0); 
    }
    if (y < height - 1)
    {
        if (x >= ft_strlen(grid[y + 1]) || grid[y + 1][x] == ' ')
            return (0);
    }
    if (x > 0)
    {
        if (grid[y][x - 1] == ' ')
            return (0);
    }
    int current_len = ft_strlen(grid[y]);
    if (grid[y][current_len - 1] == '\n')
        current_len--;
    if (x < current_len - 1)
    {
        if (grid[y][x + 1] == ' ')
            return (0);
    }
    return (1);
}

int validate_map(t_game *game)
{
    int     x;
    int     y;
    int     height;
    char    **grid;
    char    c;

    grid = game->map.grid;
    height = game->map.height;
    game->map.player_count = 0;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (grid[y][x])
        {
            c = grid[y][x];
            if (c == ' ' || c == '\t' || c == '\n')
            {
                x++;
                continue;
            }
            else if (c == '0' || is_player(c))
            {  
                int row_len = ft_strlen(grid[y]);
                if (grid[y][row_len - 1] == '\n')
                    row_len--;
                if (y == 0 || y == height - 1 || x == 0 || x == row_len - 1)
                    return (print_error("Map not enclosed by walls"), 0);
                if (!is_valid_position(grid, height, x, y))
                    return(print_error("Map not enclosed prperly !"), 0);

                if ((y > 0 && x < ft_strlen(grid[y - 1]) && grid[y - 1][x] == ' ') ||
                    (y < height - 1 && x < ft_strlen(grid[y + 1]) && grid[y + 1][x] == ' ') ||
                    (x > 0 && grid[y][x - 1] == ' ') ||
                    (x < row_len - 1 && grid[y][x + 1] == ' '))
                    return (print_error("Map has spaces adjacent to walkable area"), 0);

                if (is_player(c))
                {
                    if (game->map.player_count == 1)
                        return (print_error("Multiple player positions"), 0);
                    game->dir = c;
                    game->player.x = x + 0.5;
                    game->player.y = y + 0.5;
                    set_player_orientation(game, c);
                    game->map.player_count++;
                }
            }
            else if (c != '1')
                return (print_error("Invalid character in map"), 0);
            x++;
        }
        y++;
    }
    if (game->map.player_count != 1)
            return(print_error("Player start missing"), 0);
    return (1);    
}
