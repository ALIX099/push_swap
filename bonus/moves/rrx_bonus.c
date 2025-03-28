/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:08:34 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/26 04:17:15 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	rotate_reverse(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	last->next = *stack;
	*stack = last;
	before_last->next = NULL;
}

void	rotate_reverse_a(t_list **stack)
{
	rotate_reverse(stack);
}

void	rotate_reverse_b(t_list **stack)
{
	rotate_reverse(stack);
}

void	rotate_reverse_both(t_list **stack, t_list **sec_stack)
{
	rotate_reverse(stack);
	rotate_reverse(sec_stack);
}
