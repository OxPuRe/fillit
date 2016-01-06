/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:29:26 by aribeiro          #+#    #+#             */
/*   Updated: 2016/01/06 15:52:56 by aribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 600
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_tetri
{
	size_t	y;
	size_t	j;
	int		h1;
	int		h2;
	int		h3;
	int		h4;
	size_t	bin;
	size_t	nb_tetri;
	char	*n;
}					t_tetri;

typedef struct		s_verif
{
	int	hash;
	int	p;
	int j;
}					t_verif;

int					ft_verif(int ret, char *buf);
int					**ft_tetritab(char *buf, int nb, int nbc);
int					ft_putstr_error(int e);
int					ft_countbloc(char *buf);
size_t				ft_which_line_is_hash(int **tab, t_tetri *s, size_t k);
char				*ft_delete(char letter, t_tetri *s);
char				*ft_memalloc_template(char *n, size_t size, size_t x);
char				*ft_malloc_new_tab(size_t nb_tetri, t_tetri *s);
char				*ft_free_resize(t_tetri *s);
void				ft_resolution(int **tab, size_t nb_tetri);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_free_int(int **tab, int nbc);
void				ft_put(int **tab, t_tetri *s);
void				ft_put2(int **tab, t_tetri *s);

#endif
