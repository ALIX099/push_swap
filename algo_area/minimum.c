/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 07:12:15 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/22 07:12:16 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*mini_node(t_list *stack)
{
	t_list *tmp;
	t_list *minimum;

	tmp = stack;
	minimum = stack;
	while (tmp)
	{
		if (*(int *)tmp->content < *(int *)minimum->content)
			minimum = tmp;
		tmp = tmp->next;
	}
	return (minimum);
}