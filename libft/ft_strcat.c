/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:23:54 by cphillip          #+#    #+#             */
/*   Updated: 2020/01/10 19:27:13 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	size_t	dest_l;

	i = 0;
	dest_l = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = '\0';
	return ((char *)dest);
}
