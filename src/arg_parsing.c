/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:38:20 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/14 10:43:46 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	Valid int evaluates whether or not the string passed is indeed a valid int.
*/

static int	valid_int(char *str)
{
	intmax_t	nbr;
	char		*tmp;

	tmp = str;
	if (*tmp == '+' || *tmp == '-')
		tmp++;
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
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

/*
**	Frees the memory ft_strsplit uses in the heap.
*/

static void	free_strsplit(char ***array)
{
	char **current;

	if (array && *array)
	{
		current = ((*array));
		while ((*current))
			free((*(current++)));
		free((*array));
		(*array) = NULL;
	}
}

/*
**	First converts numbers from string to number and adds them to a pointer array
**	via ft_strsplit. Then the parser iterates over through the array and adds
**	the numbers to the linked list.
*/

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
	free_strsplit(&array);
	return (stacks);
}

/*
**	Adds numbers to the linked list. Numbers were passed as an argument, not
**	via a string list.
*/

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

/*
**	Evaluates whether or not the argument passed was as string or numbers and
**	then passes the result to the respective function above.
*/

t_stacks *parsing(t_stacks *stacks, int ac, char **av)
{
	if (ac == 2)
		stacks = parse_string(stacks, av[1]);
	else
		stacks = parse_array(stacks, ac, av);
	scan_for_duplicates(stacks);
	return (stacks);
}