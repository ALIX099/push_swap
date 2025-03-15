/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouknan <abouknan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:14:22 by abouknan          #+#    #+#             */
/*   Updated: 2025/03/15 06:15:01 by abouknan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_nums(int ac, char **av)
{
	int	i;
	int	a;
	long	num;

	a = 0;
	while (a < ac)
	{
		i = 0;
		if (av[a][i] == '-' || av[a][i] == '+')
			i++;
		if (!ft_isdigit(av[a][i]))
			return (0);
		while (av[a][i])
		{
			if (!ft_isdigit(av[a][i]))
				return (0);
			i++;
		}
		num = ft_atoi(av[a]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
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
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}