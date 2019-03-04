/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:57:47 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:57:48 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int size;

	size = ft_strlen((char*)s);
	while (s[size] != (char)c && size >= 0)
		size--;
	if (s[size] == (char)c)
		return ((char *)s + size);
	return (NULL);
}
