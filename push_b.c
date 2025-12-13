
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
	int	torr;

	torr = 0;
	spliter = get_spliter(a);
	size = a->size;
	i = 0;
	while (i < size)
	{
		if (a->head->inlis && b->head && b->head->index > spliter)
			rr(a, b);
		else if (a->head->inlis)
			ra(a);
		else if (b->head && b->head->index > spliter)
		{
			rb(b);
			pb(a, b);
		}
		else
			pb(a, b);
		i++;
	}
}
