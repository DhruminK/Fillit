/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:27:31 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/01 17:20:30 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# include <fcntl.h>
# include "get_next_line.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_fill
{
	char			ch;
	t_point			*pt;
	struct s_fill	*up;
	struct s_fill	*down;
	struct s_fill	*right;
}					t_fill;

/*
** HELPER FUNCTIONS
*/
int					ft_sqrt(int num);

/*
** T_POINT OPERATION FUNCTIONS
*/
int					ft_ptcmp(t_point *p1, t_point *p2);
t_point				*ft_ptnew(int x, int y);
void				ft_ptdel(t_point **pt);
t_point				*ft_ptdup(t_point *pt);

/*
** T_FILL OPERATION FUNCTIONS
*/
t_fill				*ft_fill_find(t_fill *head, t_point *p);
t_fill				*ft_fillnew(t_point *p, char ch);
void				ft_filldel(t_fill **head);

/*
** PARSE FILL FUNCTIONS
*/
int					ft_strcount(char **str);
int					ft_get_tetri(const int fd, t_fill **head, char ch);
int					ft_read_file(char *str, t_list **head);

/*
** FITTING THE TETRIS INTO SQUARE
*/
int					ft_compute(char ***str, t_list *head, int size);

#endif
