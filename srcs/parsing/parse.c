/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:37:15 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:14:08 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	verify_arguments(int ac, char **av)
{
	if (ac != 2)
	{
		error_message("Error: wrong number of arguments\n");
		return (INVALID_ARG);
	}
	if (ft_strlen(av[1]) < 5 || ft_strcmp(av[1] + ft_strlen(av[1]) - 4,
			".cub") != 0)
	{
		error_message("Error: Wrong file extension\n");
		return (INVALID_ARG);
	}
	return (SUCCESS);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s1);
	while (i < j && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	if (i >= j)
		return (ft_strdup(""));
	return (ft_substr(s1, i, (j - i)));
}

void	parse_map_to_stack(int fd, t_stack *q)
{
	char	*line;

	init_stack(q);
	line = get_next_line(fd);
	while (line && is_empty_line(line))
	{
		ft_free((void **)&line);
		line = get_next_line(fd);
	}
	while (line && !is_empty_line(line))
	{
		add_node(q, ft_strtrim(line, "\n"));
		ft_free((void **)&line);
		line = get_next_line(fd);
	}
	ft_free((void **)&line);
}

int	parse_map(char *file_name, t_map_infos *map_infos)
{
	int		fd;
	char	*line;

	fd = open_map_file(file_name);
	if (fd == -1)
		return (print_error("Error\nCould not open file\n"), OPEN_ERR);
	if (read_map(fd, map_infos) == false)
		return (WRONG_MAP);
	if (!all_elements_parsed(map_infos))
		return (close(fd), print_missing_elements_error(map_infos));
	parse_map_to_stack(fd, &map_infos->stack);
	line = get_next_line(fd);
	while (line && is_empty_line(line))
	{
		ft_free((void **)&line);
		line = get_next_line(fd);
	}
	if (line && !is_empty_line(line))
	{
		printf("Error\nInvalid map, found line after map\n");
		free(line);
		return (close(fd), WRONG_MAP);
	}
	return (close(fd), SUCCESS);
}

int	parse_arguments(int argc, char **argv, t_map_infos *map_info, t_map *map)
{
	int	ret;

	if (verify_arguments(argc, argv) != SUCCESS)
		return (INVALID_ARG);
	ret = parse_map(argv[1], map_info);
	if (ret == SUCCESS)
	{
		convert_stack_to_2d_array(map, &map_info->stack);
		if (!is_valid_map(map))
			return (WRONG_MAP);
	}
	return (ret);
}
