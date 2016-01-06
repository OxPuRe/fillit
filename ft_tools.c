/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:57:20 by aribeiro          #+#    #+#             */
/*   Updated: 2016/01/06 15:53:45 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free_int(int **tab, int nb_tetri)
{
	while (nb_tetri >= 0)
	{
		if (tab[nb_tetri] != NULL)
		{
			free(tab[nb_tetri]);
			tab[nb_tetri] = NULL;
		}
		nb_tetri--;
	}
	if (tab != NULL)
	{
		free(tab);
		tab = NULL;
	}
}

int			ft_countbloc(char *buf)
{
	int		j;
	int		nb;

	j = 0;
	nb = 1;
	while (buf[j])
	{
		if (buf[j] == '\n' && buf[j - 1] == '\n')
			nb++;
		j++;
	}
	return (nb);
}

size_t		ft_which_line_is_hash(int **tab, t_tetri *s, size_t k)
{
	size_t line;

	line = 0;
	if (tab[s->j][k] > 4 && tab[s->j][k] < 10)
		line = 1;
	else if (tab[s->j][k] > 9 && tab[s->j][k] < 15)
		line = 2;
	else if (tab[s->j][k] > 14 && tab[s->j][k] < 20)
		line = 3;
	return (line);
}

char		*ft_delete(char letter, t_tetri *s)
{
	size_t	i;
	size_t	hash;

	i = 0;
	hash = 0;
	while (hash < 4)
	{
		if (s->n[i] == letter)
		{
			s->n[i] = '.';
			if (hash == 0)
				s->h1 = i;
			if (hash == 1)
				s->h2 = i;
			if (hash == 2)
				s->h3 = i;
			if (hash == 3)
				s->h4 = i;
			hash++;
		}
		i++;
	}
	s->bin = 1;
	s->nb_tetri += 1;
	return (s->n);
}
