/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:49:39 by amatta            #+#    #+#             */
/*   Updated: 2023/04/05 12:15:27 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*ps1;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ps1 = (char *)malloc(sizeof(char) * (s1len + s2len) + 1);
	if (!ps1)
		return (NULL);
	ft_strlcpy(ps1, s1, s1len + 1);
	ft_strlcat(ps1, s2, s1len + s2len + 1);
	return (ps1);
}
