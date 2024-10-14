/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:46:00 by lps               #+#    #+#             */
/*   Updated: 2024/08/02 12:46:03 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memset(void *b, int n, size_t value)
{
	unsigned char	*bp;

	bp = (unsigned char *)b;
	while (value--)
	{
		*bp = (unsigned char)n;
		bp++;
	}
	return (b);
}
