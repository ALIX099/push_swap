/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:28:27 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/26 04:03:18 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
static void	ft_error(t_list **stack_a, t_list **stack_b, char *line)
{
	free(line);
	ft_lstclear(stack_a, free);
	ft_lstclear(stack_b, free);
	exit(write(2, "Error\n", 6));
}

void	check_input(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		swap_a(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		swap_b(stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		swap_both(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		rotate_a(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rotate_b(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rotate_both(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		push_a(stack_b, stack_a);
	else if (ft_strcmp(line, "pb\n") == 0)
		push_b(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rotate_reverse_a(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rotate_reverse_b(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rotate_reverse_both(stack_a, stack_b);
	else
		ft_error(stack_a, stack_b, line);
}
