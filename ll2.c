/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:26:54 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/22 20:09:22 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#define ERROR error()
// #include "../libft/header/libft.h" // I'm using my own library for ft_atoi but atoi will suffice.



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
t_lista		*step_two(t_lista *lista, t_values *values);


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

	if(!(new = (t_lista*)malloc(sizeof(t_lista))))
		return (NULL);
	return (new);
}

t_values 	*make_value_structure(void)
{
	t_values *new;

	if(!(new = (t_values*)malloc(sizeof(t_values))))
		return (NULL);
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
	t_values *values;

	a = list;
	values = make_value_structure();
	a = step_one(a);
	a = step_two(a, values);
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

t_lista		*pb(t_lista *lista, t_lista *listb)
{
	t_lista *head;
	t_lista	*new;
	t_lista *tmp;

	head = listb;
	tmp = lista;
	new = NULL;
	if (head == NULL)
	{
		head->nbr = lista->nbr;
		head->next = NULL;
	}
	else
	{
		new->nbr = lista->nbr;
		new->next = head;
		head = new;
	}
	lista = lista->next;
	free(tmp);
	return (head);
}

t_lista		*step_two(t_lista *lista, t_values *values)
{
	t_lista *head;
	t_lista	*second;
	t_lista	*tail;
	t_lista	*b;
	int		i;

	head = lista;
	second = head;
	tail = head;
	b = make_list_structure();
	while (tail->next != NULL)
		tail = tail->next;
	second = second->next; 
	i = 1;
	while (i == 1)
	{
		if (head->nbr > second->nbr && head->nbr < tail->nbr)
			head = sa(head);
		else if (head->nbr > second->nbr && head->nbr > tail->nbr)
			head = ra(head);
		else if (second->nbr > tail->nbr)
		{
			if (head->nbr < tail->nbr)
			{
				// SEG Faulting here. need to start working with 2 lists.
				printf("inside if\n");
				head = pb(head, b);
				b = pb(head, b);
				values->midpoint++;
			}
			else
				head = sa(head);
			head = ra(head);
		}
		else
			i = 0;
	}
	return (head);
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
	head = sort(head);
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
	// while (1)
	// {
		
	// }
	return (0);
}