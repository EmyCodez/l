/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:47:01 by lps               #+#    #+#             */
/*   Updated: 2024/08/02 12:47:03 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	num_words(const char *s, char seperator)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != seperator)
		{
			count++;
			while (s[i] && s[i] != seperator)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char seperator)
{
	char	**array;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	array = (char **)malloc(sizeof(char *) * (num_words(s, seperator) + 1));
	if (array == NULL)
		return (NULL);
	while (i < num_words(s, seperator))
	{
		while (s[start] == seperator)
			start++;
		end = start;
		while (s[end] != seperator && s[end])
			end++;
		array[i++] = ft_substr(s, start, end - start);
		start = end;
	}
	array[i] = NULL;
	return (array);
}
