/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:14:48 by amatta            #+#    #+#             */
/*   Updated: 2023/04/13 10:48:50 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
	return (dest);
}
