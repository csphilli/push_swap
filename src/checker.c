/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:20:32 by csphilli          #+#    #+#             */
/*   Updated: 2020/06/16 23:26:13 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	exec_parse(t_stacks *stacks, const char *line)
{
	if (ft_strequ("sa", line))
		sa(stacks, 1);
	else if (ft_strequ("sb", line))
		sb(stacks, 1);
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
		ERROR;
}

void	checker(t_stacks *stacks, int ac, char **av)
{
	t_stacks	*tmp;
	char		*line;
	int			ret;

	ret = 0;
	tmp = parsing(stacks, ac, av);
	while (get_next_line(0, &line) > 0)
	{
		exec_parse(stacks, line);
		free(line);
	}
	if (ret < 0)
		ERROR;
	check_full_sort(stacks);
	if (stacks->full_sort == true)
		ft_printf("OK");
	else
		ft_printf("KO");
}

int		main(int ac, char **av)
{
	t_stacks *stacks;

	stacks = create_stacks();
	if (ac > 1)
		checker(stacks, ac, av);
}
