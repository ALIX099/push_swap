/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:07:51 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/22 06:57:14 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rx(t_list **stack)
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

void	ra(t_list **stack)
{
	rx(stack);
	ft_printf("ra\n");
}

void	rb(t_list **stack)
{
	rx(stack);
	ft_printf("rb\n");
}

void	rr(t_list **stack, t_list **sec_stack)
{
	rx(stack);
	rx(sec_stack);
	ft_printf("rr\n");
}