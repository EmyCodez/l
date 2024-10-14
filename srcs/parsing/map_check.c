/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:07:07 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:13:46 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	all_elements_parsed(t_map_infos *map_infos)
{
	if (map_infos->no_path_parsed == 1 && map_infos->so_path_parsed == 1
		&& map_infos->we_path_parsed == 1 && map_infos->ea_path_parsed == 1
		&& map_infos->floor_color_parsed == 1
		&& map_infos->ceiling_color_parsed == 1)
		return (1);
	return (0);
}

int	open_map_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: Couldn't open file");
		return (-1);
	}
	return (fd);
}
