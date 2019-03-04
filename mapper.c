/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:44:06 by juepee-m          #+#    #+#             */
/*   Updated: 2019/02/27 22:08:29 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdlib.h>
#include <stdio.h>

void				ft_delete(uint16_t tet, uint16_t **map, int pos, int size)
{
	uint16_t		*tmp;
	uint16_t		line;
	int				i;
	int				x;
	int				y;

	i = 0;
	line = 0xF000;
	x = pos / size;
	y = pos % size;
	tmp = *map;
	while (y < size && i < 4)
	{
		tmp[y] = (((tet & line) << (4 * i)) >> x) ^ tmp[y];
		i++;
		y++;
		line >>= 4;
	}
}

void				ft_place(uint16_t tet, uint16_t **map, int pos, int size)
{
	uint16_t		line;
	int				i;
	int				x;
	int				y;

	i = 0;
	line = 0xF000;
	x = pos / size;
	y = pos % size;
	while (y < size && i < 4)
	{
		(*map)[y] = (((tet & line) << (4 * i)) >> x) ^ (*map)[y];
		i++;
		y++;
		line >>= 4;
	}
}

void				fill(char ***map, t_tetri *tetri, int x, int y)
{
	uint16_t		mask;
	int				i;
	int				pos;
	uint16_t		line;

	line = 0xF000;
	i = 0;
	while (i < 4)
	{
		mask = 0x8000;
		pos = 0;
		while (mask > 0x800)
		{
			if (((tetri->tetrimino & line) << (4 * i)) & mask)
				(*map)[y][x + pos] = tetri->index;
			pos++;
			mask >>= 1;
		}
		y++;
		i++;
		line >>= 4;
	}
}

void				grid(char ***display_map)
{
	int				x;
	int				y;

	y = 0;
	while (y < 16)
	{
		if (!((*display_map)[y] = (char *)malloc(sizeof(char) * 17)))
			return ;
		x = 0;
		while (x < 16)
		{
			(*display_map)[y][x] = '.';
			x++;
		}
		(*display_map)[y][x] = '\0';
		y++;
	}
}
