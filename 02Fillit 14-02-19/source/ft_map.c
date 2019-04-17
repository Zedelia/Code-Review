/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_map.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 23:38:29 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 16:35:42 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_map(int nb)
{
	char	**map;
	int		i;
	int		j;

	if (!(map = (char **)malloc(sizeof(*map) * (nb + 1))))
		return (0);
	i = 0;
	while (i < nb)
	{
		if (!(map[i] = (char *)malloc(nb + 1)))
			return (0);
		j = 0;
		while (j < nb)
			map[i][j++] = '.';
		map[i++][j] = '\0';
	}
	map[i] = 0;
	return (map);
}
