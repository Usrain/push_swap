/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 14:49:24 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/31 15:50:30 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a, t_stack *b, int doend, int top)
{
	int	bot;
	int	mid;

	mid = a->head->next->value;
	bot = a->head->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
	if (doend == 1)
		end(0, a, b);
}

static void	sort_btwo(t_stack *a, t_stack *stack)
{
	if (stack->head->value < stack->head->next->value)
		rb(stack);
	pa(a, stack);
	pa(a, stack);
}

static t_node	*get_presmallest(t_stack *a, t_node *min)
{
	t_node	*temp;
	t_node	*result;

	if (a->head == min)
		temp = a->head->next;
	else
		temp = a->head;
	result = temp;
	while (temp)
	{
		if (temp->value < result-> value && temp != min)
			result = temp;
		temp = temp->next;
	}
	return (result);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	t_node	*smallest;
	t_node	*presmallest;
	t_node	*temp;

	temp = a->head;
	smallest = a->head;
	while (temp)
	{
		if (smallest->value > temp->value)
			smallest = temp;
		temp = temp->next;
	}
	presmallest = get_presmallest(a, smallest);
	while (a->size != 3)
	{
		if (a->head == smallest || a->head == presmallest)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a, b, 0, a->head->value);
	sort_btwo(a, b);
	end(0, a, b);
}

void	handle_small_size(t_stack *a, t_stack *b)
{
	if (a->size == 5)
		sort_five(a, b);
	if (a->size == 3)
		sort_three(a, b, 1, a->head->value);
}
