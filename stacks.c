#include <stdio.h>
#include <stdlib.h>
#include "../libft/header/libft.h"
#define ERROR error()

void	error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}


typedef struct s_lists
{
	int		nbr;
	struct s_lists *next;
}				t_lists;

typedef struct s_stacks
{
	t_lists *head_a;
	t_lists	*head_b;
}				t_stacks;

t_stacks	*create_stacks(void);
t_lists		*create_new_node(int nbr);
t_stacks	*initialize_stacks(t_stacks *stack);
void		display_stack_a(t_stacks *stack);
void		insert_node(t_stacks *stacks, int nbr);
void		check_for_duplicates(t_stacks *stacks);

t_stacks	*create_stacks(void)
{
	t_stacks *new;

	new = (t_stacks*)malloc(sizeof(t_stacks));
	new = initialize_stacks(new);
	return (new);
}

t_lists		*create_new_node(int nbr)
{
	t_lists *new;

	new = (t_lists*)malloc(sizeof(t_lists));	
	new->nbr = nbr;
	new->next = NULL;
	return (new);
}


t_stacks	*initialize_stacks(t_stacks *stack)
{
	stack->head_a = NULL;
	stack->head_b = NULL;
	return (stack);
}

void		display_stack_a(t_stacks *stack)
{
	int i;

	i = 1;
	t_lists *tmp;
	tmp = stack->head_a;
	if (tmp)
	{
		while (tmp != NULL)
		{
			printf("address:%p | list[%d]:%d | next:%p\n", tmp, i, tmp->nbr, tmp->next); // change to ft_printf
			tmp = tmp->next;
			i++;
		}
	}
}

// void		insert_at_head(t_stacks *stacks, t_lists *node)
// {
// 	if (stacks && node)
// 		if (!stacks->head_a)
// 			stacks->head_a = node;
// }

// void		insert_at_tail(t_stacks *stacks, t_lists *node)
// {
// 	t_lists *tmp;

// 	tmp = stacks->head_a;
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	tmp->next = node;
// }

void		insert_node(t_stacks *stacks, int nbr)
{
	t_lists *tmp;
	t_lists *node;

	node = create_new_node(nbr);
	tmp = stacks->head_a;
	if (stacks && node)
	{
		if (!stacks->head_a)
			stacks->head_a = node;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = node;
		}
	}
}

void	check_for_duplicates(t_stacks *stacks)
{
	t_lists *base;
	t_lists *iterate;

	base = stacks->head_a;
	iterate = base;
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

void	run_program(t_stacks *stacks, int ac, char **av)
{
	int			nbr;
	int			i;

	i = 1;
	while (ac-- > 1)
	{
		nbr = ft_atoi(av[i]);
		insert_node(stacks, nbr);
		i++;
	}
	check_for_duplicates(stacks);
	display_stack_a(stacks);
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;
	stacks = create_stacks();
	if (ac > 1)
		run_program(stacks, ac, av);
	else
		ERROR;

	while (1)
	{

	}

	return (0);
}

/*

#include <stdio.h>
#include <stdlib.h>



typedef struct s_lists
{
    int        nbr;
    struct s_lists *next;
}                t_lists;

typedef struct s_stacks
{
    t_lists *head_a;
    t_lists    *head_b;
}                t_stacks;
void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char *ptr;

    ptr = (unsigned char*)b;
    while (len-- > 0)
        *(ptr++) = (unsigned char)c;
    return (b);
}


void    ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}

void    *ft_memalloc(size_t size)
{
    void    *mem;

    if (!(mem = malloc(size)))
        return (NULL);
    ft_bzero(mem, size);
    return (mem);
}

t_stacks    *create_new_stack(void)
{
    t_stacks *new;

    new = (t_stacks*)ft_memalloc(sizeof(t_stacks));
    return (new);
}

t_lists        *create_new_node(int nbr)
{
    t_lists *new;

    new = (t_lists*)ft_memalloc(sizeof(t_lists));
    new->nbr = nbr;
    new->next = NULL;
    return (new);
}


t_stacks    *initialize_stacks(t_stacks *stack)
{
    stack->head_a = NULL;
    stack->head_b = NULL;

    return (stack);
}

void        display_stack_a(t_stacks *stack)
{
    int i;

    i = 1;
    if (stack->head_a)
    {
        while (stack->head_a != NULL)
        {
            printf("list[%d]:%d\n", i, stack->head_a->nbr);
            stack->head_a = stack->head_a->next;
            i++;
        }
    }
}

t_stacks        *insert_at_head(t_stacks *stacks, t_lists *node)
{
    
    if (stacks && node)
    {
        if (!stacks->head_a)
        {
            printf("!stack->head_a\n");
            
            stacks->head_a = node;
            // printf("stack->head_a->nbr:%d\n", stacks->head_a->nbr);
            // printf("stack->head->address:%p\n", stacks->head_a);
            // printf("stack->next->address:%p\n", stacks->head_a->next);
            // printf("stack->head_a->address:%p\n", stacks->head_a);
        }
    }
    return (stacks);
}

t_stacks        *insert_at_tail(t_stacks *stacks, int nbr)
{
    // printf("node->nbr:%d\tnode->next:%p\n", node->nbr, node->next);
    // printf("stacks->head:%p\n", stacks->head_a);
    // printf("stacks->head:%p\n", stacks->head_a);
    t_lists *node;
    t_lists *tmp;
    
    tmp = stacks->head_a;
    node = create_new_node(nbr);

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
    // stacks = tmp;
    return (stacks);    
}

int    main(void)
{
    int nbr1 = 1;
    int nbr2 = 2;
    int nbr3 = 3;
    t_stacks *stacks;
    t_lists *node;

    node = create_new_node(nbr1);

    stacks = create_new_stack();
    stacks = insert_at_head(stacks, node);
    // node = create_new_node(nbr2);
    insert_at_tail(stacks, nbr2);
    display_stack_a(stacks);
    // printf("head_a->nbr:%d\t| next: %p\n", stacks->head_a->nbr, stacks->head_a->next);
    


    return (0);
}
*/