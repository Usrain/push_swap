/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:59:05 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/02 15:12:42 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*init_node(int val)
{
	t_node *rvalue;

	rvalue = malloc(sizeof(t_node));
	if (!rvalue)
		return (NULL);
	rvalue->value = val;
	rvalue->next = NULL;
	return (rvalue);
}

void	add_front(int val, t_stack *stack)
{
	t_node	*temp;

	temp = init_node(val);
	if (!temp)
	{
		free_stack(stack);
		return ;
	}
	temp->next = stack->head;
	stack->head = temp;
	stack->size++;
}

void	add_back(int val, t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	temp = malloc(sizeof(t_node));
	if (!temp)
	{
		free_stack(stack);
		return ;
	}
	temp->value = val;
	temp->next = NULL;
	if (!stack->head)
	{
		stack->head = temp;
		stack->size++;
		return ;
	}
	current = stack->head;
	while (current->next)
		current = current->next;
	current->next = temp;
	stack->size++;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	
	}
	free(stack);
}
