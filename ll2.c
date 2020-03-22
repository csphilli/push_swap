/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:26:54 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/22 12:09:01 by csphilli         ###   ########.fr       */
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


int		error(void)
{
	printf("Error\n");
	exit(-1);
}

// void		structure(int nbr, int i);
// void		fill_structure(t_lista *list, int nbr);
void		display_list(t_lista *head);
t_lista 	*make_structure(void);
void		add_nbr(int nbr);
t_lista		*do_head(int nbr);
t_lista		*do_new(t_lista *list, int nbr);
t_lista		*run_program(int ac, char **av);
t_lista		*sort(t_lista *head);
t_lista		*ra(t_lista *list);


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
	if (tmp->next == NULL)
		head = sa(head);
	else
	{
		while (tail->next != NULL)
			tail = tail->next;
		tmp = tmp->next;
		head->next = NULL;
		tail->next = head;
		head = tmp;
	}
	return (head);
}

t_lista 	*make_structure(void)
{
	t_lista *new;

	if(!(new = (t_lista*)malloc(sizeof(t_lista))))
		return (NULL);
	return (new);
}

t_lista		*do_head(int nbr)
{
	t_lista *head;
	
	head = make_structure();
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
	new = make_structure();
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	current = new;
	current->nbr = nbr;
	current->next = NULL;
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
	// head = sort(head);
	// run order check to see if in order, else create B
	// head = sort(head);
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
	head = sa(head);
	head = ra(head);
	
	printf("\n");
	display_list(head);
	// display_list(head);
	// while (1)
	// {
		
	// }
	return (0);
}