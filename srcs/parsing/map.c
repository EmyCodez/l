/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:53:07 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:24:28 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_color(t_color *color)
{
	if (color->red < 0 || color->red > 255)
	{
		print_error("Error\nRed value out of range (0-255)\n");
		return (0);
	}
	if (color->green < 0 || color->green > 255)
	{
		print_error("Error\nGreen value out of range (0-255)\n");
		return (0);
	}
	if (color->blue < 0 || color->blue > 255)
	{
		print_error("Error\nBlue value out of range (0-255)\n");
		return (0);
	}
	return (1);
}

int	check_colors(char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		if (!is_number(colors[i]))
		{
			print_error("Error\nInvalid numeric value in color.\n");
			return (0);
		}
		i++;
	}
	if (i != 3)
	{
		print_error("Error\nColor format must have \
         exactly three components.\n");
		return (0);
	}
	return (1);
}

int	count_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	check_texture(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
