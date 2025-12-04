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
	(void) a;
	(void)b;
	printf("rien");
}

int	**chunk(t_stack *a, t_stack *b)
{
	int	**result;

	result = malloc(sizeof(int *) * (a->size / 10 + 1));
	if (!result)
		return (NULL);
	
}
