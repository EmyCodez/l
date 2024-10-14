/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esimpson <esimpson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:53:04 by lps               #+#    #+#             */
/*   Updated: 2024/09/30 16:10:36 by esimpson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	if (parse_arguments(argc, argv, &data.map_infos, &data.map) != SUCCESS)
	{
		free_2d_array(&data.map.map_data);
		free_map_infos(&data.map_infos);
		return (1);
	}
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"cub3D");
	data.image.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.image.address = mlx_get_data_addr(data.image.img,
			&data.image.bits_pixel, &data.image.line_length,
			&data.image.endian);
	run_game(&data);
	exit_game(&data);
}
