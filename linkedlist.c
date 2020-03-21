/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 08:00:32 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/19 14:36:45 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct  s_list
{
	int				nbr;
	struct s_list 	*next;
}               t_list;

typedef struct s_cmp
{
	int	i;
	int	a_head;
	int	a_n;
	int	a_tail_m_one;
	int	a_tail;
	int	b_head;
	int	b_n;
	int	b_tail_m_one;
	int b_tail;
}				t_cmp;



t_list	*create_list_p1(int n, t_cmp *cmp);
void	display_list(t_list *list);
t_cmp	*init(t_cmp *cmp);
t_list 	*create_list_p2(int n, t_cmp *cmp, t_list *tmp);

int main()
{
	int n;
	t_cmp	*cmp;
	t_list	*list;

	cmp = NULL;
	if (!(cmp = (t_cmp*)malloc(sizeof(t_cmp))))
		return (-1);
	init(cmp);
	printf("List size?: ");
	scanf("%d", &n);
	list = create_list_p1(n, cmp);
	display_list(list);
	cmp_list(list, cmp);
	printf("a_head = %d\n", cmp->a_head);
	printf("a_n = %d\n", cmp->a_n);
	printf("a tail minus 1 = %d\n", cmp->a_tail_m_one);
	printf("tails = %d\n", cmp->a_tail);
	// while (1)
	// {
		
	// }
	
}

t_cmp	*init(t_cmp *cmp)
{
	cmp->i = 0;
	cmp->a_head = 0;
	cmp->a_n = 0;
	cmp->a_tail_m_one = 0;
	cmp->a_tail = 0;
	cmp->b_head = 0;
	cmp->b_n = 0;
	cmp->b_tail_m_one = 0;
	cmp->b_tail = 0;
	return cmp;
}

void    display_list(t_list *list)
{
	t_list *p;

	p = list;
	while (p != NULL)
	{
		printf("%d\n", p->nbr);
		p = p->next;
	}
}

t_list *create_list_p1(int n, t_cmp *cmp)
{
	int i;
	t_list *head;
	t_list *tmp;
	t_list *p;

	head = NULL;
	tmp = NULL;
	p = NULL;
	i = 0;
	while (i < n)
	{
		if (!(tmp = (t_list*)malloc(sizeof(t_list))))
			return NULL;
		printf("What nbr for node %d: ", i + 1);
		scanf("%d", &(tmp->nbr));
		tmp->next = NULL;
		i++;
		if (head == NULL)
			head = tmp;
		else
		{
			p = head;
			cmp->i = 2;
			while (p->next != NULL)
			{
				p = p->next;
				cmp->i++;
			}
			p->next = tmp;
		}
	}
	return (head);   
}

t_cmp	*cmp_list(t_list *list, t_cmp *cmp)
{
	while (list->next != NULL)
	{
		if (cmp->i == 2)
			cmp->a_n = tmp->nbr;
		else if (cmp->i == n - 1)
			cmp->a_tail_m_one = tmp->nbr;			
		cmp->a_tail = tmp->nbr;
		// printf("cmp->a_tail: %d\n", cmp->a_tail);
		cmp->i++;
	}
	return (cmp);
}


	// 		// printf("cmp->i:%d\n", cmp->i);
	// 		// printf("n-1:%d\n", n - 1);
	// 		p->next = tmp;
	// 		if (cmp->i == 2)
	// 			cmp->a_n = tmp->nbr;
	// 		else if (cmp->i == n - 1)
	// 			cmp->a_tail_m_one = tmp->nbr;			
	// 		cmp->a_tail = tmp->nbr;
	// 		// printf("cmp->a_tail: %d\n", cmp->a_tail);
	// 		cmp->i++;
	// 	}
	// }
	// return (head); 
