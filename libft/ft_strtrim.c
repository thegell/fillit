/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:58:30 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:58:33 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*cpy;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	j = ft_strlen(s) - 1;
	while (j > i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j--;
	if (j < i)
		return (cpy = ft_strdup(""));
	return (cpy = ft_strsub((char*)s, i, j - i + 1));
}
