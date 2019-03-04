/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:51:05 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:51:06 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	if (dst > src)
	{
		while (i > 0)
		{
			i--;
			((char*)dst)[i] = ((char*)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	}
	return (dst);
}
