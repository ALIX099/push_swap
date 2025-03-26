/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sec_algorithme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:01:06 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/25 17:07:38 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	affect_values(t_list **a, t_range *range, int size)
{
	range->array = append_to_array(*a, size);
	if (!range->array)
		return ;
	bubble_sort(range->array, size);
	if (size <= 100)
		range->offset = size / 6;
	else
		range->offset = size / 12;
	range->size = size;
	range->start = 0;
	range->end = range->offset;
}

void	sec_algorithme(t_list **a, t_list **b, int size)
{
	t_range	range;

	if (is_sorted(*a))
		return ;
	if (is_almost_sorted(*a))
	{
		rra(a);
		return ;
	}
	affect_values(a, &range, size);
	push_to_b(a, b, &range);
	push_to_a(a, b);
	free(range.array);
}
