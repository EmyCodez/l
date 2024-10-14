/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_and_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:29:33 by hankhali          #+#    #+#             */
/*   Updated: 2024/08/02 20:13:59 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_stack(t_stack *s)
{
	s->front = NULL;
	s->back = NULL;
}

void	append_2d_array(char **map, t_stack *stack, int *index, int columns)
{
	int		i;
	char	*old_row;
	char	*new_row;
	int		old_row_len;

	i = 0;
	old_row = remove_node(stack);
	old_row_len = ft_strlen(old_row);
	new_row = (char *)malloc(sizeof(char) * (columns + 1));
	while (i < old_row_len)
	{
		new_row[i] = old_row[i];
		i++;
	}
	while (i < columns)
		new_row[i++] = ' ';
	new_row[i] = '\0';
	map[*index] = new_row;
	(*index)++;
	ft_free((void **)&old_row);
}

void	*remove_node(t_stack *s)
{
	t_stack_node	*tmp;
	void			*val;

	if (!s->front)
		return (NULL);
	tmp = s->front;
	val = tmp->val;
	s->front = s->front->next;
	free(tmp);
	return (val);
}

void	convert_stack_to_2d_array(t_map *map, t_stack *stack)
{
	int	index;

	index = 0;
	map->rows = count_rows_in_stack(stack);
	map->cols = count_columns(stack);
	map->map_data = (char **)malloc(sizeof(char *) * (map->rows + 1));
	while (stack->front)
	{
		append_2d_array(map->map_data, stack, &index, map->cols);
	}
	map->map_data[map->rows] = NULL;
}

void	add_node(t_stack *s, void *val)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->val = val;
	new_node->next = NULL;
	if (!s->front)
	{
		s->front = new_node;
		s->back = new_node;
	}
	else
	{
		s->back->next = new_node;
		s->back = new_node;
	}
}
