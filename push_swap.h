/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:14:28 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/20 00:44:16 by abouknan         ###   ########.fr       */
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
#endif