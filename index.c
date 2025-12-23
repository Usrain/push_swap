/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 05:47:54 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/23 05:48:47 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_first(t_stack *a)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = a->head;
	tmp2 = tmp;
	while (tmp)
	{
		if (tmp->value < tmp2->value)
			tmp2 = tmp;
		tmp = tmp->next;
	}
	return (tmp2);
}

static t_node	*get_last_unsorted(t_stack *a)
{
	t_node	*tmp;

	tmp = a->head;
	while (tmp)
	{
		if (tmp->index == -1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	fill_index(t_stack *a)
{
	int		last;
	t_node	*min;
	t_node	*current;
	int		i;

	min = get_first(a);
	min->index = 0;
	i = 1;
	while (i < a->size)
	{
		last = min->value;
		current = a->head;
		min = get_last_unsorted(a);
		if (!min)
			return ;
		while (current)
		{
			if (current->index == -1 && min->value > current->value
				&& last < current->value)
				min = current;
			current = current->next;
		}
		min->index = i;
		i++;
	}
}
