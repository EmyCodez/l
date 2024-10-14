/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:29:02 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:13:30 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if ((int)start >= s_len)
		return (ft_strdup(""));
	if (start + len > (unsigned int)s_len)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	if ((int)start > (int)ft_strlen((char *)s))
		return ("\0");
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	arr_length(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (*str == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	length = nbr_len(n);
	if (!length)
		length++;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	str[length] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--length] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	rs;
	int		sg;

	i = 0;
	rs = 0;
	sg = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sg = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		rs = rs * 10 + str[i] - '0';
		if (rs * sg > 2147483648)
			return (-1);
		else if (rs * sg < -2147483648)
			return (0);
		i++;
	}
	return (rs * sg);
}
