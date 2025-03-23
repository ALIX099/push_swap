/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:31:54 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/23 03:30:59 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// int	main(void)
// {
// 	t_list *stack;
// 	int i;
// 	int a;
// 	int b;
// 	int c;

// 	a = 1;
// 	b = 3;
// 	c = 7;
// 	stack = ft_lstnew(&a);
// 	ft_lstadd_back(&stack, ft_lstnew(&b));
// 	ft_lstadd_back(&stack, ft_lstnew(&c));
// 	i = is_sorted(stack);
// 	printf("Value: %d\n", i);
// 	return (0);
// }