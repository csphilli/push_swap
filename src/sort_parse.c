/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:41:13 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/30 14:45:48 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	begin_sort(t_stacks *stacks)
{
	// printf("1st STEP\n");
	stacks->head_a = first_step(stacks, stacks->head_a); // sorting correctly.
	// printf("2nd STEP\n");
	stacks = second_step(stacks); // sorting correctly!
}
