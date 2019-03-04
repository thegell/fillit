/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:56:41 by juepee-m          #+#    #+#             */
/*   Updated: 2019/02/27 22:05:47 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <assert.h>

void			init_check(t_check **check, uint16_t tetri, int pos, int size)
{
	(*check)->x = pos / size;
	(*check)->y = pos % size;
	(*check)->line1 = (tetri & 0xF000) >> (*check)->x;
	(*check)->line2 = ((tetri & 0xF00) << 4) >> (*check)->x;
	(*check)->line3 = ((tetri & 0xF0) << 8) >> (*check)->x;
	(*check)->line4 = ((tetri & 0xF) << 12) >> (*check)->x;
}

int				check(uint16_t tetrimino, uint16_t *map, int pos, int size)
{
	t_check		*tc;

	if (!(tc = (t_check *)malloc(sizeof(t_check))))
		return (0);
	init_check(&tc, tetrimino, pos, size);
	if ((tc->line1 ^ map[tc->y]) == tc->line1 + map[tc->y])
	{
		if ((tc->line2 ^ map[tc->y + 1]) == tc->line2 + map[tc->y + 1])
		{
			if ((tc->line3 ^ map[tc->y + 2]) == tc->line3 + map[tc->y + 2])
			{
				if ((tc->line4 ^ map[tc->y + 3]) == tc->line4 + map[tc->y + 3])
				{
					ft_place(tetrimino, &map, pos, size);
					free(tc);
					return (1);
				}
			}
		}
	}
	free(tc);
	return (0);
}

int				solve(t_tetri *tetri, uint16_t **map, int size, char ***d_map)
{
	int			x;
	int			y;

	y = -1;
	if (tetri->next == NULL)
		return (1);
	while ((++y <= (size - tetri->height)) && tetri)
	{
		x = -1;
		while ((++x <= (size - tetri->width)) && tetri)
		{
			if (check(tetri->tetrimino, *map, (size * x) + y, size))
			{
				if (solve(tetri->next, map, size, d_map))
				{
					fill(d_map, tetri, x, y);
					return (1);
				}
				else
					ft_delete(tetri->tetrimino, map, (size * x) + y, size);
			}
		}
	}
	return (0);
}

void			init_map(uint16_t *map)
{
	int			i;

	i = 0;
	while (i < 16)
	{
		map[i] = 0;
		i++;
	}
}

void			main_solve(t_tetri **tetri)
{
	int			size;
	uint16_t	*map;
	char		**d_map;
	t_tetri		*tmp;

	size = ft_sqrt(4 * len_list(tetri));
	if (!(d_map = (char **)malloc(sizeof(char *) * 17)))
		return ;
	d_map[16] = NULL;
	grid(&d_map);
	if (!(map = (uint16_t *)malloc(sizeof(uint16_t) * 16)))
		return ;
	init_map(map);
	tmp = *tetri;
	while (!solve(*tetri, &map, size, &d_map))
	{
		init_map(map);
		size++;
	}
	ft_display(d_map, size);
	free(map);
	free_dis_tab(d_map);
	free(d_map);
}
