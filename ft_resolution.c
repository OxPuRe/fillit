/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:39:14 by aribeiro          #+#    #+#             */
/*   Updated: 2016/01/07 13:39:34 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** (y - 4) because by default the table is 4 * 4 but may be smaller 2*2 for
** example
*/

static void		ft_adapt(int **tab, t_tetri *s)
{
	size_t	line;

	line = ft_which_line_is_hash(tab, s, 0);
	s->h1 = tab[s->j][0] + ((s->y - 4) * line) - tab[s->j][0];
	line = ft_which_line_is_hash(tab, s, 1);
	s->h2 = tab[s->j][1] + ((s->y - 4) * line) - tab[s->j][0];
	line = ft_which_line_is_hash(tab, s, 2);
	s->h3 = tab[s->j][2] + ((s->y - 4) * line) - tab[s->j][0];
	line = ft_which_line_is_hash(tab, s, 3);
	s->h4 = tab[s->j][3] + ((s->y - 4) * line) - tab[s->j][0];
}

void			ft_put2(int **tab, t_tetri *s)
{
	if (s->n[s->h4 + s->bin] == '\0')
	{
		if (s->j == 0)
		{
			s->n = ft_free_resize(s);
			if (s->n == NULL)
				return ;
			ft_adapt(tab, s);
			ft_put(tab, s);
		}
		else
		{
			s->n = ft_delete((s->j + 64), s);
			s->j--;
			ft_put(tab, s);
		}
	}
}

void			ft_put(int **tab, t_tetri *s)
{
	while (s->n[s->h4 + s->bin] != '\0')
	{
		if (s->n[s->h1 + s->bin] == '.' && s->n[s->h2 + s->bin] == '.'
				&& s->n[s->h3 + s->bin] == '.' && s->n[s->h4 + s->bin] == '.')
		{
			s->n[s->h1 + s->bin] = s->j + 65;
			s->n[s->h2 + s->bin] = s->j + 65;
			s->n[s->h3 + s->bin] = s->j + 65;
			s->n[s->h4 + s->bin] = s->j + 65;
			s->nb_tetri -= 1;
			break ;
		}
		s->h1 += 1;
		s->h2 += 1;
		s->h3 += 1;
		s->h4 += 1;
	}
	ft_put2(tab, s);
}

static void		ft_put_loop(int **tab, t_tetri *s)
{
	s->j = 0;
	while (s->nb_tetri != 0 && s->n != NULL)
	{
		s->bin = 0;
		ft_adapt(tab, s);
		ft_put(tab, s);
		s->j++;
	}
}

void			ft_resolution(int **tab, size_t nb_tetri)
{
	t_tetri		s;

	s.n = NULL;
	s.nb_tetri = nb_tetri;
	if (tab == NULL)
	{
		ft_putstr_error(5);
		return ;
	}
	s.n = ft_malloc_new_tab(nb_tetri, &s);
	if (s.n == NULL)
	{
		ft_putstr_error(5);
		return ;
	}
	ft_put_loop(tab, &s);
	if (tab != NULL)
	{
		ft_free_int(tab, (nb_tetri - 1));
	}
	if (s.n == NULL)
		return ;
	ft_putstr(s.n);
	free(s.n);
	s.n = NULL;
}
