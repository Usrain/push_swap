/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_actionnode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:29:04 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/28 19:50:31 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

t_actionnode	*init_actionnode(void)
{
	t_actionnode	*result;

	result = malloc(sizeof(t_actionnode));
	if (!result)
		return (NULL);
	result->todo = malloc(sizeof(char) * 5);
	if (!result->todo)
	{
		free(result);
		return (NULL);
	}
	result->todo[4] = '\0';
	result->next = NULL;
	return (result);
}
