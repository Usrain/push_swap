/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_exec_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:49:10 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/28 19:50:57 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

static int	pushcase(char *s, t_stack *a, t_stack *b)
{
	if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		pa(a, b);
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		pb(a, b);
	else
		return (0);
	return (1);
}

int	execaction(char *s, t_stack *a, t_stack *b)
{
	if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		ra(a);
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		rb(b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		rr(a, b);
	else if (s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		sa(a);
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		sb(b);
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\n')
		ss(a, b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		rra(a);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		rrb(b);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		rrr(a, b);
	else if (!pushcase(s, a, b))
		return (0);
	return (1);
}
