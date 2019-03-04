/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:58:21 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:58:22 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if (s)
	{
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = start;
		while (i < (len + start) && s[i])
		{
			str[i - start] = s[i];
			i++;
		}
		str[len] = '\0';
	}
	return (str);
}
