/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:08:53 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/25 05:48:39 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	px(t_list **stack, t_list **sec_stack)
{
	t_list	*new;
	t_list	*tmp;

	if (!stack || !*stack)
		return ;
	new = ft_lstnew((*stack)->content);
	ft_lstadd_front(sec_stack, new);
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

void	pa(t_list **stack, t_list **sec_stack)
{
	px(stack, sec_stack);
	ft_printf("pa\n");
}

void	pb(t_list **stack, t_list **sec_stack)
{
	px(stack, sec_stack);
	ft_printf("pb\n");
}
