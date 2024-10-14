/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:49:22 by lps               #+#    #+#             */
/*   Updated: 2024/08/02 12:49:23 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	length;

	length = ft_strlen((char *)needle);
	if (!length)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	while (*haystack && len >= length)
	{
		if (!ft_memcmp(haystack, needle, length) && length <= len)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
