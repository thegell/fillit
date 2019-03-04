/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:48:46 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:48:47 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*tmp;

	start = f(lst);
	lst = lst->next;
	tmp = start;
	while (lst)
	{
		tmp->next = f(lst);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (start);
}
