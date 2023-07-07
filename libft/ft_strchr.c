/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:20:39 by amatta            #+#    #+#             */
/*   Updated: 2023/04/18 14:51:41 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ps;

	ps = (char *)s;
	while (*ps)
	{
		if (*ps == (char)c)
			return (ps);
		ps++;
	}
	if ((char)c == 0)
		return (ps);
	return (NULL);
}
