/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:14:54 by amatta            #+#    #+#             */
/*   Updated: 2023/04/13 12:19:36 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arr_len(int nb, int base)
{
	int	count;

	count = 0;
	if (nb <= 0)
		++count;
	while (nb)
	{
		nb /= base;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	const char	*d;

	d = "0123456789";
	len = arr_len(n, 10);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	len--;
	while (n)
	{
		if (n > 0)
			str[len--] = d[n % 10];
		else
			str[len--] = d[n % 10 *(-1)];
		n /= 10;
	}
	return (str);
}
