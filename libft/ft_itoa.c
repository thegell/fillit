/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:45:57 by juepee-m          #+#    #+#             */
/*   Updated: 2018/11/05 17:47:07 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size_int(int n)
{
	size_t i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void		ft_fill_array(char *s, int *i, int n)
{
	if (n < 10)
	{
		s[*i] = n + '0';
		*i = *i + 1;
	}
	else
	{
		ft_fill_array(s, i, n / 10);
		ft_fill_array(s, i, n % 10);
	}
}

char			*ft_itoa(int n)
{
	int		i;
	char	*s;
	int		neg;

	neg = 0;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	if (!(s = ft_strnew((sizeof(char) * (ft_size_int(n) + neg)))))
		return (NULL);
	if (neg == 1)
		s[0] = '-';
	ft_fill_array(s + neg, &i, n);
	return (s);
}
