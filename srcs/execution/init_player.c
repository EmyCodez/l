/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:51:41 by lps               #+#    #+#             */
/*   Updated: 2024/10/05 15:39:55 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	init_player_direction_east(t_data *data)
{
	while (data->player.dir_x < 1.0 && data->player.dir_y > 0)
	{
		rotate_right(data);
	}
}

static void	init_player_direction_west(t_data *data)
{
	while (data->player.dir_x > -1.0 || data->player.dir_y > 0.0)
	{
		rotate_left(data);
	}
}

static void	init_player_direction_north(t_data *data)
{
	while (data->player.dir_x > 0.0 || data->player.dir_y > -1.0)
	{
		rotate_left(data);
	}
}

void	init_player_direction(t_data *data, char dir)
{
	data->player.dir_x = 0;
	data->player.dir_y = 1;
	data->player.plane_x = 0.66;
	data->player.plane_y = 0;
	if (dir == 'E')
	{
		init_player_direction_east(data);
	}
	else if (dir == 'W')
	{
		init_player_direction_west(data);
	}
	else if (dir == 'N')
	{
		init_player_direction_north(data);
	}
}
