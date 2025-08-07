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

    game->north.img = NULL;
    game->north.path = NULL;

    game->south.img = NULL;
    game->south.path = NULL;

    game->west.img = NULL;
    game->west.path = NULL;

    game->east.img = NULL;
    game->east.path = NULL;
    // parsing flags
    game->no_parsed = 0;
    game->so_parsed = 0;
    game->ea_parsed = 0;
    game->we_parsed = 0;
    game->f_parsed = 0;
	game->c_parsed = 0;
}

void init_player_direction(t_player *player, char spawn_dir)
{
    if (spawn_dir == 'N') {
        player->dir_x = 0.0;
        player->dir_y = -1.0;
        player->plane_x= 0.66;
        player->plane_y = 0.0;
    }
    else if (spawn_dir == 'S') {
        player->dir_x = 0.0;
        player->dir_y = 1.0;
        player->plane_x = -0.66;
        player->plane_y = 0.0;
    }
    else if (spawn_dir == 'E') {
        player->dir_x = 1.0;
        player->dir_y = 0.0;
        player->plane_x = 0.0;
        player->plane_y = 0.66;
    }
    else if (spawn_dir == 'W') {
        player->dir_x = -1.0;
        player->dir_y = 0.0;
        player->plane_x = 0.0;
        player->plane_y = -0.66;
    }
}
