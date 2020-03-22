/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csphilli <csphilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 13:46:58 by csphilli          #+#    #+#             */
/*   Updated: 2020/03/22 13:50:28 by csphilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// INcludes


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