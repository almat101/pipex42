/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:04:46 by amatta            #+#    #+#             */
/*   Updated: 2023/04/03 18:45:58 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ps;

	ps = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			ps = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (ps);
}
