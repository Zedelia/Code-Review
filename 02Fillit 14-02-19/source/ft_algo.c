/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/30 04:28:21 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/30 06:10:24 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		beyond_limit(t_all *gl, t_tetri t, t_coord *c)
{
	if ((c->x + t.lenght > gl->size_sqr)
		|| (c->y + t.height > gl->size_sqr))
		return (1);
	return (0);
}

int		ft_fillit(t_tetri *stab, t_all *gl, int i)
{
	t_coord *c;

	c = (t_coord *)malloc(sizeof(*c));
	if (i >= gl->nb)
		return (ft_free_coord(c, 1));
	c->y = 0;
	while (c->y < gl->size_sqr)
	{
		c->x = 0;
		while (c->x < gl->size_sqr)
		{
			if (ft_check_pos(gl, stab[i], c->x, c->y) == 1
				&& beyond_limit(gl, stab[i], c) == 0)
			{
				ft_set_tetri(gl->map, stab[i], c->x, c->y);
				if (ft_fillit(stab, gl, i + 1) == 1)
					return (ft_free_coord(c, 1));
				ft_delete_tetri(gl->map, stab[i], c->x, c->y);
			}
			c->x++;
		}
		c->y++;
	}
	return (ft_free_coord(c, 0));
}

int		ft_algo(char *buff, int len)
{
	t_tetri	*t;
	t_all	*gl;
	int		i;

	i = 0;
	if (!(gl = ft_init_gl((len + 1) / 21)))
		return (0);
	if (!(t = ft_do_tetri(buff, len)))
	{
		ft_free_all(gl);
		return (0);
	}
	gl->map = ft_map(gl->size_map + 1);
	while (ft_fillit(t, gl, 0) == 0)
		gl->size_sqr++;
	ft_clean_map(gl->map, ft_size_square(gl->map, gl->size_map));
	ft_free_tetri(t, gl->nb);
	ft_free_all(gl);
	return (1);
}
