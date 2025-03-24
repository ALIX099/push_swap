#include "../push_swap.h"

void	large_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	*sorted;
	int	chunk_size;
	int	i;
	int	range_end;
	int	target;
	int	stack_size;
	int	max;
	int	pos;
	int	b_size;

	if (is_sorted(*stack_a))
		return ;
	sorted = append_to_array(*stack_a, size);
	bubble_sort(sorted, size);
	if (size <= 100)
		chunk_size = size / 6;
	else
		chunk_size = size / 12;
	i = 0;
	while (i < size)
	{
		range_end = i + chunk_size;
		if (range_end > size)
			range_end = size;
		while (i < range_end)
		{
			target = sorted[i];
			pos = find_position(*stack_a, target);
			stack_size = ft_lstsize(*stack_a);
			if (pos <= stack_size / 2)
			{
				while (*(int *)(*stack_a)->content != target)
					ra(stack_a);
			}
			else
			{
				while (*(int *)(*stack_a)->content != target)
					rra(stack_a);
			}
			pb(stack_a, stack_b);
			i++;
		}
	}
	while (*stack_b)
	{
		max = maximum(*stack_b);
		pos = find_position(*stack_b, max);
		b_size = ft_lstsize(*stack_b);
		if (pos <= b_size / 2)
		{
			while (*(int *)(*stack_b)->content != max)
				rb(stack_b);
		}
		else
		{
			while (*(int *)(*stack_b)->content != max)
				rrb(stack_b);
		}
		pa(stack_b, stack_a);
		if (ft_lstsize(*stack_a) >= 2)
		{
			if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
				sa(stack_a);
		}
	}
	free(sorted);
}
