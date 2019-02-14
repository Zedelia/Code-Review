/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_clean_map.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 18:42:43 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/29 18:11:02 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_clean_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		write(1, map[i++], size);
		write(1, "\n", 1);
	}
}
