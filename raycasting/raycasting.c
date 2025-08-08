#include "raycasting.h"


void draw_background(t_game *game)
{
    int x = 0;
    int y ;
    char *pixel;
    int color;

    while (x < game->win_width)
    {
        y = 0;
        while (y < game->win_heigth)
        {
            pixel = game->add + (y * game->line_length + x * (game->bits_per_pixel / 8));
            if (y < game->win_heigth/ 2)
            {
                color = game->ceiling_color;
            }
            else
                color = game->floor_color;
            y++;
            *(unsigned int*)pixel = color;
        }
        x++;
    }
}
void draw_vertical_line(t_game *game, int x, int start, int end, int color)
{
    int y;
    char *pixel;
    
    y = start;
    while (y <= end)
    {
        pixel = game->add + (y * game->line_length + x * (game->bits_per_pixel / 8));
        *(unsigned int*)pixel = color;
        y++;
    }
}

//fhad lfunction knxiftiw  supposson hna f2wl pixel so x =0 => camera = -1 . x= 800 => camera = 1 , x= 400(center) => camera = 0
//player.dir_x and player.dir_y present the center of the rar, plan are vertical to directions so ray_dir present where the ray will go accorrding to the camera and the value added or substructed

void calculate_ray_direction(t_game *game, int x, double *ray_dir_x, double *ray_dir_y)
{
    double camera_x;
    
    camera_x = 2 * x / (double)game->win_width - 1; 
    *ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
    *ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;
}
   
void perform_dda(t_game *game, double ray_dir_x, double ray_dir_y, int *map_x, int *map_y, int *side)
{
    double delta_dist_x;
    double delta_dist_y;
    double side_dist_x;
    double side_dist_y;
    int step_x;
    int step_y;
    int hit;

    hit = 0;
    *map_x = (int)game->player.x;
    *map_y = (int)game->player.y;
    delta_dist_x = fabs(1 / ray_dir_x);
    delta_dist_y = fabs(1 / ray_dir_y);
    if (ray_dir_x < 0)
    {
        step_x = -1;
        side_dist_x = (game->player.x - *map_x) * delta_dist_x;
    }
    else
    {
        step_x = 1;
        side_dist_x = (*map_x + 1.0 - game->player.x) * delta_dist_x;
    }
    
    if (ray_dir_y < 0)
    {
        step_y = -1;
        side_dist_y = (game->player.y - *map_y) * delta_dist_y;
    }
    else
    {
        step_y = 1;
        side_dist_y = (*map_y + 1.0 - game->player.y) * delta_dist_y;
    }
    while (hit == 0)
    {
        if (side_dist_x < side_dist_y)
        {
            side_dist_x += delta_dist_x;
            *map_x += step_x;
            *side = 0;
        }
        else
        {
            side_dist_y += delta_dist_y;
            *map_y += step_y;
            *side = 1;
        }
        if (game->map.grid[*map_y][*map_x] == '1')
            hit = 1;
    }
}

void calculate_wall_dimensions(t_game *game, double ray_dir_x, double ray_dir_y, 
                              int map_x, int map_y, int side, 
                              int *line_height, int *draw_start, int *draw_end)
{
    double perp_wall_dist;
    int step_x, step_y;

    step_x = (ray_dir_x < 0) ? -1 : 1;
    step_y = (ray_dir_y < 0) ? -1 : 1;
    if (side == 0)
        perp_wall_dist = (map_x - game->player.x + (1 - step_x) / 2) / ray_dir_x;
    else
        perp_wall_dist = (map_y - game->player.y + (1 - step_y) / 2) / ray_dir_y;
    *line_height = (int)(game->win_heigth / perp_wall_dist);
    *draw_start = -(*line_height) / 2 + game->win_heigth / 2;
    if (*draw_start < 0)
        *draw_start = 0;
    *draw_end = (*line_height) / 2 + game->win_heigth / 2;
    if (*draw_end >= game->win_heigth)
        *draw_end = game->win_heigth - 1;
}

void draw_wall_line(t_game *game,int x, int side, int draw_start, int draw_end)
{
    int color;

    if (side == 1)
        color = 0xFF0000;
    else
        color = 0x00FF00;
    draw_vertical_line(game, x, draw_start, draw_end, color);
}
void cast_rays(t_game *game, int x)
{
    double ray_dir_x;
    double ray_dir_y;
    int map_x;
    int map_y;
    int side;
    int line_height;
    int draw_start;
    int draw_end;

    calculate_ray_direction(game, x, &ray_dir_x, &ray_dir_y);
    perform_dda(game, ray_dir_x, ray_dir_y, &map_x, &map_y, &side);
    calculate_wall_dimensions(game, ray_dir_x, ray_dir_y, map_x, map_y, side, 
                             &line_height, &draw_start, &draw_end);
    draw_wall_line(game, x, side, draw_start, draw_end);
}