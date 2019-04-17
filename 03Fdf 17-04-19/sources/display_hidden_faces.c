/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_hidden_faces.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 15:10:50 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_line_straight_horiz_dark(t_param *param, int i, int x2, int y2)
{
	int		y1;

	y1 = param->result[i].y1;
	while (ft_abs(y2 - y1))
	{
		ft_pixel_put(param, x2, y1, ft_color_hex_to_rgb("0x00"));
		y1 = y1 <= y2 ? y1 + 1 : y1 - 1;
	}
}

static void	ft_line_straight_vert_dark(t_param *param, int i, int x2, int y2)
{
	int		x1;

	x1 = param->result[i].x1;
	while (ft_abs(x2 - x1))
	{
		ft_pixel_put(param, x1, y2, ft_color_hex_to_rgb("0x00"));
		x1 = x1 <= x2 ? x1 + 1 : x1 - 1;
	}
}

int			ft_line_straight_dark(t_param *param, int i, int x2, int y2)
{
	if (param->result[i].x1 == x2)
	{
		ft_line_straight_horiz_dark(param, i, x2, y2);
		return (1);
	}
	if (param->result[i].y1 == y2)
	{
		ft_line_straight_vert_dark(param, i, x2, y2);
		return (1);
	}
	return (0);
}

void		ft_line_horiz_dark(t_param *param, int i, int x2, int y2)
{
	int		x1;
	int		y1;
	double	dx;
	double	dy;
	double	b;

	x1 = param->result[i].x1;
	y1 = param->result[i].y1;
	dy = y2 - y1;
	dx = x2 - x1;
	b = y1 - x1 * dy / dx;
	dx = dy / dx;
	while (ft_abs(x2 - x1))
	{
		x1 = x1 <= x2 ? x1 + 1 : x1 - 1;
		ft_pixel_put(param, x1, x1 * dx + b, ft_color_hex_to_rgb("0x00"));
	}
}

void		ft_line_vert_dark(t_param *param, int i, int x2, int y2)
{
	int		x1;
	int		y1;
	double	dx;
	double	dy;
	double	b;

	x1 = param->result[i].x1;
	y1 = param->result[i].y1;
	dy = y2 - y1;
	dx = x2 - x1;
	b = y1 - x1 * dy / dx;
	dy = dx / dy;
	while (ft_abs(y2 - y1))
	{
		y1 = y1 <= y2 ? y1 + 1 : y1 - 1;
		ft_pixel_put(param, (y1 - b) * dy, y1, ft_color_hex_to_rgb("0x00"));
	}
}
