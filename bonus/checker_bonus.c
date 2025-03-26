/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 04:15:55 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/26 04:39:37 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

	if (ac == 1)
		exit(0);
	if (is_empty(ac, av))
		return (NULL);
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
	if (!array)
		exit(write(2, "Error\n", 6));
	while (i < count_array_str(array))
	{
		value = malloc(sizeof(int));
		if (!value)
			return (ft_lstclear(&head, free), NULL);
		*value = ft_atoi(array[i]);
		stack = ft_lstnew(value);
		if (!stack)
			return (free(value), ft_lstclear(&head, free), NULL);
		ft_lstadd_back(&head, stack);
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	char	**array;
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	array = valid_args(ac, av);
	stack_a = append(array);
	if (!stack_a)
		return (split_free(array, count_array_str(array)), write(2, "Error\n",
				6), 1);
	split_free(array, count_array_str(array));
	line = get_next_line(0);
	while (line)
	{
		check_input(&stack_a, &stack_b, line);
		line = get_next_line(0);
	}
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (ft_lstclear(&stack_a, free), ft_lstclear(&stack_b, free), 0);
}
