/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:24:10 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/31 15:42:52 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_sort(t_stack *a, t_stack *b)
{
	t_node		*temp;
	t_sort_cost	sort_cost;
	t_sort_cost	min;
	t_node		*min_node;

	temp = b->head;
	min_node = NULL;
	sort_cost = get_sort_cost(a, b, temp);
	min = sort_cost;
	while (temp)
	{
		if (min.totalcost > get_sort_cost(a, b, temp).totalcost)
		{
			min = get_sort_cost(a, b, temp);
			min_node = temp;
		}
		temp = temp->next;
	}
	do_sort(a, b, min);
}

static void	final_order(t_stack *a)
{
	t_node	*temp;
	int		foundat;

	foundat = 0;
	temp = a->head;
	while (temp->index != 0)
	{
		temp = temp->next;
		foundat++;
	}
	if (foundat <= a->size / 2)
		while (a->head->index != 0)
			ra(a);
	else
		while (a->head->index != 0)
			rra(a);
	end(0, a, NULL);
}

void	end(int onko, t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (onko)
		write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		end(1, NULL, NULL);
	stack_a = init_stack(av, 1, NULL);
	if (!stack_a)
		end(1, NULL, NULL);
	stack_b = create_stack();
	if (!stack_b)
		end(1, stack_a, NULL);
	if (!check_dup(stack_a))
		end(1, stack_a, stack_b);
	fill_index(stack_a);
	if (aldready_sorted(stack_a))
		end(0, stack_a, stack_b);
	handle_small_size(stack_a, stack_b);
	lis(stack_a);
	push_b(stack_a, stack_b);
	while (stack_b->head)
		min_sort(stack_a, stack_b);
	free_stack(stack_b);
	final_order(stack_a);
}
