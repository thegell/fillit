/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:53:00 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:53:02 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	ptr = (char*)s;
	i = 0;
	while (ptr[i])
	{
		if (c != '\0')
		{
			if (ptr[i] == c)
				return (ptr + i);
		}
		i++;
	}
	if (c == '\0')
		return (ptr + i);
	return (NULL);
}
