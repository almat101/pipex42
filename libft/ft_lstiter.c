/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:54:32 by amatta            #+#    #+#             */
/*   Updated: 2023/04/18 15:01:07 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	while (lst == NULL || f == NULL)
		return ;
	temp = lst;
	while (temp != NULL)
	{
		(*f)(temp->content);
		temp = temp->next;
	}
}
