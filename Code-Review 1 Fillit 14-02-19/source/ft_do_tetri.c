/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_do_tetri.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/30 12:36:59 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/30 04:56:12 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** TRUE si la colonne est vide (que des '.')
*/

int			ft_empty_col(char **tetri, int x)
{
	return (tetri[0][x] == '.' && tetri[1][x] == '.'
			&& tetri[2][x] == '.' && tetri[3][x] == '.');
}

/*
** Place le tetri le plus en haut a gauche possible
*/

char		**ft_cut_tetri(char **tetri)
{
	int		cut;
	int		i;
	int		j;

	cut = 0;
	i = 0;
	while (ft_strncmp(tetri[cut], "....", 4) == 0)
		cut++;
	while (i + cut < 4)
	{
		ft_swap_line(&(tetri[cut + i]), &(tetri[i]));
		i++;
	}
	cut = 0;
	while (ft_empty_col(tetri, cut) == 1)
		cut++;
	i = 0;
	while (i + cut < 4)
	{
		j = -1;
		while (++j < 4)
			ft_swap_col(&(tetri[j][cut + i]), &(tetri[j][i]));
		i++;
	}
	return (tetri);
}

/*
** Remplit une case du tableau avec un tetri
*/

t_tetri		ft_do_minos(char *buff, int len, char name)
{
	int			i;
	t_tetri		t;

	i = 0;
	if (!(t.tetri = (char **)malloc(sizeof(char *) * 5)))
		exit(0);
	while (*buff != '\n' && len > 0)
	{
		t.tetri[i++] = ft_strndup(buff, 4);
		buff += 5;
		len -= 5;
	}
	t.tetri[i] = 0;
	t.tetri = ft_cut_tetri(t.tetri);
	t.height = ft_size_height(t.tetri, 4);
	t.lenght = ft_size_line(t.tetri, 4);
	t.name = name;
	return (t);
}

/*
** Remplit le tableau de structure avec les tetris.
*/

t_tetri		*ft_do_tetri(char *buff, int len)
{
	t_tetri	*stab;
	char	name;
	int		i;

	i = 0;
	name = 'A';
	stab = (t_tetri *)malloc(sizeof(*stab) * ((len + 1) / 21));
	while (len >= 0)
	{
		stab[i] = ft_do_minos(buff, len, name);
		len -= 21;
		buff += 21;
		i++;
		name++;
	}
	return (stab);
}
