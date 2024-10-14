/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:44:14 by lps               #+#    #+#             */
/*   Updated: 2024/08/02 12:44:27 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (count && SIZE_MAX / count < size)
		return (NULL);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
