/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:07:23 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/26 04:17:21 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	swap(t_list **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	ft_swap((*stack)->content, (*stack)->next->content);
}

void	swap_a(t_list **stack)
{
	swap(stack);
}

void	swap_b(t_list **stack)
{
	swap(stack);
}

void	swap_both(t_list **stack, t_list **sec_stack)
{
	swap(stack);
	swap(sec_stack);
}
