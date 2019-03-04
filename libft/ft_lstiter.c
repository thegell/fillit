/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:48:36 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:48:38 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*elem;

	if (lst && f)
	{
		elem = lst;
		while (lst)
		{
			elem = lst->next;
			f(lst);
			lst = elem;
		}
	}
}
