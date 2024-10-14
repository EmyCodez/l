/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:20:38 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:13:57 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*my_strjoin(char *string1, char *string2)
{
	char	*result;
	size_t	i;
	size_t	length1;
	size_t	length2;

	i = 0;
	if (!string1 || !string2)
		return (NULL);
	length1 = ft_strlen(string1);
	length2 = ft_strlen(string2);
	result = (char *)malloc((length1 + length2 + 1) * sizeof(char));
	while (i < length1)
	{
		result[i] = string1[i];
		i++;
	}
	i = 0;
	while (i < length2)
	{
		result[length1 + i] = string2[i];
		i++;
	}
	result[length1 + length2] = '\0';
	free(string1);
	return (result);
}

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\v'
			&& line[i] != '\f' && line[i] != '\r' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
