/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:41:04 by juepee-m          #+#    #+#             */
/*   Updated: 2019/02/18 18:38:08 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_sqrt(uint16_t area)
{
	int			i;

	i = 1;
	while (i * i < area)
		i++;
	return (i);
}

void			take_power(t_tetri **tetri_list, int i, int count)
{
	t_tetri		*tetri;

	tetri = *tetri_list;
	(void)count;
	tetri->tetrimino += ft_power(2, ((16 * (((i + 1) / 21) + 1))
								- (i + 1 - ((i + 1) / 21)
								- (((i + 1) - ((i + 1) / 21)) / 5))));
}

int				ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	nb = nb * ft_power(nb, power - 1);
	return (nb);
}
