/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:13:21 by juepee-m          #+#    #+#             */
/*   Updated: 2019/02/27 21:45:24 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					len_list(t_tetri **tetri_list)
{
	int				len;
	t_tetri			*tmp;

	len = 0;
	tmp = *tetri_list;
	while (tmp->tetrimino)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void				create_elem(t_tetri **tetri, char count)
{
	t_tetri		*tmp;
	t_tetri		*elem;

	tmp = *tetri;
	if (!(elem = malloc(sizeof(t_tetri))))
		return ;
	elem->tetrimino = 0;
	tmp->index = 'A' + count;
	elem->next = NULL;
	tmp->next = elem;
}

void				do_list(t_tetri **tetri_list, int i)
{
	t_tetri			*tetri;

	tetri = *tetri_list;
	tetri_size(tetri->tetrimino, tetri);
	create_elem(&tetri, (i + 1) / 21);
}

void				init_list(t_tetri **tetri_list)
{
	t_tetri			*tetri;

	tetri = *tetri_list;
	tetri->tetrimino = 0;
	tetri->index = 0;
	tetri->height = 0;
	tetri->width = 0;
	tetri->next = NULL;
}

t_tetri				*create_list(t_tetri *tetri)
{
	if (!(tetri = malloc(sizeof(t_tetri))))
		return ((tetri = NULL));
	init_list(&tetri);
	return (tetri);
}
