/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lines.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 11:12:36 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 18:13:20 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_line_straight_horiz(t_param *p, int a, int z, int x1)
{
	double	d;
	double	t;
	int		y1;
	double	q;

	y1 = p->result[a].y1;
	d = p->result[z].y1 - y1;
	q = 1 / d;
	t = -y1;
	while (ft_abs(p->result[z].y1 - y1))
	{
		if (p->color)
			ft_pixel_put(p, x1, y1, ft_color_average(p->ground, p->height, 	\
			ft_average(p->result[a].z, p->result[z].z, (y1 + t) * q) / p->max));
		else
			ft_pixel_put(p, x1, y1, ft_color_average(p->result[a].color, 	\
			p->result[z].color, (y1 + t) * q));
		y1 = y1 <= p->result[z].y1 ? y1 + 1 : y1 - 1;
	}
	if (p->color)
		ft_pixel_put(p, x1, y1, ft_color_average(p->ground, p->height, 		\
		ft_average(p->result[a].z, p->result[z].z, (y1 + t) * q) / p->max));
	else
		ft_pixel_put(p, x1, y1, ft_color_average(p->result[a].color, 		\
		p->result[z].color, (y1 + t) * q));
}

void	ft_line_straight_vert(t_param *p, int a, int z, int y1)
{
	double	d;
	double	t;
	int		x1;
	double	q;

	x1 = p->result[a].x1;
	d = p->result[z].x1 - x1;
	q = 1 / d;
	t = -x1;
	while (ft_abs(p->result[z].x1 - x1))
	{
		if (p->color)
			ft_pixel_put(p, x1, y1, ft_color_average(p->ground, p->height, 	\
			ft_average(p->result[a].z, p->result[z].z, (x1 + t) * q) / p->max));
		else
			ft_pixel_put(p, x1, y1, ft_color_average(p->result[a].color, 	\
			p->result[z].color, (x1 + t) * q));
		x1 = x1 <= p->result[z].x1 ? x1 + 1 : x1 - 1;
	}
	if (p->color)
		ft_pixel_put(p, x1, y1, ft_color_average(p->ground, p->height, 		\
		ft_average(p->result[a].z, p->result[z].z, (x1 + t) * q) / p->max));
	else
		ft_pixel_put(p, x1, y1, ft_color_average(p->result[a].color, 		\
		p->result[z].color, (x1 + t) * q));
}

int		ft_line_straight(t_param *param, int a, int z)
{
	int		x1;
	int		y1;

	x1 = param->result[a].x1;
	y1 = param->result[a].y1;
	if (x1 == param->result[z].x1)
	{
		ft_line_straight_horiz(param, a, z, x1);
		return (1);
	}
	else if (y1 == param->result[z].y1)
	{
		ft_line_straight_vert(param, a, z, y1);
		return (1);
	}
	return (0);
}

void	ft_line_horiz(t_param *p, int a, int z, double b)
{
	double	d;
	int		x1;
	double	dx;

	x1 = p->result[a].x1;
	d = 1 / (double)(p->result[z].x1 - x1);
	dx = (p->result[z].y1 - p->result[a].y1) * d;
	while (p->result[z].x1 - x1)
	{
		if (p->color)
			ft_pixel_put(p, x1, x1 * dx + b, ft_color_average(p->ground, 	\
			p->height, ft_average(p->result[a].z, p->result[z].z, 			\
			(x1 - p->result[a].x1) * d) / p->max));
		else
			ft_pixel_put(p, x1, x1 * dx + b, 								\
			ft_color_average(p->result[a].color, p->result[z].color, 		\
			(x1 - p->result[a].x1) * d));
		x1 = x1 <= p->result[z].x1 ? x1 + 1 : x1 - 1;
	}
	if (p->color)
		ft_pixel_put(p, x1, x1 * dx + b, 									\
		ft_color_average(p->ground, p->height, p->result[z].z / p->max));
	else
		ft_pixel_put(p, x1, x1 * dx + b, p->result[z].color);
}

void	ft_line_vert(t_param *p, int a, int z, double b)
{
	double	d;
	int		y1;
	double	dy;

	y1 = p->result[a].y1;
	d = 1 / (double)(p->result[z].y1 - y1);
	dy = (p->result[z].x1 - p->result[a].x1) * d;
	while (p->result[z].y1 - y1)
	{
		if (p->color)
			ft_pixel_put(p, (y1 - b) * dy, y1, ft_color_average(p->ground, 	\
			p->height, ft_average(p->result[a].z, p->result[z].z, 			\
			(y1 - p->result[a].y1) * d) / p->max));
		else
			ft_pixel_put(p, (y1 - b) * dy, y1, 								\
			ft_color_average(p->result[a].color, p->result[z].color, 		\
			(y1 - p->result[a].y1) * d));
		y1 = y1 <= p->result[z].y1 ? y1 + 1 : y1 - 1;
	}
	if (p->color)
		ft_pixel_put(p, (y1 - b) * dy, y1, 									\
		ft_color_average(p->ground, p->height, p->result[z].z / p->max));
	else
		ft_pixel_put(p, (y1 - b) * dy, y1, p->result[z].color);
}
