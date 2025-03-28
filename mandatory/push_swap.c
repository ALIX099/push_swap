/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:14:25 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/26 03:38:44 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		**split_free(char **s, int i);

static int	count_array_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	**valid_args(int ac, char **av)
{
	char	**array;
	char	*joined_str;

	joined_str = ft_join(av, ac);
	if (!joined_str)
		return (NULL);
	array = ft_split(joined_str, ' ');
	if (!array)
		return (free(joined_str), NULL);
	if (!valid_nums(count_array_str(array), array))
		return (free(joined_str), split_free(array, count_array_str(array)),
			NULL);
	if (is_duplicate(array, count_array_str(array)))
		return (free(joined_str), split_free(array, count_array_str(array)),
			NULL);
	free(joined_str);
	return (array);
}

t_list	*append(char **array)
{
	int		i;
	int		*value;
	t_list	*head;
	t_list	*stack;

	i = 0;
	head = NULL;
	while (i < count_array_str(array))
	{
		value = malloc(sizeof(int));
		if (!value)
			return (ft_lstclear(&head, free), NULL);
		*value = ft_atoi(array[i]);
		stack = ft_lstnew(value);
		if (!stack)
		{
			free(value);
			ft_lstclear(&head, free);
			return (NULL);
		}
		ft_lstadd_back(&head, stack);
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	char	**array;
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (ac == 1)
		return (0);
	if (is_empty(ac, av))
		return (write(2, "Error\n", 6), 1);
	array = valid_args(ac, av);
	if (!array)
		return (write(2, "Error\n", 6), 1);
	stack_a = append(array);
	if (!stack_a)
		return (split_free(array, count_array_str(array)), write(2, "Error\n",
				6), 1);
	split_free(array, count_array_str(array));
	first_five(&stack_a, &stack_b);
	if (!is_sorted(stack_a))
		sec_algorithme(&stack_a, &stack_b, ft_lstsize(stack_a));
	ft_lstclear(&stack_a, free);
}
