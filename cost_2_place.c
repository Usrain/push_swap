/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_2_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:58:54 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/14 18:20:25 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*place_after(t_stack *a, int value)
{
	t_node	*maxedmin;
	t_node	*temp;

	temp = (a->head);
	maxedmin = NULL;
	while (temp)
	{
		if (!maxedmin && temp->index < value)
			maxedmin = temp;
		if (maxedmin && temp->index > maxedmin->index && temp->index < value)
			maxedmin = temp;
		temp = temp->next;
	}
	return (maxedmin);
}

static t_sorter todoinb(t_stack *b, int value)
{
	int			i;
	t_sorter	result;
	t_node		*temp;

	temp = b->head;
	i = 0;
	if (temp->index == value)
	{
		result.r = 0;
		result.rr = 0;
		result.amount = 0;
		return (result);
	}
	while (temp && temp->index != value)
	{
		temp = temp->next;
		i++;
	}
	result.rr = (i <= b->size / 2);
	result.r = (i > b->size / 2);
	result.amount = i * result.r + (b->size - i) * result.rr;
	return (result); 
}

static t_sorter	todoina(t_stack *a, int value, t_node *placeafter)
{
	t_node *temp;
	t_sorter	result;
	int		i;

	if (!placeafter)
	{
		result.r = 0;
		result.rr = 0;
		result.amount = 0;
		return (result);
	}
	temp = a->head;
	i = 0;
	while (temp != placeafter)
	{
		i++;
		temp = temp->next;
	}
	result.rr = (i <= a->size / 2);
	result.r = (i > a->size / 2);
	result.amount = i * result.r + (a->size - i) * result.rr;
	return (result);
}

static int	get_total_cost(t_sorter a, t_sorter b)
{
	if (a.r == 0 && a.rr == 0)
		return (b.amount + 1);
	if (b.r == 0 && b.rr ==0)
		return (a.amount + 1);
	if ((a.r == 1 && b.rr == 1) || (a.rr == 1 && b.r == 1))
		return (a.amount + b.amount + 1);
	if (a.amount > b.amount)
	{
		return (a.amount + 1);
	}
	else
	{
		return (b.amount + 1);
	}
}

t_sort_cost	get_sort_cost(t_stack *a, t_stack *b, t_node *tosort)
{
	t_sort_cost total;

	total.a = todoina(a, tosort->index, place_after(a, tosort->index));
	total.b = todoinb(b, tosort->index);
	total.totalcost = get_total_cost(total.a, total.b);
	printf("valeur : %d, set to sort it : %d \n", tosort->value, total.totalcost);
	return (total);
}
