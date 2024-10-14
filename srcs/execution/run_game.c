/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:52:23 by lps               #+#    #+#             */
/*   Updated: 2024/08/02 12:52:26 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ray_info(t_ray *ray, t_player *player)
{
	ray->map_x = player->pos_x;
	ray->map_y = player->pos_y;
	ray->delta_x = fabs(1 / ray->raydir_x);
	ray->delta_y = fabs(1 / ray->raydir_y);
}

unsigned int	color_to_hex(t_color color)
{
	return ((color.red << 16) | (color.green << 8) | color.blue);
}

void	run_game(t_data *data)
{
	data_info(data);
	cast_rays(data, &data->player);
	mlx_hook(data->window, 2, 0, &on_keypress, data);
	mlx_hook(data->window, 3, 0, &on_keyrelease, data);
	mlx_hook(data->window, 17, 1L << 17, &exit_game, data);
	mlx_loop_hook(data->mlx, &hook_loop, data);
	mlx_loop(data->mlx);
}
