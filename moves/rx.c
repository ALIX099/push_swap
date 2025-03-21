/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:07:51 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/21 03:08:32 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rx(t_list **stack)
{
	t_list *last;
	t_list *first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
}
