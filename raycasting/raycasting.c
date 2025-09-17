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

void draw_wall_line_text(t_game *game, int x, int start, int end, int texture, int texture_x, int real_line_height)
{
    int y;
    char *pixel;
    t_texture text;
    char *addresse_color;
    int texture_y;
    double step;
    double tex_pos;

    if (texture == NORTH)
        text = game->north;
    else if(texture == EAST)
        text = game->east;
    else if (texture == WEST)
        text = game->west;
    else
        text = game->south;
    step = (double)text.height / (double)real_line_height;
    int wall_center = game->win_heigth / 2;
    int wall_start = wall_center - real_line_height / 2;
    tex_pos = (start - wall_start) * step;
    
    y = start;
    while (y <= end)
    {
        texture_y = (int)tex_pos;
        if (texture_y >= text.height) 
            texture_y = text.height - 1;
        if (texture_y < 0)
            texture_y = 0;
            
        addresse_color = text.add + (texture_y * text.line_height) + texture_x * (text.bits_per_pexel / 8);
        pixel = game->add + (y * game->line_length) + x * (game->bits_per_pixel / 8);
        *(unsigned int*)pixel = *(unsigned int *)addresse_color;
        
        tex_pos += step;
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
    double side_dist_x;//side_dist_x: Distance the ray needs to travel to reach the next vertical grid line
    double side_dist_y;//side_dist_y: Distance the ray needs to travel to reach the next horizontal grid line
    int step_x;
    int step_y;
    int hit;

    hit = 0;
    *map_x = (int)game->player.x;//will stockes the cordinate of the wall
    *map_y = (int)game->player.y;
    delta_dist_x = fabs(1 / ray_dir_x);//bax ray yzid b1 step x7al khasso fdistance
    delta_dist_y = fabs(1 / ray_dir_y);
    if (ray_dir_x < 0)
    {
        step_x = -1;
        side_dist_x = (game->player.x - *map_x) * delta_dist_x; //kn7ydo f2axmn gride kynin 7na db o kndrbo fdik delta bax nzido exactement bwa7d gride
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
                              int *line_height, int *draw_start, int *draw_end, double *texture_x)
{
    double perp_wall_dist;
    int step_x, step_y;
    double wall_x;

    step_x = (ray_dir_x < 0) ? -1 : 1;
    step_y = (ray_dir_y < 0) ? -1 : 1;
    if (side == 0)
        perp_wall_dist = (map_x - game->player.x + (1 - step_x) / 2) / ray_dir_x ;
    else
        perp_wall_dist = (map_y - game->player.y + (1 - step_y) / 2) / ray_dir_y ;//ray dir i s equalt to cos or sin alpha prep wall dest= distance traveled along the ray
    *line_height = (int)(game->win_heigth / perp_wall_dist);//dividing by prepwall gives the view when we are near and when we ar
    *draw_start = -(*line_height) / 2 + game->win_heigth / 2;
    if (*draw_start < 0)
        *draw_start = 0;
    if (perp_wall_dist < 0.1)
        perp_wall_dist = 0.1;
    *draw_end = (*line_height) / 2 + game->win_heigth / 2;
    if (*draw_end >= game->win_heigth)
        *draw_end = game->win_heigth - 1;
    if (side == 0)
        wall_x = game->player.y +  perp_wall_dist * ray_dir_y;
    else
        wall_x = game->player.x +  perp_wall_dist * ray_dir_x;
    wall_x = wall_x - floor(wall_x);
    *texture_x = (int)(wall_x * game->north.width);
    if (*texture_x >= game->north.width) 
        *texture_x = game->north.width - 1;
    if (*texture_x < 0)
        *texture_x = 0;

}

// void draw_wall_line(t_game *game,int x, int side, int draw_start, int draw_end)
// {
//     int color;

//     if (side == 1)
//         color = 0xFF0000;
//     else
//         color = 0x00FF00;
//     draw_vertical_line(game, x, draw_start, draw_end, color);
// }
int get_wall_direction(double ray_dir_x, double ray_dir_y, int side)
{
    if (side == 0)
    {
        if (ray_dir_x > 0)
            return EAST;
        else
            return WEST; 
    }
    else
    {
        if (ray_dir_y > 0)
            return SOUTH;
        else
            return NORTH;
    }
}

void setup_textures(t_game *game)
{
    game->east.img = mlx_xpm_file_to_image(game->mlx, "textures/east_wall.xpm", &game->east.width, &game->east.height);
    if (!game->east.img)
        return(printf("tnakt"), exit (3));
    game->east.add = mlx_get_data_addr(game->east.img, &game->east.bits_per_pexel, &game->east.line_height, &game->east.endian);
    game->north.img = mlx_xpm_file_to_image(game->mlx, "textures/north_wall.xpm", &game->north.width, &game->north.height);
    game->north.add = mlx_get_data_addr(game->north.img, &game->north.bits_per_pexel, &game->north.line_height, &game->north.endian);
    game->south.img = mlx_xpm_file_to_image(game->mlx, "textures/south_wall.xpm", &game->south.width, &game->south.height);
    game->south.add = mlx_get_data_addr(game->south.img, &game->south.bits_per_pexel, &game->south.line_height, &game->south.endian);
    game->west.img = mlx_xpm_file_to_image(game->mlx, "textures/west_wall.xpm", &game->west.width, &game->west.height);
    game->west.add = mlx_get_data_addr(game->west.img, &game->west.bits_per_pexel, &game->west.line_height, &game->west.endian);
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
    int text;
    double texture_x;

    calculate_ray_direction(game, x, &ray_dir_x, &ray_dir_y);
    perform_dda(game, ray_dir_x, ray_dir_y, &map_x, &map_y, &side);
    calculate_wall_dimensions(game, ray_dir_x, ray_dir_y, map_x, map_y, side, 
                             &line_height, &draw_start, &draw_end, &texture_x);
    text = get_wall_direction(ray_dir_x, ray_dir_y, side);
    draw_wall_line_text(game, x, draw_start, draw_end, text, texture_x, line_height);
}