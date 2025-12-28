/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:56:42 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/28 19:42:49 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

void	rotate(t_stack *stack)
{
	t_node	*temp;
	t_node	*first;

	if (!stack->head)
		return ;
	if (!stack->head->next)
		return ;
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
}

void	rb(t_stack *stack)
{
	rotate(stack);
}

void	rr(t_stack *stack1, t_stack *stack2)
{
	rotate(stack1);
	rotate(stack2);
}
