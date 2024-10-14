/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:28:49 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:13:25 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map_infos(t_map_infos *map_infos)
{
	ft_free((void **)&(map_infos->no_path));
	ft_free((void **)&(map_infos->so_path));
	ft_free((void **)&(map_infos->we_path));
	ft_free((void **)&(map_infos->ea_path));
	free_stack(&map_infos->stack);
}

void	free_stack(t_stack *s)
{
	t_stack_node	*tmp;

	if (!s)
		return ;
	while (s->front)
	{
		tmp = s->front;
		s->front = s->front->next;
		ft_free((void **)&(tmp->val));
		ft_free((void **)&tmp);
	}
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_2d_array(char ***map)
{
	int	i;

	i = 0;
	if (!map || !*map)
		return ;
	while ((*map)[i])
	{
		ft_free((void **)&((*map)[i]));
		i++;
	}
	ft_free((void **)map);
}

void	ft_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
