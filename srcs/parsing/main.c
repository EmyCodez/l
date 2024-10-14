/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:12:34 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:13:43 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_map_infos	map_infos;
	t_map		map;

	map_infos = (t_map_infos){0};
	map = (t_map){0};
	if (parse_arguments(argc, argv, &map_infos, &map) != SUCCESS)
	{
		free_2d_array(&map.map_data);
		free_map_info(&map_infos);
		return (1);
	}
	free_2d_array(&map.map_data);
	free_map_info(&map_infos);
	return (0);
}
