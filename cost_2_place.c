/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_2_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:58:54 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/13 19:52:39 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_node	*place_after(t_stack *a, int value)
{
	t_node	*maxedmin;
	t_node	*temp;

	temp = (a->head);
	maxedmin = NULL;
	while (temp)
	{
		if (!maxedmin && temp->index < value)
			maxedmin = temp;
		if (maxedmin && temp->index > maxedmin && temp->index < value)
			maxedmin = temp;
		temp = temp->next;
	}
	return (maxedmin);
}

t_sorter todinb(t_stack *b, int value)
{
	int			i;
	t_sorter	result;
	t_node		*temp;

	temp = b->head;
	i = 0;
	if (temp->index == value)
	{
		result.r = 0;
		result.rr = 0;
		result.amount = 0;
		return (result);
	}
	while (temp && temp->index !value)
	{
		temp = temp->next;
		i++;
	}
	result.rr = b->size / 2 >= i;
	result.r = b->size / 2 < i;
	result.amount = i;
	return (result);
}

t_sorter	todoina(t_stack *a, int value, t_node *placeafter)
{
	t_node *temp;
	t_sorter	result;
	int		i;

	if (!placeafter)
	{
		result.r = 0;
		result.rr = 0;
		result.amount = 0;
		return (result);
	}
	temp = a->head;
	i = 0;
	while (temp != placeafter)
	{
		i++;
		temp = temp->next;
	}
	result.rr = a->size / 2 >= i;
	result.r = a->size / 2 < i;
	result.amount = i;
	return (result);
}

int	get_sort_cost(t_stack *a, t_stack *b, t_node *tosort)
{
	t_node *temp;
	int		op_amount;

	temp = b->head;
	place_after(a, tosort->index);

}
