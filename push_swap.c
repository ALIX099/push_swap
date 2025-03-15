/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:14:25 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/15 04:55:12 by abouknan         ###   ########.fr       */
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
		return (write(2, "Error\n", 6), NULL);
	array = ft_split(joined_str, ' ');
	if (!array)
		return (free(joined_str), NULL);
	if (!valid_nums(count_array_str(array), array))
		return (free(joined_str), split_free(array, count_array_str(array)),
			NULL);
	if (is_duplicate(array, count_array_str(array)))
		return (free(joined_str), split_free(array, count_array_str(array)),
			NULL);
	return (array);
}

int	main(int ac, char **av)
{
	char	**array;
	int		i;

	i = 0;
	if (ac == 1 || is_empty(ac, av))
		return (write(2, "Error\n", 6), 1);
	array = valid_args(ac, av);
	if (!array)
		return (write(2, "Error\n", 6), 1);
}
