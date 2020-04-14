/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 19:00:19 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/14 13:13:40 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = create_stacks();

	if (ac > 1)
	{
		stacks = parsing(stacks, ac, av);
		begin_sort(stacks);
	}
	return (0);
}
