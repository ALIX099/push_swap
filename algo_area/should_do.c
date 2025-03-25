/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_do.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 05:39:37 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/25 17:20:34 by abouknan         ###   ########.fr       */
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

static void	next_chunk(t_range *range)
{
	if (range->start < range->end - 1)
		range->start++;
	if (range->end < range->size - 1)
		range->end++;
}

void	push_to_a(t_list **a, t_list **b)
{
	int	max;
	int	pos;
	int	size;

	while (*b)
	{
		max = find_max_value(*b);
		pos = find_position(*b, max);
		size = ft_lstsize(*b);
		if (pos <= size / 2)
		{
			while (*(int *)(*b)->content != max)
				rb(b);
		}
		else
		{
			while (*(int *)(*b)->content != max)
				rrb(b);
		}
		pa(b, a);
		if (*a && (*a)->next
			&& *(int *)(*a)->content > *(int *)(*a)->next->content)
			sa(a);
	}
}

void	push_to_b(t_list **a, t_list **b, t_range *range)
{
	int	content;

	while (*a)
	{
		content = *(int *)(*a)->content;
		if (content <= range->array[range->start])
		{
			pb(a, b);
			rb(b);
			next_chunk(range);
		}
		else if (content <= range->array[range->end])
		{
			pb(a, b);
			if (ft_lstsize(*b) > 1
				&& *(int *)(*b)->content < *(int *)(*b)->next->content)
				sb(b);
			next_chunk(range);
		}
		else
			ra(a);
	}
}
