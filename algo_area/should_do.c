/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_do.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 05:39:37 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/25 05:41:10 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_position(t_list *stack, int value)
{
	int		position;
	t_list	*current;

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

int	find_in_stack(t_list *stack, int value)
{
	while (stack)
	{
		if (*(int *)stack->content == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	move_to_top(t_list **stack, int value, int is_stack_a)
{
	int	pos;
	int	size;

	pos = find_position(*stack, value);
	size = ft_lstsize(*stack);
	if (pos <= size / 2)
	{
		while (*(int *)(*stack)->content != value)
		{
			if (is_stack_a)
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (*(int *)(*stack)->content != value)
		{
			if (is_stack_a)
				rra(stack);
			else
				rrb(stack);
		}
	}
}
