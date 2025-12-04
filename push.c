/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:47:29 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/04 13:14:13 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *take, t_stack *place)
{
	t_node *temp;

	if (!take || !take->head)
		return ;
	temp = take->head;
	take->head = temp->next;
	temp->next = place->head;
	place->head = temp;
	take->size--;
	place->size++;
}

void	pa(t_stack *stacka, t_stack *stackb)
{
	push(stackb, stacka);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stacka, t_stack *stackb)
{
	push(stacka, stackb);
	write(1, "pb\n", 3);
}
