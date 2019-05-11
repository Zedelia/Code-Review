/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manage_pos.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 00:11:52 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 20:33:49 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Positionne le tetrimino sur la map, avec le bon nom
*/

void	ft_set_tetri(char **map, t_tetri t, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t.tetri[i][j] == '#')
				map[y + i][x + j] = t.name;
			j++;
		}
		i++;
	}
}

/*
** Supprime le tetri donne en parametre sur la map (remplace par des .)
*/

void	ft_delete_tetri(char **map, t_tetri t, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (map[y + i][x + j] == t.name)
				map[y + i][x + j] = '.';
			j++;
		}
		i++;
	}
}

/*
** Verifie si le tetrimino peut etre positionne sur la map (rien en dessous)
*/

int		ft_check_pos(t_all *gl, t_tetri t, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t.tetri[i][j] == '#'
				&& gl->map[y + i][x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
