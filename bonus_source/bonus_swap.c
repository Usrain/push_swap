/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:19:41 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/28 19:43:10 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

void	swap_first(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->head = second;
	stack->head->prev = NULL;
	stack->head->next->prev = stack->head;
}

void	sa(t_stack *stack)
{
	swap_first(stack);
}

void	sb(t_stack *stack)
{
	swap_first(stack);
}

void	ss(t_stack *stack1, t_stack *stack2)
{
	swap_first(stack1);
	swap_first(stack2);
}
