/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:14:28 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/22 07:32:40 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>

int		is_empty(int ac, char **av);
char	*ft_join(char **av, int ac);
int		valid_nums(int ac, char **av);
int		is_duplicate(char **av, int ac);
void	sx(t_list **stack_a);
void	rx(t_list **stack_a);
void	rrx(t_list **stack);
void	px(t_list **stack, t_list **sec_stack);
void	free_list(t_list *head);
int		is_sorted(t_list *stack);
void	first_five(t_list *stack_a, t_list *stack_b);
void	pa(t_list **stack, t_list **sec_stack);
void	pb(t_list **stack, t_list **sec_stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack, t_list **sec_stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack, t_list **sec_stack);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack, t_list **sec_stack);
t_list	*mini_node(t_list *stack);

#endif