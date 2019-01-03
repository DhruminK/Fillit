/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:17:04 by dkhatri           #+#    #+#             */
/*   Updated: 2018/12/28 19:18:25 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_strcount(char **str)
{
	int		i;
	int		j;
	int		count;

	if (!str)
		return (0);
	i = -1;
	count = 0;
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
			if (str[i][j++] == '#')
				count++;
	}
	return (count);
}

t_point		*ft_find_chr(char **str)
{
	int			i;
	int			j;
	t_point		*pt;

	if (!(pt = ft_ptnew(0, 0)))
		return (0);
	j = -1;
	while (++j < 4)
	{
		i = 0;
		while (i < 4)
			if (str[i++][j] == '#')
			{
				pt->x = i - 1;
				pt->y = j;
				return (pt);
			}
	}
	return (0);
}

int			ft_traverse(char **str, t_fill *head, t_point *pt, t_fill **ele)
{
	t_point		*p;
	int			count;

	if (ft_fill_find(head, pt) || (count = 0) || pt->x > 3 || pt->y > 3 || \
			pt->x < 0 || str[pt->x][pt->y] != '#' || !(p = ft_ptdup(pt)))
	{
		free(pt);
		*ele = 0;
		return (0);
	}
	if (!((*ele) = ft_fillnew(pt, head->ch)))
		return (-1);
	if (!(pt = ft_ptnew(p->x, p->y + 1)) || \
			(count += ft_traverse(str, head, pt, &((*ele)->right))) == -1)
		return (-1);
	if (!(pt = ft_ptnew(p->x + 1, p->y)) || \
			(count += ft_traverse(str, head, pt, &((*ele)->down))) == -1)
		return (-1);
	if (!(pt = ft_ptnew(p->x - 1, p->y)) ||\
			(count += ft_traverse(str, head, pt, &((*ele)->up))) == -1)
		return (-1);
	free(p);
	return (1 + count);
}

int			ft_parse_tetri(char **str, t_fill **head, char ch)
{
	t_point		*p;
	t_point		*pt;
	int			count;

	if (ft_strcount(str) != 4 || !(count = 1))
		return (-1);
	if (!(p = ft_find_chr(str)))
		return (-1);
	if (!((*head) = (t_fill*)ft_fillnew(p, ch)))
		return (-1);
	if (!(pt = ft_ptdup(p)))
		return (-1);
	if (!(p = ft_ptnew(p->x, p->y + 1)))
		return (-1);
	if ((count += ft_traverse(str, *head, p, &((*head)->right))) == -1)
		return (-1);
	if (!(p = ft_ptnew(pt->x + 1, pt->y)))
		return (-1);
	if ((count += ft_traverse(str, *head, p, &((*head)->down))) == -1)
		return (-1);
	free(pt);
	return (count == 4 ? 1 : -1);
}

int			ft_get_tetri(const int fd, t_fill **head, char ch)
{
	char	**str;
	char	*line;
	int		i;

	i = 0;
	if (!(str = (char**)malloc(sizeof(char*) * 5)))
		return (-1);
	str[4] = 0;
	while (i < 4)
	{
		if (get_next_line(fd, &line) < 1 || !line || ft_strlen(line) != 4 || \
				ft_strcnt(line, '#') + ft_strcnt(line, '.') != 4)
			return (-1);
		str[i++] = line;
	}
	if ((i = get_next_line(fd, &line)) == -1 || (i == 1 && ft_strlen(line)))
		return (-1);
	free(line);
	if (ft_parse_tetri(str, head, ch) == -1)
		return (-1);
	ft_strarrdel(&str);
	if (i == 0)
		return (0);
	return (1);
}
