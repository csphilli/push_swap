/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:20:32 by csphilli          #+#    #+#             */
/*   Updated: 2020/04/13 16:17:22 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	exec_parse(t_stacks *stacks, const char *line)
{
	// printf("INSIDE EXEC PARSE\n");
	if (ft_strequ("sa", line))
		sa(stacks, 1);
	else if (ft_strequ("pa", line))
		pa(stacks, 1);
	else if (ft_strequ("pb", line))
		pb(stacks, 1);
	else if (ft_strequ("ra", line))
		ra(stacks, 1);
	else if (ft_strequ("rb", line))
		rb(stacks, 1);
	else if (ft_strequ("rr", line))
		rr(stacks, 1);
	else if (ft_strequ("rra", line))
		rra(stacks, 1);
	else if (ft_strequ("rrb", line))
		rrb(stacks, 1);
	else if (ft_strequ("rrr", line))
		rrr(stacks, 1);
	else
	{
		printf("exec parse error\n"); // Remove before submission.
		ERROR;
	}
	stacks->nbr_moves++;
}

void	checker(t_stacks *stacks, int ac, char **av)
{
	t_stacks *tmp;
	char 	*line;
	int		ret;

	ret = 0;
	tmp = parsing(stacks, ac, av);
	while (get_next_line(0, &line) > 0)
	{
		exec_parse(stacks, line);
		free(line);
	}
	if (ret < 0)
	{
		printf("error in GNL ret\n"); // Remove before submission.
		ERROR;
	}
	check_full_sort(stacks);
	if (stacks->full_sort == true)
		ft_putendl("OK");
	else
		ft_putendl("KO");
}

int		main(int ac, char **av)
{
	t_stacks *stacks;

	stacks = create_stacks();
	if (ac > 1)
		checker(stacks, ac, av);
	else
	{
		printf("checker evaluated to ac < 2\n");
		ERROR;
	}
	printf("nbr_moves: %d\n", stacks->nbr_moves); // Remove before submission.
	// printf("LIST A\n");
	// display_list(stacks->head_a);
	// if (stacks->head_b != NULL)
	// {
	// 	printf("LIST B\n");
	// 	display_list(stacks->head_b);
	// }
	// printf("STATS: ll_a_start:%2d | ll_a_cur:%d | NBR MOVES:%3d | ll_b_cur:%d\n", stacks->ll_a_start,\
	// 	stacks->ll_a_cur, stacks->nbr_moves, stacks->ll_b_cur);
	// free(stacks);
	// while (1)
	// {
		
	// }
}