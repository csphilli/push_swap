#include "../includes/push_swap.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include "../includes/push_swap.h"
// #define ERROR error()

// void	error(void)
// {
// 	write(2, "Error\n", 6);
// 	exit(-1);
// }


// typedef struct s_lists
// {
// 	int		nbr;
// 	struct s_lists *next;
// }				t_lists;

// typedef struct s_stacks
// {
// 	t_lists *head_a;
// 	t_lists	*head_b;
// 	int		midpoint;
// 	int		list_len_start;
// 	int		nbr_moves;
// }				t_stacks;

// t_stacks	*create_stacks(void);
// t_lists		*create_new_node(int nbr);
// t_stacks	*initialize_stacks(t_stacks *stack);
// void		display_list(t_lists *list);
// void		insert_node(t_stacks *stacks, int nbr);
// void		check_for_duplicates(t_stacks *stacks);

// t_stacks	*create_stacks(void)
// {
// 	t_stacks *new;

// 	new = (t_stacks*)malloc(sizeof(t_stacks));
// 	new = initialize_stacks(new);
// 	return (new);
// }

// t_lists		*create_new_node(int nbr)
// {
// 	t_lists *new;

// 	new = (t_lists*)malloc(sizeof(t_lists));	
// 	new->nbr = nbr;
// 	new->next = NULL;
// 	return (new);
// }


// t_stacks	*initialize_stacks(t_stacks *stack)
// {
// 	stack->head_a = NULL;
// 	stack->head_b = NULL;
// 	stack->midpoint = 0;
// 	stack->list_len_start = 0;
// 	stack->nbr_moves = 0;
// 	return (stack);
// }

// void		display_list(t_lists *list)
// {
// 	int i;

// 	i = 1;
// 	t_lists *tmp;
// 	tmp = list;
// 	if (tmp)
// 	{
// 		while (tmp != NULL)
// 		{
// 			printf("address:%p | list[%2d]:%3d | next:%p\n", tmp, i, tmp->nbr, tmp->next); // change to ft_printf
// 			// printf("seg fault here?\n");
// 			tmp = tmp->next;
// 			// printf("or here?\n");
// 			i++;
// 		}
// 	}
// }

// void		insert_node(t_stacks *stacks, int nbr)
// {
// 	t_lists *tmp;
// 	t_lists *node;

// 	node = create_new_node(nbr);
// 	tmp = stacks->head_a;
// 	if (stacks && node)
// 	{
// 		if (!stacks->head_a)
// 			stacks->head_a = node;
// 		else
// 		{
// 			while (tmp->next != NULL)
// 				tmp = tmp->next;
// 			tmp->next = node;
// 		}
// 		stacks->list_len_start++;
// 	}
// }

// void	check_for_duplicates(t_stacks *stacks)
// {
// 	t_lists *base;
// 	t_lists *iterate;

// 	base = stacks->head_a;
// 	iterate = base;
// 	if (base->next != NULL)
// 	{
// 		while (base->next != NULL)
// 		{
// 			iterate = base->next;
// 			while (iterate != NULL)
// 			{
// 				if (iterate->nbr == base->nbr)
// 					ERROR;
// 				iterate = iterate->next;
// 			}
// 			base = base->next;
// 		}
// 	}
// }

// t_lists		*rotate_list(t_stacks *stacks, t_lists *list) // this needs to be part of checker
// {
// 	t_lists *tmp;
// 	t_lists *head;
// 	t_lists *tail;

// 	tmp = list;
// 	head = tmp;
// 	tail = tmp;
// 	// printf("ROTATE LIST - LIST START\n");
// 	// display_list(head);
// 	if (tmp != NULL || tmp->next != NULL)
// 	{
// 		while (tail->next != NULL)
// 			tail = tail->next;
// 		tail->next = tmp;
// 		head = head->next;
// 		tmp->next = NULL;
// 		stacks->nbr_moves++;
// 	}
// 	return (head);
// }

// t_lists		*swap_list(t_lists *list)
// {
// 	// printf("SWAP LIST - LIST START\n");
// 	t_lists *head;
// 	t_lists *second;

// 	head = list;
// 	second = head;
// 	// display_list(head);
// 	if (second->next != NULL)
// 	{
// 		second = second->next;
// 		if (second->next != NULL)
// 		{
// 			head->next = second->next;
// 			second->next = head;
// 			head = second;
// 		}
// 		else
// 		{
// 			second->next = head;
// 			head->next = NULL;
// 			head = second;
// 		}		
// 	}
// 	// printf("SWAP LIST - LIST END\n");
// 	// display_list(head);
// 	return (head);	
// }

// t_lists		*first_step(t_stacks *stacks, t_lists *list_a)
// {
// 	t_lists *head_a;
// 	t_lists	*tail_a;
	
// 	head_a = list_a;
// 	tail_a = head_a;
// 	if (head_a->next != NULL)
// 	{
// 		while (tail_a->next != NULL)
// 			tail_a = tail_a->next;
// 		if (head_a->nbr > tail_a->nbr)
// 		{
// 			// display_list(head_a);
// 			head_a = first_step(stacks, rotate_list(stacks, head_a));
// 			// Each time i execute this step, i must output "ra" for GNL to pick up.
// 			// printf("\n");
// 		}
// 	}
// 	return (head_a);
// }

// t_lists		*list_pop(t_lists *list)
// {
// 	// printf("POP LIST - LIST START\n");
	
// 	t_lists *tmp;
// 	t_lists *head;

// 	head = list;
// 	tmp = head;
// 	// display_list(head);
// 	head = tmp->next;
// 	tmp->nbr = '\0';
// 	tmp->next = NULL;
// 	free(tmp);
// 	// printf("POP LIST - AFTER POP\n");
// 	// display_list(head);
// 	return (head);
// }

// t_lists		*list_push(int nbr, t_lists *list)
// {
// 	// printf("PUSH LIST - LIST START\n");	
// 	// printf("nbr sent:%d\n", nbr);
// 	t_lists	*head;
// 	t_lists *tmp;
// 	t_lists	*node;

// 	head = list;
// 	tmp = head;
// 	display_list(head);
// 	node = create_new_node(nbr);
// 	if (!list)
// 		head = node;
// 	else
// 	{
// 		node->next = head;
// 		head = node;
// 	}
// 	// printf("PUSH LIST - LIST AFTER PUSH\n");
// 	// display_list(head);
// 	return (head);
// }

// t_stacks	*pb(t_stacks *stacks)
// {
// 	// printf("PUSH B - LISTS START\n");
	
// 	t_stacks 	*tmp;
// 	t_lists		*head_a;
// 	t_lists		*head_b;

// 	tmp = stacks;
// 	head_a = tmp->head_a;
// 	head_b = tmp->head_b;
// 	// printf("HEAD_A\n");
// 	// display_list(head_a);
// 	// printf("HEAD_B\n");
// 	// display_list(head_b);
// 	tmp->head_b = list_push(head_a->nbr, head_b);
// 	tmp->head_a = list_pop(head_a);
// 	// printf("LISTS AFTER PB FINISHES\n");
// 	// display_list(tmp->head_a);
// 	// display_list(tmp->head_b);
// 	return (tmp);
// 	// pop removes the top element of the list.
// 	// push adds an element to the top of the stack.

// }

// t_stacks	*longer_second_step(t_stacks *stacks)
// {
// 	t_stacks *tmp;
// 	t_lists	*head_a;
// 	t_lists	*tail_a;

// 	tmp = stacks;
// 	head_a = tmp->head_a;
// 	tail_a = tmp->head_a;
// 	while (tail_a->next != NULL)
// 		tail_a = tail_a->next;
// 	if (head_a->nbr < tail_a->nbr)
// 	{
// 		tmp = pb(tmp);
// 		// printf("VERIFYING LISTS AFTER RETURN FROM PB\n");
// 		// display_list(tmp->head_a);
// 		// display_list(tmp->head_b);
// 		tmp->midpoint++;
// 		// printf("MIDPOINT VALUE:%d\n", tmp->midpoint);
// 	}
// 	else
// 		tmp->head_a = swap_list(tmp->head_a);
// 	tmp->head_a = rotate_list(tmp, tmp->head_a);
// 	// printf("LISTS AFTER LONGER SECOND STEP\n");
// 	// display_list(tmp->head_a);
// 	// printf("\n");
// 	// display_list(tmp->head_b);
// 	return (tmp);
// }

// t_stacks	*second_step(t_stacks *stacks)
// {
// 	bool check;
// 	t_stacks *tmp;
// 	t_lists	*head_a;
// 	t_lists	*tail_a;
// 	int i;

// 	i = 1;
// 	tmp = stacks;
// 	head_a = tmp->head_a;
// 	tail_a = tmp->head_a;
// 	check = true;
// 	while (check)
// 	{

// 		// printf("SECOND STEP START - ROUND %d\n", i);
// 		// printf("LIST A START\n");
// 		// display_list(tmp->head_a);
// 		// printf("LIST B START\n");
// 		// display_list(tmp->head_b);
// 		// printf("seg fault thrice\n");
// 		i++;
// 		tail_a = tmp->head_a;
// 		head_a = tmp->head_a;
// 		// printf("seg fault fourth\n");
// 		while (tail_a->next != NULL)
// 			tail_a = tail_a->next;
// 		// printf("tail_a->nbr:%d\n", tail_a->nbr);
// 		// printf("head_a->nbr:%d | ", head_a->nbr);
// 		// printf("head_a->next->nbr:%d | ", head_a->next->nbr);
// 		// printf("tail_a->nbr:%d\n", tail_a->nbr);
// 		if (head_a->nbr > head_a->next->nbr && head_a->nbr < tail_a->nbr)
// 		{
// 			// printf("FIRST IF - SWAP A - START LIST\n");
// 			// display_list(tmp->head_a);
// 			tmp->head_a = swap_list(tmp->head_a);
// 			// printf("FIRST IF - SWAP A - RESULT\n");
// 			// display_list(tmp->head_a);
// 			// tmp->head_a = swap_list(tmp->head_a);
// 		}
// 		else if (head_a->nbr > head_a->next->nbr && head_a->nbr > tail_a->nbr)
// 		{
// 			// printf("SECOND IF - ROTATE A\n");
// 			tmp->head_a = rotate_list(tmp, tmp->head_a);
// 			// printf("SECOND IF - ROTATE A - RESULT\n");
// 			// display_list(tmp->head_a);
// 			// tmp->head_a = rotate_list(tmp->head_a);
// 		}
// 		else if (head_a->next->nbr > tail_a->nbr && head_a->next != NULL)
// 		{
// 			// printf("SENT TO LONG SECOND STEP\n");
// 			tmp = longer_second_step(tmp);
// 			// printf("VERIFYING LISTS RETURNED TO LONG 2nd STEP\n");
// 			// display_list(tmp->head_a);
// 			// display_list(tmp->head_b);

// 		}
// 		else
// 		{
// 			// printf("CHANGING TO FALSE\n");
// 			check = false;
// 		}
// 	}
// 	return (tmp);
// }

// void	begin_sort(t_stacks *stacks)
// {
// 	// printf("1st STEP\n");
// 	stacks->head_a = first_step(stacks, stacks->head_a); // sorting correctly.
// 	// printf("2nd STEP\n");
// 	stacks = second_step(stacks); // sorting correctly!
// }

// t_stacks	*run_program(t_stacks *stacks, int ac, char **av)
// {
// 	int			nbr;
// 	int			i;

// 	i = 1;
// 	while (ac-- > 1)
// 	{
// 		nbr = ft_atoi(av[i]);
// 		insert_node(stacks, nbr);
// 		i++;
// 	}
// 	check_for_duplicates(stacks);
// 	begin_sort(stacks);
// 	// printf("PRINTING STACKS IN RUN PROGRAM\n");
// 	// printf("LIST A\n");
// 	// display_list(stacks->head_a);
// 	// printf("LIST B\n");
// 	// display_list(stacks->head_b);
// 	return (stacks);
// }

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	stacks = create_stacks();
	if (ac > 1)
		stacks = run_program(stacks, ac, av);
	else
		ERROR;
	printf("LIST A\n");
	display_list(stacks->head_a);	
	printf("LIST B\n");	
	display_list(stacks->head_b);
	printf("STATS: LIST_LEN_START:%2d | NBR MOVES:%3d\n", stacks->list_len_start,\
		stacks->nbr_moves);
	while (1)
	{

	}

	return (0);
}
