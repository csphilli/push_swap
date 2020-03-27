/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 10:24:22 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/25 16:01:32 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/header/libft.h"
#include <unistd.h>
#define ERROR error()

int		error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

typedef struct	s_lists
{
	int				nbr;
	struct s_lists	*next;;
}				t_lists;

typedef struct	s_stack
{
	t_lists	*head;
}				t_stack;

t_stack		*create_stack(int nbr)
{
	printf("create stack\n");
	t_stack	*tmp;
	t_lists	*new;

	tmp = (t_stack*)ft_memalloc(sizeof(t_stack));
	new = (t_lists*)ft_memalloc(sizeof(t_lists));
	new->nbr = nbr;
	new->next = NULL;
	tmp->head = new;
	printf("new->head->nbr:%d\n", tmp->head->nbr);
	free(new);
	return (tmp);
}

void		add_node(t_stack *stack, int nbr)
{
	// printf("create node\n");
	t_lists	*new;
	new = (t_lists*)ft_memalloc(sizeof(t_lists));
	new->nbr = nbr;
	new->next = NULL;
	stack->head == NULL ? printf("yes\n") : printf("no\n");
	while (stack->head->next != NULL)
	{
		printf("current->head->nbr:%d\n", stack->head->nbr);
		stack->head = stack->head->next;
	}
	stack->head = new;
	// stack->head = new;
	printf("here\n");
	// return (current);
}

void	display_list(t_stack *stack)
{
	int i;

	i = 1;
	while (i < 10)
	{
		printf("list[%d]:%d\n", i, stack->head->nbr); // Change to FT_
		stack->head = stack->head->next;
		i++;
	}
}

t_stack		*assemble_list(int ac, char **av)
{
	int 		i;
	int 		nbr;
	t_stack 	*stacka;
	// t_stack		*current;

	i = 1;
	while (ac-- > 1)
	{
		nbr = ft_atoi(av[i]);
		if (i == 1)
		{
			stacka = create_stack(nbr);
			printf("stack->head->nbr:%d\n", stacka->head->nbr);
		}
		else
			add_node(stacka, nbr);
		i++;
	}
	// free(current);
	return (stacka);
}




// void	run_program(t_stack *stack)
// {
// 	printf("RUN PROGRAM START\n");
// 	// check_for_dupes(stack);
// }

int		main(int ac, char **av)
{
	t_stack *stacka;
	
	stacka = NULL;
	// stacka = create_stack();
	// stacka->head == NULL ? printf("stacka head is NULL\n") : printf("stacka head NOT null\n");
	if (ac > 1)
	{
		stacka = assemble_list(ac, av);
		// run_program(stacka);		
	}
	else
		ERROR; // change to ft_printf once validated
	display_list(stacka);
	free(stacka);
	while (1)
	{
		
	}
	return (0);
}