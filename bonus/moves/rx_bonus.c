/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:07:51 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/26 04:01:22 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
}

void	rotate_a(t_list **stack)
{
	rotate(stack);
}

void	rotate_b(t_list **stack)
{
	rotate(stack);
}

void	rotate_both(t_list **stack, t_list **sec_stack)
{
	rotate(stack);
	rotate(sec_stack);
}

