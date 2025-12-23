/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:54:30 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/23 02:13:16 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	arbr(t_stack *a, t_stack *b, t_sort_cost *sort)
{
	if (sort->a.amount > 0 && sort->b.amount > 0)
	{
		rr(a, b);
		sort->a.amount--;
		sort->b.amount--;
	}
	else if (sort->a.amount > 0)
	{
		ra(a);
		sort->a.amount--;
	}
	else
	{
		rb(b);
		sort->b.amount--;
	}
}

static void	arrbrr(t_stack *a, t_stack *b, t_sort_cost *sort)
{
	if (sort->a.amount > 0 && sort->b.amount > 0)
	{
		rrr(a, b);
		sort->a.amount--;
		sort->b.amount--;
	}
	else if (sort->a.amount > 0)
	{
		rra(a);
		sort->a.amount--;
	}
	else
	{
		rrb(b);
		sort->b.amount--;
	}
}

static void	arbrr(t_stack *a, t_stack *b, t_sort_cost *sort)
{
	if (sort->a.amount > 0)
	{
		ra(a);
		sort->a.amount--;
	}
	else
	{
		rrb(b);
		sort->b.amount--;
	}
}

static void	arrbr(t_stack *a, t_stack *b, t_sort_cost *sort)
{
	if (sort->a.amount > 0)
	{
		rra(a);
		sort->a.amount--;
	}
	else
	{
		rb(b);
		sort->b.amount--;
	}
}
void	do_sort(t_stack *a, t_stack *b, t_sort_cost sort)
{
	int i = 20;
	while (i-- > 0 && (sort.a.amount > 0 || sort.b.amount > 0))
	{
		if (sort.a.r && sort.b.r)
			arbr(a, b, &sort);
		else if (sort.a.rr && sort.b.rr)
			arrbrr(a, b, &sort);
		else if (sort.a.r && sort.b.rr)
			arbrr(a, b, &sort);
		else if (sort.a.rr && sort.b.r)
			arrbr(a, b, &sort);
		else if (sort.a.r)
		{
			ra(a);
			sort.a.amount--;
		}
		else if (sort.a.rr)
		{
			rra(a);
			sort.a.amount--;
		}
		else if (sort.b.r)
		{
			rb(b);
			sort.b.amount--;
		}
		else if (sort.b.rr)
		{
			rrb(b);
			sort.b.amount--;
		}
	}
	pa(a, b);
}
