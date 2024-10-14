/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:28:28 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:13:14 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

int	verify_map_element(t_map *map, int i, int j)
{
	char	c;

	c = map->map_data[i][j];
	if (i == 0 || i == map->rows - 1 || j == 0 || j == map->cols - 1)
	{
		if (c != '1' && c != ' ')
		{
			print_error("Error\nmap is not enclosed by walls\n");
			return (0);
		}
	}
	else if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (!valid_sides(map, i, j))
		{
			print_error("Error\nInvalid placement\n");
			return (0);
		}
	}
	return (1);
}

int	valid_sides(t_map *map, int i, int j)
{
	if (map->map_data[i][j + 1] == ' ' || map->map_data[i][j - 1] == ' '
		|| map->map_data[i + 1][j] == ' ' || map->map_data[i - 1][j] == ' ')
		return (0);
	return (1);
}

int	is_valid_map(t_map *map)
{
	int	i;
	int	j;
	int	start_count;

	i = -1;
	start_count = 0;
	while (map->map_data[++i])
	{
		j = -1;
		while (map->map_data[i][++j])
		{
			if (!is_valid_map_char(map->map_data[i][j]))
			{
				return (print_error("Error\nInvalid character in map\n"), 0);
			}
			if (map->map_data[i][j] == 'N' || map->map_data[i][j] == 'S'
				|| map->map_data[i][j] == 'E' || map->map_data[i][j] == 'W')
				start_count++;
		}
	}
	if (start_count != 1)
		return (print_error("Error\nStarter position\n"), 0);
	return (is_map_enclosed(map));
}

int	is_map_enclosed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_data[i])
	{
		j = 0;
		while (map->map_data[i][j])
		{
			if (!verify_map_element(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
