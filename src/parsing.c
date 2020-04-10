/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:38:20 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/10 03:12:23 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	valid_int(char *str)
{
	intmax_t	nbr;
	char		*tmp;

	tmp = str;
	if (*tmp == '+' || *tmp == '-')
		tmp++;
	while (*tmp)
	{
		if (*tmp > '9' && *tmp < '0')
			ERROR;
		tmp++;
	}
	nbr = ft_atoimax(str);
	if (nbr >= (-2147483647 - 1) && nbr <= 2147483648)
		return (nbr);
	else
		ERROR;
	return (0);
}

// static void	free_strsplit(char ***str)
// {
// 	char *current;

// 	if (str && *str)
// 	{
// 		current = **str;
// 	}
// }

t_stacks *parse_string(t_stacks *stacks, char *str)
{
	int nbr;
	int i;
	char **array;

	array = ft_strsplit(str, 32);
	i = 0;
	while (array[i])
	{
		nbr = valid_int(array[i]);
		push_a(stacks, nbr);
		stacks->ll_a_start++;
		i++;
	}
	// free(&array);
	return (stacks);
}

t_stacks *parse_array(t_stacks *stacks, int ac, char **av)
{
	int i;
	int nbr;

	i = 1;
	while (ac-- > 1)
	{
		nbr = valid_int(av[i]);
		push_a(stacks, nbr);
		stacks->ll_a_start++;
		i++;
	}
	return (stacks);
}

t_stacks *parsing(t_stacks *stacks, int ac, char **av)
{
	if (ac == 2)
		stacks = parse_string(stacks, av[1]);
	else
		stacks = parse_array(stacks, ac, av);
	scan_for_duplicates(stacks);
	return (stacks);
}