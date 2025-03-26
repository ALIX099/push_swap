/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:07:23 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/26 03:59:41 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sx(t_list **stack)
{
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	ft_swap((*stack)->content, (*stack)->next->content);
}

void	sa(t_list **stack)
{
	sx(stack);
	ft_printf("sa\n");
}

void	sb(t_list **stack)
{
	sx(stack);
	ft_printf("sb\n");
}

void	ss(t_list **stack, t_list **sec_stack)
{
	sx(stack);
	sx(sec_stack);
	ft_printf("ss\n");
}
