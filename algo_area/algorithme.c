/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:14:31 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/22 06:44:35 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*mini_node(t_list *stack)
{
	t_list	*tmp;
	t_list	*minimum;

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
void two_args(t_list *stack_a)
{
	sx(&stack_a);
	ft_printf("sa\n");
}

void	three_args(t_list *stack_a,t_list *stack_b, int a, int b, int c)
{
	if (a < b && b > c && a < c)
	{
		rrx(&stack_a);
		sx(&stack_a);
		ft_printf("rra\nsa\n");
	}
	else if (b < a && a < c && b < c)
	{
		sx(&stack_a);
		ft_printf("sa\n");
	}
	else if (c < b && b < a && c < a)
	{
		rrx(&stack_a);
		rrx(&stack_a);
		sx(&stack_a);
		ft_printf("rra\nrra\nsa\n");
	}
	else if (b < c && c < a && b < a)
	{
		rrx(&stack_a);
		rrx(&stack_a);
		ft_printf("rra\nrra\n");
	}
	else
	{
		rrx(&stack_a);
		ft_printf("rra\n");
	}
}
void	first_five(t_list *stack_a, t_list *stack_b)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)stack_a->content;
	b = *(int *)stack_a->next->content;
	c = *(int *)stack_a->next->next->content;
	(void)stack_b;
	if (is_sorted(stack_a))
		return (free_list(stack_a));
	if (ft_lstsize(stack_a) == 2)
		two_args(stack_a);
	else if (ft_lstsize(stack_a) == 3)
		three_args(stack_a, stack_b, a , b , c);
	
}
