/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lisarr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:22:49 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/04 13:04:00 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_lis(int val, int size, t_lis *lisarr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (lisarr[i].value == val && lisarr[i].inlis)
			return (1);
		i++;
	}
	return (0);
}
