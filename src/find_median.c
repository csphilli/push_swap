/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:11:30 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/18 10:24:44 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		sort_array(long *array, int len)
{
	int		i;
	long	tmp;

	i = 0;
	while (i < len - 1)
	{
		if (array[i] < array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

int				find_median(t_stacks *stacks, t_lists *list_a)
{
	int		len;
	int		i;
	int		median;
	long	*arr;

	len = ll(list_a);
	if (!(arr = (long*)malloc(sizeof(long) * len)))
	{
		stacks->advanced == 1 ? ft_printf(ER_MALLOC) : ft_printf(ERROR);
		exit(-1);
	}
	i = -1;
	while (++i < len)
	{
		arr[i] = list_a->nbr;
		list_a = list_a->next;
	}
	sort_array(arr, len);
	median = arr[len / 2];
	free(arr);
	return (median);
}
