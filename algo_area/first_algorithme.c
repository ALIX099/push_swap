/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:14:31 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/22 08:10:29 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_args(t_list *stack_a)
{
	sx(&stack_a);
	ft_printf("sa\n");
}

void	three_args(t_list *stack_a, int a, int b, int c)
{
	a = *(int *)stack_a->content;
	b = *(int *)stack_a->next->content;
	c = *(int *)stack_a->next->next->content;
	if (a < b && b > c && a < c)
	{
		rra(&stack_a);
		sa(&stack_a);
	}
	else if (b < a && a < c && b < c)
		sa(&stack_a);
	else if (c < b && b < a && c < a)
	{
		rra(&stack_a);
		rra(&stack_a);
		sa(&stack_a);
	}
	else if (b < c && c < a && b < a)
	{
		rra(&stack_a);
		rra(&stack_a);
	}
	else if (c < a && a < b && c < b)
		rra(&stack_a);
}
void	four_args(t_list *stack_a, t_list *stack_b)
{
	int		a;
	int		b;
	int		c;
	t_list	*minimum;

	a = 0;
	b = 0;
	c = 0;
	minimum = mini_node(stack_a);
	if (*(int *)minimum->content == *(int *)stack_a->next->content)
		sa(&stack_a);
	else
	{
		while (*(int *)stack_a->content != *(int *)minimum->content)
			rra(&stack_a);
	}
	if (is_sorted(stack_a))
		return ;
	pb(&stack_a, &stack_b);
	three_args(stack_a, a, b, c);
	pa(&stack_b, &stack_a);
}

void	five_args(t_list *stack_a, t_list *stack_b)
{
	int		a;
	int		b;
	int		c;
	t_list	*minimum;

	a = 0;
	b = 0;
	c = 0;
	minimum = mini_node(stack_a);
	if (*(int *)minimum->content == *(int *)stack_a->next->content)
		sa(&stack_a);
	else
	{
		while (*(int *)stack_a->content != *(int *)minimum->content)
			rra(&stack_a);
	}
	if (is_sorted(stack_a))
		return ;
	pb(&stack_a, &stack_b);
	four_args(stack_a, stack_b);
	pa(&stack_b, &stack_a);
}

void	first_five(t_list *stack_a, t_list *stack_b)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	c = 0;
	if (is_sorted(stack_a))
		return (free_list(stack_a));
	if (ft_lstsize(stack_a) == 2)
		two_args(stack_a);
	else if (ft_lstsize(stack_a) == 3)
		three_args(stack_a, a, b, c);
	else if (ft_lstsize(stack_a) == 4)
		four_args(stack_a, stack_b);
	else if (ft_lstsize(stack_a) == 5)
		five_args(stack_a, stack_b);
}
