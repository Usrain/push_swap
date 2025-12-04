/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:19:41 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/03 19:30:45 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void	sa(t_stack *stack)
{
	swap_first(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	swap_first(stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack1, t_stack *stack2)
{
	swap_first(stack1);
	swap_first(stack2);
	write(1, "ss\n", 3);
}
