/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 04:34:58 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/23 04:39:50 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_unique_case(t_stack *a, t_stack *b, t_sort_cost *sort)
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
