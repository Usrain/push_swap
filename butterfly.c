/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:18:34 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/04 16:29:00 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	butterflysort(stack *a, stack *b)
{
}

int	**chunk(stack *a, stack *b)
{
	int	**result;

	result = malloc(sizeof(int *) * (a->size / 10 + 1));
	if (!result)
		return (NULL);
	
}
