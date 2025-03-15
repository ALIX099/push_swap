/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:14:22 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/15 04:55:43 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_nums(int ac, char **av)
{
	int	i;
	int	a;

	a = 0;
	while (a < ac)
	{
		i = 0;
		if (av[a][i] == '-' || av[a][i] == '+' || ft_isdigit(av[a][i]))
			i++;
		while (av[a][i])
		{
			if (!ft_isdigit(av[a][i]))
				return (0);
			i++;
		}
		a++;
	}
	return (1);
}

char	*ft_join(char **av, int ac)
{
	char	*str;
	char	*tmp;
	int		a;

	str = ft_strdup("");
	a = 1;
	while (a < ac)
	{
		tmp = ft_strjoin(str, av[a]);
		free(str);
		str = tmp;
		tmp = ft_strjoin(str, " ");
		free(str);
		str = tmp;
		a++;
	}
	return (str);
}

int	check_empty(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int	is_empty(int ac, char **av)
{
	int	a;

	a = 1;
	while (a < ac)
	{
		if (check_empty(av[a]) == 0)
			return (1);
		a++;
	}
	return (0);
}

int	is_duplicate(char **av, int ac)
{
	int i = 0;
	int a = 0;
	while (a < ac)
	{
		i = 0;
		while (av[a][i])
		{
			if (av[a + 1] && ft_atoi(av[a]) == ft_atoi(av[a + 1]))
				return (1);
			i++;
		}
		a++;
	}
	return (0);
}