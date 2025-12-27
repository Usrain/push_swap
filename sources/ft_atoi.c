/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:59:35 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/27 19:05:26 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	skip_ws(char *nptr, int i)
{
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == ' ')
		i++;
	return (i);
}

static long	handle_sign(char *nptr, int *i)
{
	long	neg;

	neg = 1;
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			neg = -1;
		(*i)++;
	}
	return (neg);
}

long	ft_atol(char *nptr)
{
	int				i;
	long			neg;
	long			result;

	result = 0;
	i = skip_ws(nptr, 0);
	neg = handle_sign(nptr, &i);
	if (!nptr[i] || nptr[i] == '\0')
		return (2147483649);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if ((neg == 1 && result > (2147483647 - (nptr[i] - '0')) / 10)
			|| (neg == -1 && -(result) < (-2147483648 + (nptr[i] - '0')) / 10))
			return (2147483649);
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
		return (2147483649);
	i = skip_ws(nptr, i);
	if (!((nptr[i] >= '0' && nptr[i] <= '9' )
			|| nptr[i] == '-' || nptr[i] == '+') && nptr[i] != '\0')
		return (2147483649);
	return ((long)(result * neg));
}
