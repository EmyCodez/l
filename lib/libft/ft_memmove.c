/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:45:53 by lps               #+#    #+#             */
/*   Updated: 2024/08/02 12:45:56 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return ((void *)d);
}
