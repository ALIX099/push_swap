/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:08:53 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/20 01:11:36 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	px(t_list **stack, t_list **sec_stack)
{
	t_list	*new;
	t_list	*tmp;

	new = ft_lstnew((*stack)->content); // 8->null
	if (!stack || !*stack)
		return ;
	ft_lstadd_front(sec_stack, new);
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}