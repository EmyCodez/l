/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:59:37 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:13:36 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_map_infos(t_map_infos *map_info)
{
	map_info->no_path = NULL;
	map_info->so_path = NULL;
	map_info->we_path = NULL;
	map_info->ea_path = NULL;
	map_info->floor_color.red = 0;
	map_info->floor_color.green = 0;
	map_info->floor_color.blue = 0;
	map_info->ceiling_color.red = 0;
	map_info->ceiling_color.green = 0;
	map_info->ceiling_color.blue = 0;
	map_info->no_path_parsed = 0;
	map_info->so_path_parsed = 0;
	map_info->we_path_parsed = 0;
	map_info->ea_path_parsed = 0;
	map_info->floor_color_parsed = 0;
	map_info->ceiling_color_parsed = 0;
	map_info->rowlist = NULL;
}
