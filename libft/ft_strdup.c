/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:53:51 by juepee-m          #+#    #+#             */
/*   Updated: 2019/02/18 23:42:57 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = NULL;
	if (s)
	{
		while (s[i])
			i++;
		if (!(cpy = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			cpy[i] = s[i];
			i++;
		}
		cpy[i] = '\0';
	}
	return (cpy);
}
