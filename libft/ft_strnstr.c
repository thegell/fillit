/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:57:32 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:57:37 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (hay[i] && i < len)
	{
		if (hay[i] == needle[j])
		{
			while (hay[i] == needle[j] && i < len && needle[j])
			{
				i++;
				j++;
			}
		}
		if (needle[j] == '\0')
			return ((char*)hay + i - j);
		else
			i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
