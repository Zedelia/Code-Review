/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hidden_faces_lines_calc.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 15:08:41 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_line_dark(t_param *param, int i, int x2, int y2)
{
	int		x1;
	int		y1;
	double	dx;
	double	dy;

	if (ft_line_straight_dark(param, i, x2, y2))
		return ;
	x1 = param->result[i].x1;
	y1 = param->result[i].y1;
	dx = x2 - x1;
	dy = y2 - y1;
	if (ft_abs(dx / dy))
		ft_line_horiz_dark(param, i, x2, y2);
	else
		ft_line_vert_dark(param, i, x2, y2);
}

void	ft_init_x_line_dark(t_param *param, int i, int x, int y)
{
	ft_line_dark(param, i + 1, x, y);
	ft_line_dark(param, i + param->nb_columns, x, y);
	if (x != param->result[i].x1 && 	\
	y != param->result[i].y1 && y - 1 != param->result[i].y1)
	{
		ft_line_dark(param, i + 1, x, y + 1);
		ft_line_dark(param, i + param->nb_columns, x, y - 1);
	}
}

void	ft_init_y_line_dark(t_param *param, int i, int x, int y)
{
	ft_line_dark(param, i + 1, x, y);
	ft_line_dark(param, i + param->nb_columns, x, y);
	if (x != param->result[i].x1 && 	\
	y != param->result[i].y1 && x - 1 != param->result[i].x1)
	{
		ft_line_dark(param, i + 1, x + 1, y);
		ft_line_dark(param, i + param->nb_columns, x - 1, y);
	}
}

void	ft_init_x_line_dark_direction(t_param *param, int i, int x, int y)
{
	ft_line_dark(param, i, x, y);
	ft_line_dark(param, i + param->nb_columns + 1, x, y);
	if (x != param->result[i + 1].x1 && 	\
	y != param->result[i + 1].y1 && y - 1 != param->result[i + 1].y1)
	{
		ft_line_dark(param, i, x, y + 1);
		ft_line_dark(param, i + param->nb_columns + 1, x, y - 1);
	}
}

void	ft_init_y_line_dark_direction(t_param *param, int i, int x, int y)
{
	ft_line_dark(param, i, x, y);
	ft_line_dark(param, i + param->nb_columns + 1, x, y);
	if (x != param->result[i + 1].x1 && y != param->result[i + 1].y1 && 	\
	x - 1 != param->result[i + 1].x1)
	{
		ft_line_dark(param, i, x + 1, y);
		ft_line_dark(param, i + param->nb_columns + 1, x - 1, y);
	}
}
