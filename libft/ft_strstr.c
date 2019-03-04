/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:58:13 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:58:14 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i] == needle[j] && needle[j])
			{
				i++;
				j++;
			}
		}
		if (needle[j] == '\0')
			return ((char*)haystack + i - j);
		else
			i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
