/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:31:54 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/22 05:43:51 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		while (stack)
		{
			if (*(int *)tmp->content > *(int *)stack->content)
				return (0);
			stack = stack->next;
		}
		tmp = tmp->next;
		if (tmp)
			stack = tmp->next;
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