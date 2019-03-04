/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:13:50 by juepee-m          #+#    #+#             */
/*   Updated: 2019/02/27 21:40:43 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define VALID_CHAR(c) (c == '#' || c== '.' || c == '\n')

void				tetri_size(uint16_t tetrimino, t_tetri *tetri)
{
	uint16_t		line;
	uint16_t		column;
	char			height;
	char			width;

	line = 0xF000;
	column = 0x8888;
	height = 0;
	width = 0;
	while (tetrimino & line)
	{
		height++;
		line >>= 4;
	}
	tetri->height = height;
	while (tetrimino & column)
	{
		width++;
		column >>= 1;
	}
	tetri->width = width;
}

uint16_t			top_left(t_tetri **tetri)
{
	while (!((*tetri)->tetrimino & 0xF000))
		(*tetri)->tetrimino <<= 4;
	while (!((*tetri)->tetrimino & 0x8888))
		(*tetri)->tetrimino <<= 1;
	return ((*tetri)->tetrimino);
}

int					valid_map(int i, char c)
{
	int				count;

	count = 0;
	if (c != '\n' && c != '\0')
	{
		if ((i + 1 - ((i + 1) / 21)) % 5 != 0)
			return (0);
	}
	if (c == '\n' || c == '\0')
	{
		if ((i + 2) % 21 != 0)
			return (0);
	}
	return (1);
}

int					tetri_taker(const char *str, t_tetri *tetri)
{
	uint16_t		i;
	int				count;

	i = -1;
	count = 0;
	while (str[++i] && VALID_CHAR(str[i]))
	{
		if (str[i] == '\n' && !valid_map(i, str[i + 1]))
		{
			return (0);
		}
		if (str[i] == '#')
			take_power(&tetri, i, count++);
		if (((i + 2) % 21 == 0 && count % 4 == 0 && count != 0))
		{
			if (valid_shape(top_left(&tetri)))
			{
				do_list(&tetri, i);
				tetri = tetri->next;
			}
			else
				return (0);
		}
	}
	return ((str[i] == '\0' && count % 4 == 0 && count != 0) ? 1 : 0);
}

int					main(int ac, char **av)
{
	int				fd;
	char			buf[BUF_SIZE];
	char			*str;
	int				ret;
	t_tetri			*tetri_list;

	tetri_list = NULL;
	fd = open(av[1], O_RDONLY);
	tetri_list = create_list(tetri_list);
	if ((ret = read(fd, buf, BUF_SIZE)))
		str = ft_strdup(buf);
	if (!ret || ac != 2 || !tetri_taker(str, tetri_list))
	{
		free(str);
		close(fd);
		free_list(tetri_list);
		write(1, "error\n", 6);
		return (0);
	}
	close(fd);
	free(str);
	main_solve(&tetri_list);
	free_list(tetri_list);
	return (0);
}
