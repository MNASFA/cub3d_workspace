/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:56:23 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/07/15 13:56:24 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
    {
        write (2, "Usage : ./cub3D <map.cub>\n", 27);
        return (1);
    }

    init_game(&game);

    if (parse_cub_file(av[1], &game) == 0)
    {
        write (2, "error parsing map\n", 19);
        return (1);
    }
    return (0);
}
