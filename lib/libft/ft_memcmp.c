/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:45:38 by lps               #+#    #+#             */
/*   Updated: 2024/08/02 12:45:40 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*first;
	const unsigned char	*second;

	first = s1;
	second = s2;
	while (n--)
	{
		if (*first != *second)
			return (*first - *second);
		first++;
		second++;
	}
	return (0);
}
