/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:08:34 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/25 05:48:37 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrx(t_list **stack)
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

void	rra(t_list **stack)
{
	rrx(stack);
	ft_printf("rra\n");
}

void	rrb(t_list **stack)
{
	rrx(stack);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack, t_list **sec_stack)
{
	rrx(stack);
	rrx(sec_stack);
	ft_printf("rrr\n");
}
