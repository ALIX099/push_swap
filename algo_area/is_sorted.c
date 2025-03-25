/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:31:54 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/25 16:25:32 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_almost_sorted(t_list *a)
{
	t_list	*current;
	int		min_val;

	if (!a || !a->next)
		return (0);
	min_val = *(int *)mini_node(a)->content;
	current = a;
	while (current->next)
	{
		if (*(int *)current->content > *(int *)current->next->content)
		{
			if (current->next->next == NULL
				&& *(int *)current->next->content == min_val)
				return (1);
			else
				return (0);
		}
		current = current->next;
	}
	return (0);
}
