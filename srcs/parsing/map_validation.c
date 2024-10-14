/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:29:22 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:13:50 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

bool	read_map(int fd, t_map_infos *map_infos)
{
	char	*line;
	char	*map_line;

	line = get_next_line(fd);
	while (line)
	{
		map_line = ft_strtrim(line, " \t\v\f\r\n");
		ft_free((void **)&line);
		if (*map_line && parse_line(map_infos, map_line) != SUCCESS)
		{
			ft_free((void **)&map_line);
			close(fd);
			return (false);
		}
		ft_free((void **)&map_line);
		if (all_elements_parsed(map_infos))
			break ;
		line = get_next_line(fd);
	}
	return (true);
}

int	handle_color_line(t_map_infos *map_infos, t_array *array, int *parsed_flag,
		char *type)
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

int	parse_line(t_map_infos *map_infos, char *map_line)
{
	t_array	str_arr;

	str_arr.strs = ft_split(map_line, ' ');
	str_arr.length = arr_length(str_arr.strs);
	if (ft_strcmp(str_arr.strs[0], "NO") == 0)
		return (check_duplicates(map_infos, &str_arr,
				&map_infos->no_path_parsed, "NO"));
	else if (ft_strcmp(str_arr.strs[0], "SO") == 0)
		return (check_duplicates(map_infos, &str_arr,
				&map_infos->so_path_parsed, "SO"));
	else if (ft_strcmp(str_arr.strs[0], "WE") == 0)
		return (check_duplicates(map_infos, &str_arr,
				&map_infos->we_path_parsed, "WE"));
	else if (ft_strcmp(str_arr.strs[0], "EA") == 0)
		return (check_duplicates(map_infos, &str_arr,
				&map_infos->ea_path_parsed, "EA"));
	else if (ft_strcmp(str_arr.strs[0], "F") == 0)
		return (handle_color_line(map_infos, &str_arr,
				&map_infos->floor_color_parsed, "floor\n"));
	else if (ft_strcmp(str_arr.strs[0], "C") == 0)
		return (handle_color_line(map_infos, &str_arr,
				&map_infos->ceiling_color_parsed, "ceiling\n"));
	return (SUCCESS);
}

int	parse_texture_line(t_map_infos *map_infos, t_array *array)
{
	if (array->length != 2)
	{
		print_error("Error\n");
		print_error("Please provide only the texture \
			identifier and the path.\n");
		return (WRONG_MAP);
	}
	if (!check_texture(array->strs[1]))
	{
		print_error("Error\n");
		print_error("Please provide a valid file path for the texture.\n");
		return (WRONG_MAP);
	}
	if (ft_strcmp(array->strs[0], "NO") == 0)
		map_infos->no_path = ft_strdup(array->strs[1]);
	else if (ft_strcmp(array->strs[0], "SO") == 0)
		map_infos->so_path = ft_strdup(array->strs[1]);
	else if (ft_strcmp(array->strs[0], "WE") == 0)
		map_infos->we_path = ft_strdup(array->strs[1]);
	else if (ft_strcmp(array->strs[0], "EA") == 0)
		map_infos->ea_path = ft_strdup(array->strs[1]);
	return (SUCCESS);
}

int	check_duplicates(t_map_infos *map_infos, t_array *array, int *parsed_flag,
		char *type)
{
	if (*parsed_flag)
	{
		print_error("Error\n");
		print_error("Duplicate texture path: ");
		print_error(type);
		return (free_array(array->strs), WRONG_MAP);
	}
	else
	{
		if (parse_texture_line(map_infos, array) != SUCCESS)
			return (free_array(array->strs), WRONG_MAP);
		*parsed_flag = 1;
	}
	return (free_array(array->strs), SUCCESS);
}
