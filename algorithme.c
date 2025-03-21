/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:14:31 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/21 16:18:13 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int main(void)
{
    t_list *stack;
    t_list *min_node;
    int a = 5;
    int b = 3;
    int c = 7;

    stack = ft_lstnew(&a);
    ft_lstadd_back(&stack, ft_lstnew(&b));
    ft_lstadd_back(&stack, ft_lstnew(&c));

    min_node = mini_node(stack);

    printf("Minimum value: %d\n", *(int *)min_node->content);

    return 0;
}
