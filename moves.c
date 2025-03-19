/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:52:37 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/19 09:00:22 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rx(t_list **stack)
{
	t_list	*last;
	t_list	*first;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = ft_lstlast(first);
	last->next = first;
	first->next = NULL;
}

void	rrx(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	last->next = *stack;
	*stack = last;
	before_last->next = NULL;
}

void px(t_list **stack , t_list **sec_stack)
{
	t_list *new;
	t_list *tmp;

	if (!stack || !(*stack))
		return;
	new->content = (*stack)->content;
	ft_lstadd_front(sec_stack, new);
	tmp = *stack;
	(*stack) = (*stack)->next;
	free(tmp);
}