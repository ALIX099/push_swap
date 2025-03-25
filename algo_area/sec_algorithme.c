/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_algorithme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 05:52:29 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/25 06:01:42 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_chunks_to_b(t_list **stack_a, t_list **stack_b, t_range *range)
{
	int content;
	range->i = 0;
	while (range->i < range->size)
	{
		range->range_end = range->i + range->chunk_size;
		if (range->range_end > range->size)
			range->range_end = range->size;
		while (range->i < range->range_end)
		{
			range->target = range->array[range->size - 1 - range->i];
			move_to_top(stack_a, range->target, 1);
			pb(stack_a, stack_b);
			content = *(int *)(*stack_a)->next->content;
			if (*stack_b && (*stack_b)->next
				&& *(int *)(*stack_b)->content < content)
				rb(stack_b);
			range->i++;
		}
	}
}

void	large_sort(t_list **stack_a, t_list **stack_b, int size)
{
	t_range	range;

	range.array = append_to_array(*stack_a, size);
	bubble_sort(range.array, size);
	range.size = size;
	if (size <= 100)
		range.chunk_size = size / 6;
	else
		range.chunk_size = size / 15;
	push_chunks_to_b(stack_a, stack_b, &range);
	range.i = size - 1;
	while (range.i >= 0)
	{
		if (find_in_stack(*stack_b, range.array[range.i]))
		{
			move_to_top(stack_b, range.array[range.i], 0);
			pa(stack_b, stack_a);
			range.content = *(int *)(*stack_a)->next->content;
			if (*stack_a && (*stack_a)->next
				&& *(int *)(*stack_a)->content > range.content)
				sa(stack_a);
		}
		range.i--;
	}
	free(range.array);
}
