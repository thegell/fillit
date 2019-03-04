/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:45:34 by juepee-m          #+#    #+#             */
/*   Updated: 2019/02/27 22:06:01 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_list(t_tetri *tetri)
{
	t_tetri		*tmp;

	while (tetri)
	{
		tmp = tetri;
		tetri = tetri->next;
		free(tmp);
	}
}

void		free_dis_tab(char **display_map)
{
	int		i;

	i = 0;
	while (display_map[i])
	{
		free(display_map[i]);
		i++;
	}
}
