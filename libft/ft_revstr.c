/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:46:12 by cphillip          #+#    #+#             */
/*   Updated: 2020/03/02 13:43:39 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

char	*ft_revstr(char *str)
{
	char	*tmp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	if (!(tmp = (char *)malloc(sizeof(len * (char)+1))))
		return (NULL);
	tmp[len] = '\0';
	while (len--)
	{
		tmp[len] = str[i];
		i++;
	}
	return (tmp);
}
