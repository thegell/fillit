/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:53:20 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:53:21 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;
	unsigned int	diff;

	i = 0;
	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	while (ss1[i] && ss2[i] && ss1[i] == ss2[i])
		i++;
	if (ss1[i] == '\0' && ss2[i] == '\0')
		return (0);
	diff = ss1[i] - ss2[i];
	return (diff);
}
