/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:47:20 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/31 15:50:09 by malebrun         ###   ########.fr       */
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
	int				index;
	int				inlis;
	struct s_node	*prev;
	struct s_node	*next;
}			t_node;

typedef struct s_lis
{
	int	value;
	int	lislen;
	int	lisprev;
	int	inlis;
}				t_lis;

typedef struct s_sorter
{
	int	rr;
	int	r;
	int	amount;
}				t_sorter;

typedef struct s_sort_cost
{
	t_sorter	a;
	t_sorter	b;
	int			totalcost;
}				t_sort_cost;

typedef struct s_stack
{
	int		size;
	t_node	*head;
}			t_stack;

long		ft_atol(char *nptr);
int			is_number(char c);
int			is_sign(char c);
int			is_whitespace(char c);
void		add_front(int val, t_stack *stack);
void		add_back(int val, t_stack *stack);
void		free_stack(t_stack *stack);
t_stack		*init_stack(char **av, int i, t_stack *stack_a);
int			ft_strlen(char *str);
int			check_dup(t_stack *stack);
t_stack		*create_stack(void);
void		fill_index(t_stack *a);
void		sort_stacks(t_stack *a, t_stack *b, t_lis *lisarr, int lis_size);
void		lis(t_stack *a);
int			is_in_lis(int val, int size, t_lis *lisarr);
void		rotate(t_stack *stack);
void		setuplis(t_stack *a, t_lis *lisar);
void		push_b(t_stack *a, t_stack *b);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stacka, t_stack *stackb);
void		pb(t_stack *stacka, t_stack *stackb);
t_sort_cost	get_sort_cost(t_stack *a, t_stack *b, t_node *tosort);
void		do_sort(t_stack *a, t_stack *b, t_sort_cost sort);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack1, t_stack *stack2);
void		sort_unique_case(t_stack *a, t_stack *b, t_sort_cost *sort);
t_node		*get_max(t_stack *a);
t_node		*get_min(t_stack *a);
void		sa(t_stack *stack);
int			aldready_sorted(t_stack *a);
void		end(int onko, t_stack *a, t_stack *b);
void		handle_small_size(t_stack *a, t_stack *b);
#endif
