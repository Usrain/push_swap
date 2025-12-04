/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:05:10 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/04 15:10:33 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

t_sorter	*get_sort_value(t_stack *a, t_stack *b)
{
	t_sorter *result;

	result = malloc(sizeof(t_stack) * b->size);
	if (!result)
		return (NULL);
	
}
