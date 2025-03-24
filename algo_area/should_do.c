#include "../push_swap.h"

// Rotates max value to top of stack_b
void	move_to_top_b(t_list **stack, int max_value)
{
	int	index;
	int	size;

	if (!stack || !*stack)
		return ;
	while (*(int *)((*stack)->content) != max_value)
	{
		index = find_position(*stack, max_value);
		size = ft_lstsize(*stack);
		if (index < size / 2)
			rb(stack);
		else
			rrb(stack);
	}
}

// Check if stack can be sorted with minimal rotations
int	needs_simple_rotation(t_list *stack)
{
	int		rotations_needed;
	t_list	*tmp;
	int		min;
	int		max;

	rotations_needed = 0;
	tmp = stack;
	min = *(int *)mini_node(stack)->content;
	max = maximum(stack);
	// Find the first element that breaks ascending order
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			break ;
		tmp = tmp->next;
		rotations_needed++;
	}
	// Case 1: Already sorted
	if (rotations_needed == ft_lstsize(stack) - 1)
		return (0);
	// Case 2: Can be sorted with reverse rotations
	if (*(int *)ft_lstlast(stack)->content == max
		&& *(int *)stack->content == min)
		return (1); // Needs reverse rotation
	// Case 3: Can be sorted with forward rotations
	if (*(int *)stack->content == max
		&& *(int *)ft_lstlast(stack)->content == min)
		return (-1); // Needs forward rotation
	return (0);      // Not an edge case
}

int	find_position(t_list *stack, int value)
{
	int position;
	t_list *current;

	position = 0;
	current = stack;
	while (current)
	{
		if (*(int *)current->content == value)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}