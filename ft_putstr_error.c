/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:43:22 by aribeiro          #+#    #+#             */
/*   Updated: 2016/01/07 13:25:54 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** for debug : 2 = error fd; 3 = open() failed; 4 = read() failed;
** 5 = malloc failed; 6 = close() failed
*/

int		ft_putstr_error(int e)
{
	if (e == 2)
		write(1, "error\n", 6);
	if (e == 3)
		write(1, "error\n", 6);
	if (e == 4)
		write(1, "error\n", 6);
	if (e == 5)
		write(1, "error\n", 6);
	if (e == 6)
		write(1, "error\n", 6);
	return (1);
}
