/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malebrun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:47:20 by malebrun          #+#    #+#             */
/*   Updated: 2025/12/28 19:56:35 by malebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_CHECKER_H
# define BONUS_CHECKER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				inlis;
	struct s_node	*prev;
	struct s_node	*next;
}			t_node;

typedef struct s_actionnode
{
	char				*todo;
	struct s_actionnode	*next;
}			t_actionnode;

typedef struct s_stack
{
	int		size;
	t_node	*head;
}			t_stack;

void			add_front(int val, t_stack *stack);
void			add_back(int val, t_stack *stack);
void			free_stack(t_stack *stack);
t_stack			*create_stack(void);
t_stack			*init_stack(char **av, int i, t_stack *stack_a);
int				check_dup(t_stack *stack);
long			ft_atol(char *nptr);
int				is_number(char c);
int				is_sign(char c);
int				is_whitespace(char c);
void			end(int onko, t_stack *a, t_stack *b);
int				aldready_sorted(t_stack *a);
t_actionnode	*init_actionnode(void);
int				execaction(char *s, t_stack *a, t_stack *b);
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			rr(t_stack *stack1, t_stack *stack2);
void			rrr(t_stack *stack1, t_stack *stack2);
void			pa(t_stack *stacka, t_stack *stackb);
void			pb(t_stack *stacka, t_stack *stackb);
void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			ss(t_stack *stack1, t_stack *stack2);

#endif
