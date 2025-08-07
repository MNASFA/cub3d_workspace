#include "../cub3d.h"

void init_game(t_game *game)
{
    game->floor_color = -1;
    game->ceiling_color = -1;

    game->map.grid = NULL;
    game->map.width = 0;
    game->map.height = 0;
    game->map.player_count = 0;

    game->player.x = 0;
    game->player.y = 0;
    game->player.dir_x = 0;
    game->player.dir_y = 0;

    game->north.img = NULL;
    game->north.path = NULL;

    game->south.img = NULL;
    game->south.path = NULL;

    game->west.img = NULL;
    game->west.path = NULL;

    game->east.img = NULL;
    game->east.path = NULL;
    //camer
    game->player.plan_x = -0.66 * game->player.dir_x;
    game->player.plan_y = 0.66 * game->player.dir_y;
    // parsing flags
    game->no_parsed = 0;
    game->so_parsed = 0;
    game->ea_parsed = 0;
    game->we_parsed = 0;
    game->f_parsed = 0;
	game->c_parsed = 0;
}
