/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetritab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:15:16 by auverneu          #+#    #+#             */
/*   Updated: 2016/01/06 15:35:37 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*ft_hashpos(char *buf, int *tab)
{
	int		j;
	int		n;
	int		i;

	j = 0;
	n = 0;
	i = 0;
	while (buf[j] != '#')
	{
		if (buf[j] == '\n')
			n++;
		j++;
	}
	while (j < 19)
	{
		if (buf[j] == '#')
		{
			tab[i] = (j - (n * 5));
			i++;
		}
		j++;
	}
	return (tab);
}

int				**ft_tetritab(char *buf, int nb, int nbc)
{
	int		**tab;

	tab = NULL;
	tab = (int **)malloc(sizeof(int *) * nb);
	if (tab == NULL)
	{
		ft_putstr_error(5);
		return (tab);
	}
	while (nbc < nb)
	{
		tab[nbc] = NULL;
		tab[nbc] = (int *)malloc(sizeof(int) * 4);
		if (tab[nbc] == NULL)
		{
			free(tab);
			tab = NULL;
			ft_putstr_error(5);
			return (tab);
		}
		tab[nbc] = ft_hashpos(buf, tab[nbc]);
		nbc++;
		buf = buf + 21;
	}
	return (tab);
}
