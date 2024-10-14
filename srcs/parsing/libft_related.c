/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_related.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:29:07 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:13:38 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

int	nbr_len(int n)
{
	int	len;

	if (n <= -2147483648)
	{
		len = 11;
		return (len);
	}
	len = 0;
	if (n < 0)
	{
		n *= -1;
		len += 1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srclen);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (srclen);
}
