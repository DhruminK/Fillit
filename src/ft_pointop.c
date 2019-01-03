/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:32:11 by dkhatri           #+#    #+#             */
/*   Updated: 2018/12/20 15:13:40 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_ptcmp(t_point *p1, t_point *p2)
{
	if (!p1 || !p2)
		return (0);
	if (p1->x == p2->x && p1->y == p2->y)
		return (1);
	return (0);
}

t_point		*ft_ptnew(int x, int y)
{
	t_point		*ele;

	if (!(ele = (t_point*)malloc(sizeof(t_point))))
		return (0);
	ele->x = x;
	ele->y = y;
	return (ele);
}

t_point		*ft_ptdup(t_point *pt)
{
	t_point		*ele;

	if (!(ele = ft_ptnew(pt->x, pt->y)))
		return (0);
	return (ele);
}

void		ft_ptdel(t_point **pt)
{
	t_point *p;

	if (!pt || !*pt)
		return ;
	p = *pt;
	p->x = 0;
	p->y = 0;
	free(p);
	*pt = 0;
}
