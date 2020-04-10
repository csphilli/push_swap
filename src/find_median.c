/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 14:11:30 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/10 23:40:06 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		sort_array(long *array, int len)
{
	int i;
	long tmp;

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

int 			find_median(t_lists *list_a)
{
	int 	len;
	int 	i;
	int		median;
	long	*arr;

	len = ll(list_a);
	if (!(arr = (long*)malloc(sizeof(long) * len)))
		ERROR;
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

int 	count_below_median(t_lists *list)
{
	int median;
	int count;

	median = find_median(list);
	count = 0;
	while (list)
	{
		if (list->nbr <= median)
			count++;
		list = list->next;
	}
	return (count);
}
