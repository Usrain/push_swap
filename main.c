/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:24:10 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/04 14:51:46 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	lys_sort(stack_a, stack_b);

	//
	int	i;
	i = 0;
	t_node *test = stack_a->head;
	printf("stack a :\n");
	while (test)
	{
		printf("%d : %d \n", i, test->value);
		test = test->next;
		i++;
	}
	printf("stack b :\n");
	test = stack_b->head;
	i = 0;
	while (test)
	{
		printf("%d : %d \n", i, test->value);
		test = test->next;
		i++;
	}
}
