/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:00:20 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/08/21 15:45:14 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"


void setup_sun(t_game *game)
{
    game->sun[0].img = mlx_xpm_file_to_image(game->mlx, "animation/s1.xpm", &game->sun[0].width, &game->sun[0].height);
    game->sun[0].add = mlx_get_data_addr(game->sun[0].img, &game->sun[0].bits_per_pixel, &game->sun[0].line_length, &game->sun[0].endian);
    game->sun[1].img = mlx_xpm_file_to_image(game->mlx, "animation/s2.xpm", &game->sun[1].width, &game->sun[1].height);
    game->sun[1].add = mlx_get_data_addr(game->sun[1].img, &game->sun[1].bits_per_pixel, &game->sun[1].line_length, &game->sun[1].endian);  
    game->sun[2].img = mlx_xpm_file_to_image(game->mlx, "animation/s3.xpm", &game->sun[2].width, &game->sun[2].height);
    game->sun[2].add = mlx_get_data_addr(game->sun[2].img, &game->sun[2].bits_per_pixel, &game->sun[2].line_length, &game->sun[2].endian);
    game->sun[3].img = mlx_xpm_file_to_image(game->mlx, "animation/s4.xpm", &game->sun[3].width, &game->sun[3].height);
    game->sun[3].add = mlx_get_data_addr(game->sun[3].img, &game->sun[3].bits_per_pixel, &game->sun[3].line_length, &game->sun[3].endian);
    game->sun[4].img = mlx_xpm_file_to_image(game->mlx, "animation/s5.xpm", &game->sun[4].width, &game->sun[4].height);
    game->sun[4].add = mlx_get_data_addr(game->sun[4].img, &game->sun[4].bits_per_pixel, &game->sun[4].line_length, &game->sun[4].endian);
    game->sun[5].img = mlx_xpm_file_to_image(game->mlx, "animation/s6.xpm", &game->sun[5].width, &game->sun[5].height);
    game->sun[5].add = mlx_get_data_addr(game->sun[5].img, &game->sun[5].bits_per_pixel, &game->sun[5].line_length, &game->sun[5].endian);
    game->sun[6].img = mlx_xpm_file_to_image(game->mlx, "animation/s7.xpm", &game->sun[6].width, &game->sun[6].height);
    game->sun[6].add = mlx_get_data_addr(game->sun[6].img, &game->sun[6].bits_per_pixel, &game->sun[6].line_length, &game->sun[6].endian);
    game->sun[7].img = mlx_xpm_file_to_image(game->mlx, "animation/s8.xpm", &game->sun[7].width, &game->sun[7].height);
    game->sun[7].add = mlx_get_data_addr(game->sun[7].img, &game->sun[7].bits_per_pixel, &game->sun[7].line_length, &game->sun[7].endian);
    game->sun[8].img = mlx_xpm_file_to_image(game->mlx, "animation/s9.xpm", &game->sun[8].width, &game->sun[8].height);
    game->sun[8].add = mlx_get_data_addr(game->sun[8].img, &game->sun[8].bits_per_pixel, &game->sun[8].line_length, &game->sun[8].endian);
    game->sun[9].img = mlx_xpm_file_to_image(game->mlx, "animation/s10.xpm", &game->sun[9].width, &game->sun[9].height);
    game->sun[9].add = mlx_get_data_addr(game->sun[9].img, &game->sun[9].bits_per_pixel, &game->sun[9].line_length, &game->sun[9].endian);
    game->sun[10].img = mlx_xpm_file_to_image(game->mlx, "animation/s11.xpm", &game->sun[10].width, &game->sun[10].height);
    game->sun[10].add = mlx_get_data_addr(game->sun[10].img, &game->sun[10].bits_per_pixel, &game->sun[10].line_length, &game->sun[10].endian);
    game->sun[11].img = mlx_xpm_file_to_image(game->mlx, "animation/s12.xpm", &game->sun[11].width, &game->sun[11].height);
    game->sun[11].add = mlx_get_data_addr(game->sun[11].img, &game->sun[11].bits_per_pixel, &game->sun[11].line_length, &game->sun[11].endian);
    game->sun[12].img = mlx_xpm_file_to_image(game->mlx, "animation/s13.xpm", &game->sun[12].width, &game->sun[12].height);
    game->sun[12].add = mlx_get_data_addr(game->sun[12].img, &game->sun[12].bits_per_pixel, &game->sun[12].line_length, &game->sun[12].endian);
    game->sun[13].img = mlx_xpm_file_to_image(game->mlx, "animation/s14.xpm", &game->sun[13].width, &game->sun[13].height);
    game->sun[13].add = mlx_get_data_addr(game->sun[13].img, &game->sun[13].bits_per_pixel, &game->sun[13].line_length, &game->sun[13].endian);
    game->sun[14].img = mlx_xpm_file_to_image(game->mlx, "animation/s15.xpm", &game->sun[14].width, &game->sun[14].height);
    game->sun[14].add = mlx_get_data_addr(game->sun[14].img, &game->sun[14].bits_per_pixel, &game->sun[14].line_length, &game->sun[14].endian);
    game->sun[15].img = mlx_xpm_file_to_image(game->mlx, "animation/s16.xpm", &game->sun[15].width, &game->sun[15].height);
    game->sun[15].add = mlx_get_data_addr(game->sun[15].img, &game->sun[15].bits_per_pixel, &game->sun[15].line_length, &game->sun[15].endian);
    game->sun[16].img = mlx_xpm_file_to_image(game->mlx, "animation/s17.xpm", &game->sun[16].width, &game->sun[16].height);
    game->sun[16].add = mlx_get_data_addr(game->sun[16].img, &game->sun[16].bits_per_pixel, &game->sun[16].line_length, &game->sun[16].endian);
    game->sun[17].img = mlx_xpm_file_to_image(game->mlx, "animation/s18.xpm", &game->sun[17].width, &game->sun[17].height);
    game->sun[17].add = mlx_get_data_addr(game->sun[17].img, &game->sun[17].bits_per_pixel, &game->sun[17].line_length, &game->sun[17].endian);
    game->sun[18].img = mlx_xpm_file_to_image(game->mlx, "animation/s19.xpm", &game->sun[18].width, &game->sun[18].height);
    game->sun[18].add = mlx_get_data_addr(game->sun[18].img, &game->sun[18].bits_per_pixel, &game->sun[18].line_length, &game->sun[18].endian);
    game->sun[19].img = mlx_xpm_file_to_image(game->mlx, "animation/s20.xpm", &game->sun[19].width, &game->sun[19].height);
    game->sun[19].add = mlx_get_data_addr(game->sun[19].img, &game->sun[19].bits_per_pixel, &game->sun[19].line_length, &game->sun[19].endian);
    game->sun[20].img = mlx_xpm_file_to_image(game->mlx, "animation/s21.xpm", &game->sun[20].width, &game->sun[20].height);
    game->sun[20].add = mlx_get_data_addr(game->sun[20].img, &game->sun[20].bits_per_pixel, &game->sun[20].line_length, &game->sun[20].endian);
    game->sun[21].img = mlx_xpm_file_to_image(game->mlx, "animation/s22.xpm", &game->sun[21].width, &game->sun[21].height);
    game->sun[21].add = mlx_get_data_addr(game->sun[21].img, &game->sun[21].bits_per_pixel, &game->sun[21].line_length, &game->sun[21].endian);
    game->sun[22].img = mlx_xpm_file_to_image(game->mlx, "animation/s23.xpm", &game->sun[22].width, &game->sun[22].height);
    game->sun[22].add = mlx_get_data_addr(game->sun[22].img, &game->sun[22].bits_per_pixel, &game->sun[22].line_length, &game->sun[22].endian);
    game->sun[23].img = mlx_xpm_file_to_image(game->mlx, "animation/s24.xpm", &game->sun[23].width, &game->sun[23].height);
    game->sun[23].add = mlx_get_data_addr(game->sun[23].img, &game->sun[23].bits_per_pixel, &game->sun[23].line_length, &game->sun[23].endian);
    game->sun[24].img = mlx_xpm_file_to_image(game->mlx, "animation/s25.xpm", &game->sun[24].width, &game->sun[24].height);
    game->sun[24].add = mlx_get_data_addr(game->sun[24].img, &game->sun[24].bits_per_pixel, &game->sun[24].line_length, &game->sun[24].endian);
    game->sun[25].img = mlx_xpm_file_to_image(game->mlx, "animation/s26.xpm", &game->sun[25].width, &game->sun[25].height);
    game->sun[25].add = mlx_get_data_addr(game->sun[25].img, &game->sun[25].bits_per_pixel, &game->sun[25].line_length, &game->sun[25].endian);
    game->sun[26].img = mlx_xpm_file_to_image(game->mlx, "animation/s27.xpm", &game->sun[26].width, &game->sun[26].height);
    game->sun[26].add = mlx_get_data_addr(game->sun[26].img, &game->sun[26].bits_per_pixel, &game->sun[26].line_length, &game->sun[26].endian);
    game->sun[27].img = mlx_xpm_file_to_image(game->mlx, "animation/s28.xpm", &game->sun[27].width, &game->sun[27].height);
    game->sun[27].add = mlx_get_data_addr(game->sun[27].img, &game->sun[27].bits_per_pixel, &game->sun[27].line_length, &game->sun[27].endian);
    game->sun[28].img = mlx_xpm_file_to_image(game->mlx, "animation/s29.xpm", &game->sun[28].width, &game->sun[28].height);
    game->sun[28].add = mlx_get_data_addr(game->sun[28].img, &game->sun[28].bits_per_pixel, &game->sun[28].line_length, &game->sun[28].endian);
    game->sun[29].img = mlx_xpm_file_to_image(game->mlx, "animation/s30.xpm", &game->sun[29].width, &game->sun[29].height);
    game->sun[29].add = mlx_get_data_addr(game->sun[29].img, &game->sun[29].bits_per_pixel, &game->sun[29].line_length, &game->sun[29].endian);
    game->sun[30].img = mlx_xpm_file_to_image(game->mlx, "animation/s31.xpm", &game->sun[30].width, &game->sun[30].height);
    game->sun[30].add = mlx_get_data_addr(game->sun[30].img, &game->sun[30].bits_per_pixel, &game->sun[30].line_length, &game->sun[30].endian);
    game->sun[31].img = mlx_xpm_file_to_image(game->mlx, "animation/s32.xpm", &game->sun[31].width, &game->sun[31].height);
    game->sun[31].add = mlx_get_data_addr(game->sun[31].img, &game->sun[31].bits_per_pixel, &game->sun[31].line_length, &game->sun[31].endian);
    game->sun[32].img = mlx_xpm_file_to_image(game->mlx, "animation/s33.xpm", &game->sun[32].width, &game->sun[32].height);  
    game->sun[32].add = mlx_get_data_addr(game->sun[32].img, &game->sun[32].bits_per_pixel, &game->sun[32].line_length, &game->sun[32].endian);
    game->sun[33].img = mlx_xpm_file_to_image(game->mlx, "animation/s34.xpm", &game->sun[33].width, &game->sun[33].height);
    game->sun[33].add = mlx_get_data_addr(game->sun[33].img, &game->sun[33].bits_per_pixel, &game->sun[33].line_length, &game->sun[33].endian);
    game->sun[34].img = mlx_xpm_file_to_image(game->mlx, "animation/s35.xpm", &game->sun[34].width, &game->sun[34].height);
    game->sun[34].add = mlx_get_data_addr(game->sun[34].img, &game->sun[34].bits_per_pixel, &game->sun[34].line_length, &game->sun[34].endian);
    game->sun[35].img = mlx_xpm_file_to_image(game->mlx, "animation/s36.xpm", &game->sun[35].width, &game->sun[35].height);
    game->sun[35].add = mlx_get_data_addr(game->sun[35].img, &game->sun[35].bits_per_pixel, &game->sun[35].line_length, &game->sun[35].endian);
    game->sun[36].img = mlx_xpm_file_to_image(game->mlx, "animation/s37.xpm", &game->sun[36].width, &game->sun[36].height);
    game->sun[36].add = mlx_get_data_addr(game->sun[36].img, &game->sun[36].bits_per_pixel, &game->sun[36].line_length, &game->sun[36].endian);
    game->sun[37].img = mlx_xpm_file_to_image(game->mlx, "animation/s38.xpm", &game->sun[37].width, &game->sun[37].height);
    game->sun[37].add = mlx_get_data_addr(game->sun[37].img, &game->sun[37].bits_per_pixel, &game->sun[37].line_length, &game->sun[37].endian);
    game->sun[38].img = mlx_xpm_file_to_image(game->mlx, "animation/s39.xpm", &game->sun[38].width, &game->sun[38].height);
    game->sun[38].add = mlx_get_data_addr(game->sun[38].img, &game->sun[38].bits_per_pixel, &game->sun[38].line_length, &game->sun[38].endian);
    game->sun[39].img = mlx_xpm_file_to_image(game->mlx, "animation/s40.xpm", &game->sun[39].width, &game->sun[39].height);
    game->sun[39].add = mlx_get_data_addr(game->sun[39].img, &game->sun[39].bits_per_pixel, &game->sun[39].line_length, &game->sun[39].endian);
    game->sun[40].img = mlx_xpm_file_to_image(game->mlx, "animation/s41.xpm", &game->sun[40].width, &game->sun[40].height);
    game->sun[40].add = mlx_get_data_addr(game->sun[40].img, &game->sun[40].bits_per_pixel, &game->sun[40].line_length, &game->sun[40].endian);
    game->sun[41].img = mlx_xpm_file_to_image(game->mlx, "animation/s42.xpm", &game->sun[41].width, &game->sun[41].height);
    game->sun[41].add = mlx_get_data_addr(game->sun[41].img, &game->sun[41].bits_per_pixel, &game->sun[41].line_length, &game->sun[41].endian);
    game->sun[42].img = mlx_xpm_file_to_image(game->mlx, "animation/s43.xpm", &game->sun[42].width, &game->sun[42].height);    
    game->sun[42].add = mlx_get_data_addr(game->sun[42].img, &game->sun[42].bits_per_pixel, &game->sun[42].line_length, &game->sun[42].endian);
    game->sun[43].img = mlx_xpm_file_to_image(game->mlx, "animation/s44.xpm", &game->sun[43].width, &game->sun[43].height);
    game->sun[43].add = mlx_get_data_addr(game->sun[43].img, &game->sun[43].bits_per_pixel, &game->sun[43].line_length, &game->sun[43].endian);
    game->sun[44].img = mlx_xpm_file_to_image(game->mlx, "animation/s45.xpm", &game->sun[44].width, &game->sun[44].height);
    game->sun[44].add = mlx_get_data_addr(game->sun[44].img, &game->sun[44].bits_per_pixel, &game->sun[44].line_length, &game->sun[44].endian);
    // for(int i = 0; i < 45; i++)
    // {
    //     printf("num: %d; height: %d, width: %d\n",i + 1, game->sun[i].height, game->sun[i].width);
    // }
}


void draw_sun_frame(t_game *game, int frame)
{
    int texture_x;
    int texture_y;
    int x, y;
    char *pixel;
    char *address_color;

    // top center
    int start_x = game->win_width / 2 - game->sun[frame].width / 2 - 300;
    int start_y = -100;

    texture_x = 0;
    while (texture_x < game->sun[frame].width)
    {
        texture_y = 0;
        while (texture_y < game->sun[frame].height)
        {
            x = start_x + texture_x;
            y = start_y + texture_y;
            if (x >= 0 && x < game->win_width && y >= 0 && y < game->win_heigth)
            {
                pixel = game->add + (y * game->line_length + x * (game->bits_per_pixel / 8));
                address_color = game->sun[frame].add +
                    (texture_y * game->sun[frame].line_length +
                     texture_x * (game->sun[frame].bits_per_pixel / 8));

                if (*(unsigned int*)address_color != 0xff000000 && *(unsigned int*)address_color != 0)
                {
                    *(unsigned int*)pixel = *(unsigned int*)address_color;
                }
            }
            texture_y++;
        }
        texture_x++;
    }
}


void draw_sun(t_game *game)
{
    if(game->sun_frame < 44)
    {
        draw_sun_frame(game, game->sun_frame);
        game->sun_frame++;
    }
    else
    {
        game->sun_frame = 0;
         draw_sun_frame(game, game->sun_frame);
    }
}