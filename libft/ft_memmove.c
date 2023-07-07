/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:31:18 by amatta            #+#    #+#             */
/*   Updated: 2023/04/13 12:16:57 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pd;
	unsigned char		*ps;

	if (!dst && !src)
		return (dst);
	if (dst < src)
		dst = ft_memcpy(dst, src, len);
	else
	{
		pd = (unsigned char *)dst;
		ps = (unsigned char *)src;
		while (len--)
			pd[len] = ps[len];
	}
	return (dst);
}
