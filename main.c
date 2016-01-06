/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 21:41:50 by aribeiro          #+#    #+#             */
/*   Updated: 2016/01/06 16:51:09 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char *av[])
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	int		fd;
	int		e;

	ret = 0;
	if (ac != 2)
		return (ft_putstr_error(2));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_error(3));
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (ret < 1)
		return (ft_putstr_error(4));
	e = ft_verif(ret, buf);
	if (e == 1)
		ft_putstr_error(2);
	if (e == 0)
		ft_resolution(ft_tetritab(buf, ft_countbloc(buf), 0),
				ft_countbloc(buf));
	if (close(fd) == -1)
		return (ft_putstr_error(6));
	return (0);
}
