/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:45:47 by lps               #+#    #+#             */
/*   Updated: 2024/08/02 12:45:49 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
