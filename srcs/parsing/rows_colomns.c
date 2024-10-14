/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows_colomns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:29:45 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:14:17 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	count_rows_in_stack(t_stack *stack)
{
	int				i;
	t_stack_node	*tmp;

	i = 0;
	tmp = stack->front;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	count_columns(t_stack *stack)
{
	int				max;
	int				len;
	t_stack_node	*tmp;

	max = INT_MIN;
	tmp = stack->front;
	while (tmp)
	{
		len = ft_strlen(tmp->val);
		if (len > max)
			max = len;
		tmp = tmp->next;
	}
	return (max);
}
