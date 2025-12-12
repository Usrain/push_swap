/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lyssort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:11:48 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/12 18:48:39 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lis	*stack_to_arr(t_stack *stack)
{
	t_lis		*result;
	t_node	*actual;
	int		i;

	result = malloc(sizeof(t_lis) * (stack->size));
	if (!result)
		return (NULL);
	actual = stack->head;
	i = 0;
	while (actual)
	{
		result[i].value = actual->value;
		result[i].lislen = 1;
		result[i].lisprev = -1;
		result[i].inlis = 0;
		i++;
		actual = actual->next;
	}
	return (result);
	
}

static t_lis	*fill_lis_arr(t_lis *listarr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		listarr[i].lislen = 1;
		j = 0;
		while (j < i)
		{
			if (listarr[j].value < listarr[i].value)
			{
				if (listarr[j].lislen + 1 > listarr[i].lislen)
				{
					listarr[i].lislen = listarr[j].lislen + 1;
					listarr[i].lisprev = j;
				}
			}
			j++;
		}
		i++;
	}
	return (listarr);
}

static void	fill_in_lis(t_lis *lisarr, int size)
{
	int	i;
	int	max;
	int	indexmax;
	int	prev;

	i = 0;
	max = 0;
	indexmax = 0;
	while (i < size)
	{
		if (lisarr[i].lislen > max)
		{
			indexmax = i;
			max = lisarr[i].lislen;
		}
		i++;
	}
	while (indexmax >=0 && (lisarr[indexmax].lisprev < 0
			|| lisarr[lisarr[indexmax].lisprev].value < lisarr[indexmax].value))
	{
		lisarr[indexmax].inlis = 1; 
		prev = lisarr[indexmax].lisprev;
		if (prev >= 0 && lisarr[prev].value < lisarr[indexmax].value)
			indexmax = prev;
		else
			indexmax = -1;
	}
}

listarr	get_best_lis(t_stack *a, )
void	lis(t_stack *a, t_stack *b)
{
	t_lis	*listarr;
	t_node	*temp;
	t_node	first;
	t_node	best;
	first = a->head;
	listarr = stack_to_arr(a);
	if (!listarr)
		return ;
	listarr = fill_lis_arr(listarr, a->size);
	fill_in_lis(listarr, a->size);
	temp = a->head;
	while (temp)
	{
		if (is_in_lis(temp->value, a->size, listarr))
			temp->inlis = 1;
		temp = temp->next;
	}
}
