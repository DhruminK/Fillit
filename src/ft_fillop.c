/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:34:51 by dkhatri           #+#    #+#             */
/*   Updated: 2018/12/20 15:39:16 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_fill		*ft_fill_find(t_fill *head, t_point *p)
{
	t_fill		*ele;

	if (!head)
		return (0);
	if (ft_ptcmp(head->pt, p))
		return (head);
	if ((ele = ft_fill_find(head->right, p)))
		return (ele);
	if ((ele = ft_fill_find(head->up, p)))
		return (ele);
	if ((ele = ft_fill_find(head->down, p)))
		return (ele);
	return (0);
}

t_fill		*ft_fillnew(t_point *p, char ch)
{
	t_fill		*ele;

	if (!(ele = (t_fill*)malloc(sizeof(t_fill))))
		return (0);
	ele->pt = p;
	ele->ch = ch;
	ele->up = 0;
	ele->right = 0;
	ele->down = 0;
	return (ele);
}

void		ft_filldel(t_fill **head)
{
	t_fill *ele;

	if (!head || !*head)
		return ;
	ele = *head;
	if (ele->right)
		ft_filldel(&(ele->right));
	if (ele->down)
		ft_filldel(&(ele->down));
	if (ele->up)
		ft_filldel(&(ele->up));
	ele->ch = 0;
	ft_ptdel(&(ele->pt));
	free(ele);
	*head = 0;
}
