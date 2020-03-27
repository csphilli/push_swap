/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:26:54 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/26 10:20:22 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#define ERROR error()
#include "../libft/header/libft.h" // I'm using my own library for ft_atoi but atoi will suffice.



typedef struct 	s_lista
{
	int 	nbr;
	struct 	s_lista *next;
}				t_lista;

typedef struct	s_values
{
	int	midpoint;
}				t_values;

typedef struct	s_stack
{
	struct s_lista *lista;
	struct s_lista *listb;
}				t_stack;

int		error(void)
{
	printf("Error\n");
	exit(-1);
}

// void		structure(int nbr, int i);
// void		fill_structure(t_lista *list, int nbr);
void		display_list(t_lista *head);
t_lista 	*make_list_structure(void);
t_values 	*make_value_structure(void);
void		add_nbr(int nbr);
t_lista		*do_head(int nbr);
t_lista		*do_new(t_lista *list, int nbr);
t_lista		*run_program(int ac, char **av);
t_lista		*sort(t_lista *head);
void		duplicate_check(t_lista *list);
t_lista		*ra(t_lista *list);
t_lista		*rra(t_lista *list);
t_lista		*sort(t_lista *list);
t_lista		*step_one(t_lista *lista);
t_lista		*step_two(t_lista *lista);//, t_values *values);


void	display_list(t_lista *head)
{
	t_lista *p;
	int i;

	p = head;
	i = 1;
	while (p != NULL)
	{
		printf("list->[%d]:%d\n", i, p->nbr);
		p = p->next;
		i++;
	}
}



t_lista	 *sa(t_lista *list)
{
	t_lista	*head;
	t_lista *current;

	head = list;
	current = head;
	if (head == NULL || head->next == NULL)
		ERROR;
	current = current->next;
	if (current->next != NULL)
	{
		head->next = current->next;
		current->next = head;
		head = current;
	}
	else
	{
		current->next = head;
		head->next = NULL;
		head = current;		
	}
	return (head);
}

t_lista		*ra(t_lista *list)
{
	t_lista	*head;
	t_lista *tail;
	t_lista	*tmp;

	head = list;
	tail = head;
	tmp = head;
	if (head == NULL || head->next == NULL)
		ERROR;
	tmp = tmp->next;
	if (tmp->next == NULL)
		head = sa(head);
	else
	{
		while (tail->next != NULL)
			tail = tail->next;
		head->next = NULL;
		tail->next = head;
		head = tmp;
	}
	return (head);
}

t_lista		*rra(t_lista *list)
{
	t_lista	*head;
	t_lista *tail;
	t_lista	*tmp;

	head = list;
	tail = head;
	tmp = head;
	if (head == NULL || head->next == NULL)
		ERROR;
	tmp = tmp->next;
	if (tmp->next == NULL)
		head = sa(head);
	else
	{
		while (tail->next != NULL)
			tail = tail->next;
		while (tmp->next != tail)
			tmp = tmp->next;
		tail->next = head;
		tmp->next = NULL;
		head = tail;
	}
	return (head);
}

t_lista 	*make_list_structure(void)
{
	t_lista *new;

	new = (t_lista*)ft_memalloc(sizeof(t_lista));
	return (new);
}

t_values 	*make_value_structure(void)
{
	t_values *new;

	new = (t_values*)ft_memalloc(sizeof(t_values));
	return (new);
}

t_lista		*do_head(int nbr)
{
	t_lista *head;
	
	head = make_list_structure();
	head->nbr = nbr;
	head->next = NULL;
	return (head);
}

t_lista		*do_new(t_lista *list, int nbr)
{
	t_lista	*new;
	t_lista	*current;
	t_lista	*head;

	head = list;
	new = make_list_structure();
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	current = new;
	current->nbr = nbr;
	current->next = NULL;
	return (head);	
}

void		duplicate_check(t_lista *list)
{
	t_lista *base;
	t_lista *iterate;

	base = list;
	if (base->next != NULL)
	{
		while (base->next != NULL)
		{
			iterate = base->next;
			while (iterate != NULL)
			{
				if (iterate->nbr == base->nbr)
					ERROR;
				iterate = iterate->next;
			}
			base = base->next;
		}
	}
}

t_lista		*sort(t_lista *list)
{
	t_lista *a;
	// t_values *values;

	a = list;
	// values = make_value_structure();
	a = step_one(a);
	a = step_two(a);
	printf("printing list before exit sorting\n");
	display_list(a);
	return (a);

}

t_lista		*step_one(t_lista *lista)
{
	t_lista *head;
	t_lista *tail;
	head = lista;
	tail = head;
	if (head->next != NULL)
	{
		while (tail->next != NULL)
			tail = tail->next;
		if (head->nbr > tail->nbr)
			head = step_one(ra(head));		
	}
	return (head);
}

t_lista		*pb(t_lista *listb, int nbr)
{
	t_lista *head;
	t_lista *tmp;
	// t_lista	*new;
	

	head = listb;
	tmp = head;
	if (head == NULL)
	{
		head->nbr = nbr;
		head->next = NULL;
	}
	else
	{
		tmp->nbr = nbr;
		tmp->next = head;
		head->next = NULL;
		head = tmp;
	}
	// lista = lista->next;
	// free(tmp);
	return (head);
}

t_lista	 *delete_node(t_lista *list)
{
	t_lista *tmp;
	t_lista *head;

	head = list;
	tmp = head;
	tmp = tmp->next;
	head = tmp;
	free(tmp);
	return (head);
}

t_lista		*step_two(t_lista *lista)//, t_values *values)
{
	t_lista *head_a;
	t_lista	*second_a;
	t_lista	*tail_a;
	t_lista	*head_b;
	int		i;

	head_a = lista;
	second_a = head_a;
	tail_a = head_a;
	head_b = make_list_structure();
	while (tail_a->next != NULL)
		tail_a = tail_a->next;
	second_a = second_a->next; 
	i = 1;
	printf("sorting\n");
	while (i < 2)
	{
		printf("BEGIN SORTING. LIST A\n");
		display_list(head_a);
		printf("BEGIN SORTING. LIST B\n");
		display_list(head_b);
		if (head_a->nbr > second_a->nbr && head_a->nbr < tail_a->nbr)
		{
			printf("first if\n");
			head_a = sa(head_a);
		}
		else if (head_a->nbr > second_a->nbr && head_a->nbr > tail_a->nbr)
		{
			printf("2nd if\n");
			head_a = ra(head_a);
		}
		else if (second_a->nbr > tail_a->nbr && second_a->next != NULL)
		{
			// printf("3rd if\n");
			if (head_a->nbr < tail_a->nbr)
			{
				// SEG Faulting here. need to start working with 2 lists.
				printf("4th if\n");
				// printf("head_a->nbr:%d\n", head_a->nbr);
				head_b = pb(head_b, head_a->nbr);
				// display_list(head_b);
				head_a = delete_node(head_a);
				printf("PRINTING LIST A\n");
				display_list(head_a);
				printf("PRINTING LIST B\n");
				display_list(head_b);
				// printf("last statement\n");
				// values->midpoint++;
			}
			else
			{
				printf("4th IF ELSE WITH SA\n");
				head_a = sa(head_a);
			}
			printf("ROTATING HEAD_A\n");
			head_a = ra(head_a);
		}
		else
		{
			printf("hit else\n");
			i++;
		}
	}
	printf("printing lists before exiting step two\n");
	display_list(head_a);
	display_list(head_b);
	free(head_b);
	return (head_a);
}

t_lista	 *run_program(int ac, char **av)
{
	int		nbr;
	int		i;
	t_lista	*head;
	t_lista *current;
	
	i = 1;
	head = NULL;
	current = NULL;
	while (ac-- > 1)
	{
		nbr = atoi(av[i]); // Change to ft_atoi
		if (i == 1)
			head = do_head(nbr);
		else
			current = do_new(head, nbr);
		i++;
	}
	duplicate_check(head);
	if (i > 1)
		head = sort(head);
	printf("exiting run program function\n");
	printf("printing another list inside run program\n");
	display_list(head);
	printf("done printing that list\n");
	// run order check to see if in order, else create B
	return (head);
}

void		fill_structure(t_lista *list, int nbr)
{
	list->nbr = nbr;
}

/*
I'm compiling with gcc -Wall -Wextra -Werror.
then giving arguments via command line such as ./a.out 1 2 3 4
*/

int	main(int ac, char **av)
{
	t_lista	*head;

	head = NULL;
	if (ac > 1)
		head = run_program(ac, av);
	else
		ERROR;
	display_list(head);
	while (1)
	{
		
	}
	return (0);
}