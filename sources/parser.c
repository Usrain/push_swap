/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:00:02 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/27 19:36:35 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	movetonext(char *arg)
{
	int	i;

	i = 0;
	while (is_whitespace(arg[i]))
		i++;
	if (is_sign(arg[i]))
		i++;
	while (is_number(arg[i]))
		i++;
	while (is_whitespace(arg[i]))
		i++;
	if (i == 0)
		i = 1;
	return (i);
}

t_stack	*create_stack(void)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->head = NULL;
	result->size = 0;
	return (result);
}

t_stack	*init_stack(char **av, int i, t_stack *stack_a)
{
	int		j;
	long	result;

	stack_a = create_stack();
	if (!stack_a)
		return (NULL);
	while (av[i])
	{
		result = 0;
		j = 0;
		if (!av[i][0])
			end(1, stack_a, NULL);
		while (av[i][j])
		{
			result = ft_atol(&av[i][j]);
			if (result == 2147483649)
				end(1, stack_a, NULL);
			add_back(result, stack_a);
			j += movetonext(&av[i][j]);
		}
		i++;
	}
	return (stack_a);
}

int	check_dup(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;

	temp = stack->head;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->value == temp2->value)
				return (0);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (1);
}
