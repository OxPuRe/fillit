/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_template_free.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 15:08:37 by aribeiro          #+#    #+#             */
/*   Updated: 2016/01/07 13:39:57 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** create template with '.' '\n' and '\0'
*/

char	*ft_memalloc_template(char *n, size_t size, size_t x)
{
	size_t	f;

	f = x - 1;
	n = (char *)malloc(sizeof(char) * size);
	if (n != NULL)
	{
		n = ft_memset(n, '.', size);
		n[size - 1] = '\0';
		while (f <= (size - 2))
		{
			n[f] = '\n';
			f = f + x;
		}
		return (n);
	}
	else
		return (NULL);
}

/*
** first malloc
*/

char	*ft_malloc_new_tab(size_t nb_tetri, t_tetri *s)
{
	size_t	x;
	size_t	size;

	s->y = 2;
	while ((s->y * s->y) < (nb_tetri * 4))
		s->y++;
	x = s->y + 1;
	size = (x * s->y) + 1;
	s->n = ft_memalloc_template(s->n, size, x);
	if (s->n == NULL)
		ft_putstr_error(5);
	return (s->n);
}

/*
** resize *n if necessary
*/

char	*ft_free_resize(t_tetri *s)
{
	size_t	x;
	size_t	size;

	if (s->n != NULL)
	{
		free(s->n);
		s->n = NULL;
	}
	s->y++;
	x = s->y + 1;
	size = (x * s->y) + 1;
	s->n = ft_memalloc_template(s->n, size, x);
	if (s->n == NULL)
		ft_putstr_error(5);
	s->bin = 0;
	return (s->n);
}
