/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhatri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:36:40 by dkhatri           #+#    #+#             */
/*   Updated: 2019/01/01 17:19:01 by dkhatri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"
#include <stdio.h>

void	ft_display(char **str, size_t size)
{
	size_t	s;
	size_t	i;
	char	c;

	i = -1;
	while (++i < size)
	{
		s = 0;
		while (s < size)
			ft_putchar((c = (*str)[s++]) ? c : '.');
		str++;
		ft_putchar('\n');
	}
}

void	free_lst(void *content, size_t size)
{
	t_fill **head;

	head = (t_fill**)content;
	size = 0;
	ft_filldel(head);
	free(content);
}

int		ft_end_pro(int ac, t_list **head, int i, char ***str)
{
	if (ac != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (0);
	}
	if (!head || !*head)
	{
		ft_putendl("error");
		return (0);
	}
	if (i == 0)
		ft_putendl("error");
	ft_lstdel(head, &free_lst);
	ft_strarrdel(str);
	return (0);
}

int		main(int ac, char **av)
{
	t_list		*head;
	int			count;
	char		**str;
	int			i;

	if (ac != 2)
		return (ft_end_pro(ac, 0, 0, 0));
	if (!ft_read_file(av[1], &head))
		return (ft_end_pro(ac, &head, 0, 0));
	i = 0;
	count = ft_lstfindsize(head);
	count = ft_sqrt(4 * count);
	str = ft_strarrnew(count);
	while ((i = ft_compute(&str, head, count)) == 0)
	{
		ft_strarrdel(&str);
		str = ft_strarrnew(++count);
	}
	if (i == 1)
		ft_display(str, count);
	return (ft_end_pro(ac, &head, i, &str));
}
