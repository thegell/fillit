/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:55:41 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:55:43 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;
	char	*ss;

	i = 0;
	ss = (char*)s;
	str = NULL;
	if (s)
	{
		if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(ss) + 1))))
			return (NULL);
		if (ss)
		{
			while (ss[i])
			{
				str[i] = f(ss[i]);
				i++;
			}
		}
		str[i] = '\0';
	}
	return (str);
}
