/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/30 04:57:27 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/30 05:41:18 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_free_coord(t_coord *c, int ret)
{
	free(c);
	return (ret);
}

void	ft_free_tetri(t_tetri *stab, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ft_freetab(stab[i].tetri);
		i++;
	}
	free(stab);
}

void	ft_free_all(t_all *gl)
{
	ft_freetab(gl->map);
	free(gl);
}
