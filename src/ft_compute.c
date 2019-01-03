/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 17:56:09 by dkhatri           #+#    #+#             */
/*   Updated: 2018/12/28 18:40:17 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_fit_tetri(char **str, t_fill *head, int size, t_point pt)
{
	int		ret;
	int		x;
	int		y;

	x = pt.x;
	y = pt.y;
	if (!head)
		return (1);
	if (x < 0 || x >= size || y >= size || str[x][y])
		return (0);
	str[x][y] = head->ch;
	pt.y = y + 1;
	if ((ret = ft_fit_tetri(str, head->right, size, pt)) < 1)
		return (ret);
	pt.y = y;
	pt.x = x + 1;
	if ((ret = ft_fit_tetri(str, head->down, size, pt)) < 1)
		return (ret);
	pt.x = x - 1;
	if ((ret = ft_fit_tetri(str, head->up, size, pt)) < 1)
		return (ret);
	return (1);
}

int			ft_fit_curr_tetri(char ***str, t_list *head, int size, t_point pt)
{
	char		**dup;
	t_fill		**fhead;
	int			ret;

	if (!(dup = ft_strarrdup(*str, size)))
		return (-1);
	if (!(fhead = (t_fill**)head->content) && !*fhead)
		return (-1);
	if ((ret = ft_fit_tetri(dup, *fhead, size, pt)) == 1)
		ret = ft_compute(&dup, head->next, size);
	if (ret < 1)
	{
		ft_strarrdel(&dup);
		return (ret);
	}
	ft_strarrdel(str);
	*str = ft_strarrdup(dup, size);
	ft_strarrdel(&dup);
	return (1);
}

int			ft_compute(char ***str, t_list *head, int size)
{
	t_point		p;
	int			ret;

	if (!head)
		return (1);
	p.x = 0;
	p.y = 1;
	while (p.x < size)
	{
		p.y = -1;
		while (++(p.y) < size)
			if ((ret = ft_fit_curr_tetri(str, head, size, p)))
				return (ret);
		p.x = p.x + 1;
	}
	return (0);
}
