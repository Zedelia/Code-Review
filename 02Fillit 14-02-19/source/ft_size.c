/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_size.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 22:09:51 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 20:48:49 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** ft_size_line definit la taille de la ligne en comptant les '.'
** en partant de la fin par rapport a la len
*/

int		ft_size_line(char **map, int len)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	while (i < len)
	{
		j = len - 1;
		while (map[i][j] == '.' && j >= 0)
			j--;
		if (j == -1 && i == 0)
			return (0);
		size = (j > size) ? j : size;
		i++;
	}
	return (size + 1);
}

/*
** ft_size_height definit la taille de la hauteur en comptant les '.'
** en partant de la fin par rapport a la len
*/

int		ft_size_height(char **map, int len)
{
	int		i;
	int		j;
	int		size;

	j = 0;
	size = 0;
	while (j < len)
	{
		i = len - 1;
		while (map[i][j] == '.' && i > 0)
			i--;
		if (i == -1 && j == 0)
			return (0);
		size = (i > size) ? i : size;
		j++;
	}
	return (size + 1);
}

/*
** selectionne la plus grande taille entre la hauteur et la longueur
*/

int		ft_size_square(char **map, int len)
{
	int		line;
	int		height;

	line = ft_size_line(map, len);
	height = ft_size_height(map, len);
	return ((line > height) ? line : height);
}
