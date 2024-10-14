/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:47:42 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:28:28 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
