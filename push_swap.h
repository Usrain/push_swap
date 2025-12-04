/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:47:20 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/04 15:04:54 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}			t_node;

typedef struct s_lis
{
	int	value;
	int	lislen;
	int	lisprev;
	int	inlis;
}				t_lis;

typedef	struct s_sorter
{
	int	value_b;
	int op_amount;
	int	place_after;
}				t_sorter;


typedef struct s_stack
{
	int		size;
	t_node	*head;
}			t_stack;

long	ft_atol(char *nptr);
int		is_number(char c);
int		is_sign(char c);
int		is_whitespace(char c);
void    add_front(int val, t_stack *stack);
void    add_back(int val, t_stack *stack);
void    free_stack(t_stack *stack);
t_stack *init_stack(char **av);
int 	ft_strlen(char *str);
int		check_dup(t_stack *stack);
t_stack *create_stack(void);
void    lys_sort(t_stack *a, t_stack *b);
#endif
