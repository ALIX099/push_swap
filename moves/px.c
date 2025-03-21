/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:08:53 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/21 00:46:41 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	px(t_list **stack, t_list **sec_stack)
{
	t_list	*new;
	t_list	*tmp;

	if (!stack || !*stack)
		return ;
	new = ft_lstnew((*stack)->content);
	ft_lstadd_front(sec_stack, new);
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

int	main(void)
{
	t_list	*c;
	int		aa;
	int		bb;
	t_list	*tmp;

	t_list *a, *b;
	aa = 1;
	bb = 2;
	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	c = malloc(sizeof(t_list));
	a->content = &aa;
	a->next = b;
	b->content = &bb;
	b->next = NULL;
	px(&a, &c);
	tmp = c;
	while (tmp->content)
	{
		printf("%d ->", *(int *)tmp->content);
		tmp = tmp->next;
	}
}

// sec_stack 23 -> 87 ->NULL
// stack 23 ->42 .. -> NULL