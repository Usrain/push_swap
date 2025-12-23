/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:24:10 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/23 05:31:11 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*static void test(t_stack *a, t_stack *b)
{
	int	i;
	i = 0;
	t_node *test = a->head;
	printf("stack a :\n");
	while (test)
	{
		printf("%d : %d  index : %d  inlis : %d\n", i, test->value, test->index, test->inlis);
		test = test->next;
		i++;
	}
	printf("stack b :\n");
	test = b->head;
	i = 0;
	while (test)
	{
		printf("%d : %d  index : %d  inlis : %d\n", i, test->value, test->index, test->inlis);
		test = test->next;
		i++;
	}
	printf("\n \n %s \n \n", "____________________next___________________");
}*/

static void min_sort(t_stack *a, t_stack *b)
{
	t_node *temp;
	t_sort_cost sort_cost;
	t_sort_cost min;
	t_node *min_node;

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
	do_sort(a,b,min);
	//test(a, b);
}

static void final_order(t_stack *a)
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
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void) ac;
	stack_a = init_stack(av);
	if (!stack_a)
		return (1);
	stack_b = create_stack();
	if (!stack_b)
		return (1);
	if (!check_dup(stack_a))
	{
		free_stack(stack_a);
		write(2, "ko", 2);
		return (1);
	}
	fill_index(stack_a);
	lis(stack_a);
	push_b(stack_a, stack_b);

	while (stack_b->head)
		min_sort(stack_a, stack_b);
	final_order(stack_a);
	//test(stack_a, stack_b);
}
