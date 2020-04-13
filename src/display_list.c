/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 10:34:16 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/13 16:15:02 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	A function to display the list. Very useful for debugging or can be
**	implemented to display the final sorted list.
*/

void		display_list(t_lists *list)
{
	int 	i;
	t_lists *tmp;

	i = 1;	
	tmp = list;
	if (tmp)
	{
		while (tmp != NULL)
		{
			printf("address:%p | list[%2d]:%3d | next:%p\n", tmp, i, tmp->nbr, tmp->next); // change to ft_printf
			tmp = tmp->next;
			i++;
		}
	}
}
