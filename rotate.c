/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:56:42 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/02 19:12:18 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*first;

	first = stack->head;
	stack->head = first->next;
	temp = stack->head;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->prev = temp;
	first->next = NULL;
	stack->head->prev = NULL;
}

void	ra(t_stack *stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	rotate(stack1);
	rotate(stack2);
	write(1, "rr\n", 3);
}

