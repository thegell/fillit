/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:57:55 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:57:57 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	i;
	size_t	len;
	char	tmp;

	if (s)
	{
		i = 0;
		len = ft_strlen(s) - 1;
		while (i < len)
		{
			tmp = s[i];
			s[i] = s[len];
			s[len] = tmp;
			i++;
			len--;
		}
	}
	return (s);
}
