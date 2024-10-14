/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:51:47 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:13:27 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*createemptystring(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	if (str != NULL)
		str[0] = '\0';
	return (str);
}

char	*read_line(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 2];
	int		bytes_read;
	int		newline_found;

	newline_found = 0;
	bytes_read = 1;
	if (str == NULL)
		str = createemptystring();
	while (!newline_found && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(str);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = my_strjoin(str, buffer);
		if (ft_strchr(str, '\n') != NULL)
			newline_found = 1;
	}
	return (str);
}

char	*skip_line(char *input_string)
{
	int		i;
	char	*remaining_string;

	i = 0;
	while (input_string[i] != '\0' && input_string[i] != '\n')
		i++;
	if (input_string[i] == '\0')
	{
		free(input_string);
		return (NULL);
	}
	remaining_string = ft_strdup(input_string + i + 1);
	free(input_string);
	return (remaining_string);
}

char	*extract_line(char *input_str)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	line = NULL;
	if (input_str == NULL || input_str[i] == '\0')
		return (NULL);
	while (input_str[i] != '\0' && input_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	j = 0;
	while (j < i)
	{
		line[j] = input_str[j];
		j++;
	}
	if (input_str[i] == '\n')
	{
		line[i] = input_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
	{
		return (NULL);
	}
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = skip_line(buffer);
	return (line);
}
