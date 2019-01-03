/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:07:06 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/01 17:20:19 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			ft_parse_file(const int fd, t_list **head)
{
	char		ch;
	t_fill		*fhead;
	t_list		*ele;
	int			ret;

	fhead = 0;
	ch = 'A';
	while ((ret = ft_get_tetri(fd, &fhead, ch++)) > 0)
	{
		if (!(ele = ft_lstnew(&fhead, sizeof(fhead))))
			return (0);
		ft_lstaddlast(head, ele);
	}
	if (ret == -1)
		return (0);
	if (!(ele = ft_lstnew(&fhead, sizeof(&fhead))))
		return (0);
	ft_lstaddlast(head, ele);
	return (1);
}

int			ft_read_file(char *str, t_list **head)
{
	int		fd;

	*head = 0;
	if (!str)
		return (0);
	fd = open(str, O_RDONLY);
	if (fd < 1 || read(fd, str, 0) < 0)
		return (0);
	if (!ft_parse_file(fd, head))
		return (0);
	return (1);
}
