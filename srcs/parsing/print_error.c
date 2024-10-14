/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:29:42 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:27:47 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	print_error(const char *error_message)
{
	write(2, error_message, ft_strlen(error_message));
}

void	error_message(const char *message)
{
	printf("%s", message);
}

int	print_missing_elements_error(t_map_infos *map_infos)
{
	print_error("Error\n");
	print_error("Invalid map file. \
The following elements are missing:\n");
	if (map_infos->no_path_parsed != 1)
		print_error("  - NO texture path\n");
	if (map_infos->so_path_parsed != 1)
		print_error("  - SO texture path\n");
	if (map_infos->we_path_parsed != 1)
		print_error("  - WE texture path\n");
	if (map_infos->ea_path_parsed != 1)
		print_error("  - EA texture path\n");
	if (map_infos->floor_color_parsed != 1)
		print_error("  - Floor color\n");
	if (map_infos->ceiling_color_parsed != 1)
		print_error("  - Ceiling color\n");
	return (WRONG_MAP);
}
