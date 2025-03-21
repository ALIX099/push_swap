/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:07:23 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/21 03:08:35 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(int *a, int *b)
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
