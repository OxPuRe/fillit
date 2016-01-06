/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:43:22 by aribeiro          #+#    #+#             */
/*   Updated: 2016/01/06 19:17:20 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
