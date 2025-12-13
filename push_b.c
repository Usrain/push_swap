
#include "push_swap.h"

static int	get_spliter(t_stack *stack)
{
	return (stack->size / 2);
}

void	push_b(t_stack *a, t_stack *b)
{
	int	i;
	int	size;
	int	spliter;

	spliter = get_spliter(a);
	size = a->size;
	i = 0;
	while (i < size)
	{
		if (a->head->inlis)
			ra(a);
		else
		{
			if (a->head->index < spliter)
				pb(a, b);
			else
			{
				pb(a, b);
				if (b->size > 1)
					rb(b);
			}
		}
		i++;
	}
}
