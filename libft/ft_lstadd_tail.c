/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:48:09 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:48:10 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_tail(t_list **alst, t_list *new)
{
	t_list	*current;

	current = *alst;
	if (new)
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}
}
