/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:18:34 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/04 17:03:56 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterflysort(t_stack *a, t_stack *b)
{
	int	c_size = 30;


}

static int	chunk(t_stack *a, t_stack *b)
{
	int	chunk_amount;

	if (a->size < 100)
		chunk_amount = 5;
	else if (a->size <=500)
		chunk_amount = 15;
	else
		chunk_amount = 20;
	return (chunk_amount);
}
