/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:56:19 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:56:43 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = NULL;
	if (s)
	{
		if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		if (s)
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
		}
		str[i] = '\0';
	}
	return (str);
}
