/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maximum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 06:08:19 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/24 18:04:40 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	maximum(t_list *stack)
{
	int	max;

	max = *(int *)(stack->content);
	stack = stack->next;
	while (stack != NULL)
	{
		if (*(int *)(stack->content) > max)
			max = *(int *)(stack->content);
		stack = stack->next;
	}
	return (max);
}
