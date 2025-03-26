/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:14:28 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/26 04:02:10 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../mandatory/push_swap.h"
# include "get_next_line_bonus/get_next_line_bonus.h"

void	check_input(t_list **stack_a, t_list **stack_b, char *line);
void	push_a(t_list **stack, t_list **sec_stack);
void	push_b(t_list **stack, t_list **sec_stack);
void	rotate_reverse_a(t_list **stack);
void	rotate_reverse_b(t_list **stack);
void	rotate_reverse_both(t_list **stack, t_list **sec_stack);
void	rotate_a(t_list **stack);
void	rotate_b(t_list **stack);
void	rotate_both(t_list **stack, t_list **sec_stack);
void	swap_a(t_list **stack);
void	swap_b(t_list **stack);
void	swap_both(t_list **stack, t_list **sec_stack);

#endif