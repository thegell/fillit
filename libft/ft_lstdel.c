/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:48:19 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:48:21 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*tmp;

	if (*alst && alst && del)
	{
		current = *alst;
		while (current)
		{
			del(current->content, current->content_size);
			tmp = current->next;
			free(current);
			current = NULL;
			current = tmp;
		}
		*alst = NULL;
		alst = NULL;
	}
}
