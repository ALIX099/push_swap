/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:14:28 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/15 04:25:29 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				element;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
}					t_stack;

long				ft_atoii(char *str);
int					check_empty(char *str);
int					check_digit(char **str, int ac);
int					is_empty(int ac, char **av);
int					check_sign(char **str, int ac);
char				*ft_join(char **av, int ac);
void				free_array(char **array);
int					valid_nums(int ac, char **av);
int					is_duplicate(char **av, int ac);

#endif