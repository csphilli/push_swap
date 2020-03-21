/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:26:54 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/22 00:07:37 by csphilli         ###   ########.fr       */
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
	printf("displaying list inside SA\n");
	display_list(list);
	t_lista	*head;
	t_lista *current;

	head = list;
	current = head;
	if (head->next == NULL)
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

t_lista 	*make_structure(void)
{
	t_lista *new;

	if(!(new = (t_lista*)malloc(sizeof(t_lista))))
		return (NULL);
	return (new);
}

t_lista		*do_head(int nbr)
{
	// printf("head->list->nbr:%d\n", list->nbr);
	// printf("head->nbr:%d\n", nbr);
	t_lista *head;
	
	head = make_structure();
	head->nbr = nbr;
	head->next = NULL;
	printf("head->nbr:%d\n", head->nbr);
	return (head);
}

t_lista		*do_new(t_lista *list, int nbr)
{
	printf("head->nbr:%d\n", list->nbr);
	printf("new->nbr:%d\n", nbr);
	t_lista	*new;
	t_lista	*current;
	t_lista	*head;

	head = list;
	new = make_structure();
	current = head;
	printf("current->nbr:%d\n", current->nbr);
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	current = new;
	current->nbr = nbr;
	current->next = NULL;
	printf("new current->nbr:%d\n", current->nbr);
	printf("verify head->nbr:%d\n", head->nbr);
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
		nbr = atoi(av[i]);
		printf("av[%d]:%s\n", i, av[i]);
		if (i == 1)
		{
			printf("do head\n");
			head = do_head(nbr);
			printf("\n");
		}
		else
		{
			printf("do tails\n");
			current = do_new(head, nbr);
			printf("\n");
		}
		// current->next = NULL;
		// fill_structure(current, nbr)
		i++;
	}
	// current->next = NULL;
	// display_list(current);
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
	sa(head);
	printf("\n");
	// display_list(head);
	while (1)
	{
		
	}
	return (0);
}