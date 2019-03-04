/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepee-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:21:38 by juepee-m          #+#    #+#             */
/*   Updated: 2019/02/27 21:57:03 by juepee-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 546

# include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_tetri
{
	uint16_t		tetrimino;
	char			index;
	int				height;
	int				width;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_check
{
	int				x;
	int				y;
	uint16_t		line1;
	uint16_t		line2;
	uint16_t		line3;
	uint16_t		line4;
}					t_check;

int					main(int ac, char **av);
void				main_solve(t_tetri **tetri);
void				ft_delete(uint16_t tet, uint16_t **map, int pos, int size);
void				ft_place(uint16_t tet, uint16_t **map, int pos, int size);
int					ft_power(int nb, int power);
void				take_power(t_tetri **tetri_list, int i, int count);
int					ft_sqrt(uint16_t area);
uint16_t			top_left(t_tetri **tetri_list);
int					valid_shape(uint16_t tetrimino);
void				init_list(t_tetri **tetri_list);
void				do_list(t_tetri **tetri_list, int i);
int					len_list(t_tetri **tetri_list);
void				grid(char ***display_map);
void				fill(char ***map, t_tetri *tetri, int x, int y);
void				ft_display(char **map, uint16_t size);
void				free_dis_tab(char **display_map);
void				tetri_size(uint16_t tetrimino, t_tetri *tetri);
t_tetri				*create_list(t_tetri *tetri);
void				free_list(t_tetri *tetri);

#endif
