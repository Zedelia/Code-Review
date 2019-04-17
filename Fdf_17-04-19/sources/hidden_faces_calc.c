/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hidden_faces_calc.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 15:05:43 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_op_straight_horiz_dark(t_param *p, int i, int x1, int direction)
{
	int		y1;

	if (direction)
	{
		y1 = p->result[i + 1].y1;
		while (ft_abs(p->result[i + p->nb_columns].y1 - y1))
		{
			y1 = y1 <= p->result[i + p->nb_columns].y1 ? y1 + 1 : y1 - 1;
			ft_pixel_put(p, x1, y1, ft_color_hex_to_rgb("0x00"));
			ft_line_dark(p, i, x1, y1);
			ft_line_dark(p, i + p->nb_columns + 1, x1, y1);
		}
	}
	else
	{
		y1 = p->result[i].y1;
		while (ft_abs(p->result[i + p->nb_columns + 1].y1 - y1))
		{
			y1 = y1 <= p->result[i + p->nb_columns + 1].y1 ? y1 + 1 : y1 - 1;
			ft_pixel_put(p, x1, y1, ft_color_hex_to_rgb("0x00"));
			ft_line_dark(p, i + 1, x1, y1);
			ft_line_dark(p, i + p->nb_columns, x1, y1);
		}
	}
	return (1);
}

static int	ft_op_straight_vert_dark(t_param *p, int i, int y1, int direction)
{
	int		x1;

	if (direction)
	{
		x1 = p->result[i + 1].x1;
		while (ft_abs(p->result[i + p->nb_columns].x1 - x1))
		{
			x1 = x1 <= p->result[i + p->nb_columns].x1 ? x1 + 1 : x1 - 1;
			ft_pixel_put(p, x1, y1, ft_color_hex_to_rgb("0x00"));
			ft_line_dark(p, i, x1, y1);
			ft_line_dark(p, i + p->nb_columns + 1, x1, y1);
		}
	}
	else
	{
		x1 = p->result[i].x1;
		while (ft_abs(p->result[i + p->nb_columns + 1].x1 - x1))
		{
			x1 = x1 <= p->result[i + p->nb_columns + 1].x1 ? x1 + 1 : x1 - 1;
			ft_pixel_put(p, x1, y1, ft_color_hex_to_rgb("0x00"));
			ft_line_dark(p, i + 1, x1, y1);
			ft_line_dark(p, i + p->nb_columns, x1, y1);
		}
	}
	return (1);
}

int			ft_op_straight_dark(t_param *param, int i, int direction)
{
	int x1;
	int y1;

	if (direction)
	{
		x1 = param->result[i + 1].x1;
		y1 = param->result[i + 1].y1;
	}
	else
	{
		x1 = param->result[i].x1;
		y1 = param->result[i].y1;
	}
	if ((direction && x1 == param->result[i + param->nb_columns].x1) || 	\
	(!direction && x1 == param->result[i + param->nb_columns + 1].x1))
		return (ft_op_straight_horiz_dark(param, i, x1, direction));
	if ((direction && y1 == param->result[i + param->nb_columns].y1) || 	\
	(!direction && y1 == param->result[i + param->nb_columns + 1].y1))
		return (ft_op_straight_vert_dark(param, i, y1, direction));
	return (0);
}

static void	ft_op_horiz_dark_bis(t_param *param, int i, double b)
{
	int		x1;
	int		x2;
	double	dx;

	x1 = param->result[i].x1;
	x2 = param->result[i + param->nb_columns + 1].x1;
	dx = (double)(param->result[i + param->nb_columns + 1].y1 - 	\
	param->result[i].y1) / (x2 - x1);
	while (ft_abs(x2 - x1))
	{
		ft_init_x_line_dark(param, i, x1, x1 * dx + b);
		x1 = x1 <= x2 ? x1 + 1 : x1 - 1;
	}
}

void		ft_op_horiz_dark(t_param *param, int i, double b, int direction)
{
	int		x1;
	int		x2;
	double	dx;

	if (direction)
	{
		x1 = param->result[i + 1].x1;
		x2 = param->result[i + param->nb_columns].x1;
		dx = (double)(param->result[i + param->nb_columns].y1 - 	\
		param->result[i + 1].y1) / (x2 - x1);
		while (ft_abs(x2 - x1))
		{
			ft_init_x_line_dark_direction(param, i, x1, x1 * dx + b);
			x1 = x1 <= x2 ? x1 + 1 : x1 - 1;
		}
	}
	else
		ft_op_horiz_dark_bis(param, i, b);
}
