/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 05:41:17 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/27 19:06:56 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_spliter(t_stack *stack)
{
	return (stack->size / 2);
}

void	push_b(t_stack *a, t_stack *b)
{
	int	i;
	int	size;
	int	spliter;
	int	torr;

	torr = 0;
	spliter = get_spliter(a);
	size = a->size;
	i = 0;
	while (i < size)
	{
		if (a->head && a->head->inlis && b->head
			&& b->head->next && b->head->index > spliter)
			rr(a, b);
		else if (a->head && a->head->inlis)
			ra(a);
		else if (b->head && b->head->next && b->head->index > spliter)
		{
			rb(b);
			pb(a, b);
		}
		else
			pb(a, b);
		i++;
	}
}
