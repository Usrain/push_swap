/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 19:12:37 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/28 19:42:58 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

static void	rreverse(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;

	if (!stack->head)
		return ;
	if (!stack->head->next)
		return ;
	temp = stack->head;
	temp2 = temp;
	while (temp->next)
		temp = temp->next;
	while (temp2->next != temp)
		temp2 = temp2->next;
	temp2->next = NULL;
	temp->next = stack->head;
	stack->head = temp;
	stack->head->next->prev = stack->head;
	stack->head->prev = NULL;
}

void	rra(t_stack *stack)
{
	rreverse(stack);
}

void	rrb(t_stack *stack)
{
	rreverse(stack);
}

void	rrr(t_stack *stack1, t_stack *stack2)
{
	rreverse(stack1);
	rreverse(stack2);
}
