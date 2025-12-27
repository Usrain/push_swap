/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 04:34:58 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/27 19:06:21 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_unique_case(t_stack *a, t_stack *b, t_sort_cost *sort)
{
	if (sort->a.r)
	{
		ra(a);
		sort->a.amount--;
	}
	else if (sort->a.rr)
	{
		rra(a);
		sort->a.amount--;
	}
	else if (sort->b.r)
	{
		rb(b);
		sort->b.amount--;
	}
	else if (sort->b.rr)
	{
		rrb(b);
		sort->b.amount--;
	}
}

t_node	*get_max(t_stack *a)
{
	t_node	*temp;
	t_node	*max;

	temp = a->head;
	max = temp;
	while (temp)
	{
		if (temp->index > max-> index)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_node	*get_min(t_stack *a)
{
	t_node	*temp;
	t_node	*min;

	temp = a->head;
	min = temp;
	while (temp)
	{
		if (temp->index < min-> index)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

int	aldready_sorted(t_stack *a)
{
	int		intemp;
	t_node	*temp;

	temp = a->head;
	intemp = temp->index;
	while (temp)
	{
		if (temp->index >= intemp)
			intemp = temp->index;
		else
			return (0);
		temp = temp->next;
	}
	return (1);
}
