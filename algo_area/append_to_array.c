/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 04:52:53 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/23 15:35:53 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*append_to_array(t_list *stack, int size)
{
	unsigned int	i;
	int				*array;

	i = 0;
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	while (stack)
	{
		array[i] = *(int *)stack->content;
		stack = stack->next;
		i++;
	}
	return (array);
}
