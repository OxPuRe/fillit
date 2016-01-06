/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 14:52:47 by aribeiro          #+#    #+#             */
/*   Updated: 2016/01/06 16:25:41 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_numb_join(char *buf, int i)
{
	int			join;

	join = 0;
	if (buf[i - 5] == '#')
		join++;
	if (buf[i + 5] == '#')
		join++;
	if (buf[i - 1] == '#')
		join++;
	if (buf[i + 1] == '#')
		join++;
	return (join);
}

static int		ft_blocverif(char *buf, int i, t_verif *var)
{
	int	total_join;

	total_join = 0;
	var->j = i;
	if (buf[4 + var->j] == '\n' && buf[9 + var->j] == '\n' &&
			buf[14 + var->j] == '\n' && buf[19 + var->j] == '\n')
	{
		while (i <= var->j + 20)
		{
			if (buf[i] == '#')
			{
				total_join = total_join + ft_numb_join(buf, i);
				var->hash++;
			}
			if (buf[i] == '.')
				var->p++;
			i++;
		}
	}
	if (total_join > 4)
	{
		if (var->hash == 4 && var->p == 12)
			return (0);
	}
	return (1);
}

int				ft_verif(int ret, char *buf)
{
	int		i;
	t_verif	var;

	i = 0;
	if (ret > 545 || ret < 20)
		return (1);
	while (ret < 546 && ret > 19 && i <= ret)
	{
		var.hash = 0;
		var.p = 0;
		var.j = 0;
		if (ft_blocverif(buf, i, &var) == 1)
			return (1);
		if (buf[i + 20] == '\n' || buf[i + 20] == '\0')
			i = i + 21;
		else
			return (1);
	}
	return (0);
}
