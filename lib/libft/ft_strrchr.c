/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:49:27 by lps               #+#    #+#             */
/*   Updated: 2024/08/02 12:49:30 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (((char *)&s[i]));
		i--;
	}
	if (c == 0)
		return (((char *)&s[i]));
	return (NULL);
}
