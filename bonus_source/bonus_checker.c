/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:24:10 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/28 20:25:14 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

void	end(int onko, t_stack *a, t_stack *b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (onko == 1)
		write(2, "Error\n", 6);
	if (!onko)
		write(1, "OK\n", 3);
	if (onko == 2)
		write(1, "KO\n", 3);
	exit(1);
}

static t_actionnode	*get_action(void)
{
	ssize_t			nbite;
	t_actionnode	*head;
	t_actionnode	*temp;
	t_actionnode	*temp2;

	head = init_actionnode();
	temp = head;
	nbite = read(0, temp->todo, 4);
	while (nbite > 0)
	{
		temp2 = init_actionnode();
		nbite = read(0, temp2->todo, 4);
		temp->next = temp2;
		temp = temp2;
	}
	return (head);
}

static int	is_ok(t_stack *a, t_stack *b)
{
	t_node	*temp;

	temp = a->head;
	if (b->head)
		return (0);
	while (temp && temp->next)
	{
		if (!(temp->value < temp->next->value))
			return (0);
		temp = temp->next;
	}
	return (1);
}

static void	try(t_stack *a, t_stack *b, t_actionnode *head, t_actionnode *temp)
{
	int	verif;

	verif = 1;
	while (temp->next && verif)
	{
		verif = execaction(temp->todo, a, b);
		temp = temp->next;
	}
	while (head)
	{
		temp = head->next;
		free(head->todo);
		free(head);
		head = temp;
	}
	if (!verif)
		end(1, a, b);
	if (is_ok(a, b))
		end(0, a, b);
	end(2, a, b);
}

int	main(int ac, char **av)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_actionnode	*head;

	if (ac < 2)
		end(3, NULL, NULL);
	stack_a = init_stack(av, 1, NULL);
	if (!stack_a)
		end(1, NULL, NULL);
	stack_b = create_stack();
	if (!stack_b)
		end(1, stack_a, NULL);
	if (!check_dup(stack_a))
		end(1, stack_a, stack_b);
	head = get_action();
	try(stack_a, stack_b, head, head);
}
