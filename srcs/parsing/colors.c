/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:28:34 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:13:08 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	verify_colors(t_color *color, char **colors)
{
	if (!check_colors(colors))
	{
		print_error("Error\n");
		print_error("Invalid color format. Please use three \
		digits seperated by commas for the color \
		components (e.g., 'R,G,B').\n");
		return (WRONG_MAP);
	}
	color->red = ft_atoi(colors[0]);
	color->green = ft_atoi(colors[1]);
	color->blue = ft_atoi(colors[2]);
	if (!check_color(color))
	{
		print_error("Error\n");
		print_error("Color components must be between 0 \
and 255.\n");
		return (WRONG_MAP);
	}
	return (SUCCESS);
}

int	check_color_line(t_map_infos *map_infos, t_array *array)
{
	char	**colors;
	t_color	*color;

	if (array->length != 2)
	{
		print_error("Error\nPlease provide only the color identifier \
			and the color components.\n");
		return (WRONG_MAP);
	}
	if (ft_strcmp(array->strs[0], "F") == 0)
		color = &map_infos->floor_color;
	else if (ft_strcmp(array->strs[0], "C") == 0)
		color = &map_infos->ceiling_color;
	if (count_commas(array->strs[1]) != 2)
		return (print_error("Error\nWrong format color.\n"), WRONG_MAP);
	colors = ft_split(array->strs[1], ',');
	if (verify_colors(color, colors) == WRONG_MAP)
	{
		free_array(colors);
		return (WRONG_MAP);
	}
	free_array(colors);
	return (SUCCESS);
}

int	process_color_setting(t_map_infos *map_infos, t_array *array,
		int *parsed_flag, char *type)
{
	if (*parsed_flag)
	{
		print_error("Error\n");
		print_error("Same color: ");
		print_error(type);
		return (free_array(array->strs), WRONG_MAP);
	}
	else
	{
		if (check_color_line(map_infos, array) != SUCCESS)
			return (free_array(array->strs), WRONG_MAP);
		*parsed_flag = 1;
	}
	return (SUCCESS);
}
