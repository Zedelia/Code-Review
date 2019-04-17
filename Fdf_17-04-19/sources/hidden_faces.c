/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hidden_faces.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 12:02:05 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_op_vert_dark_bis(t_param *param, int i, double b)
{
	int		y1;
	int		y2;
	double	dy;

	y1 = param->result[i].y1;
	y2 = param->result[i + param->nb_columns + 1].y1;
	dy = (double)(param->result[i + param->nb_columns + 1].x1 - 	\
	param->result[i].x1) / (y2 - y1);
	while (ft_abs(y2 - y1))
	{
		ft_init_y_line_dark(param, i, (y1 - b) * dy, y1);
		y1 = y1 <= y2 ? y1 + 1 : y1 - 1;
	}
}

static void	ft_op_vert_dark(t_param *param, int i, double b, int direction)
{
	int		y1;
	int		y2;
	double	dy;

	if (direction)
	{
		y1 = param->result[i + 1].y1;
		y2 = param->result[i + param->nb_columns].y1;
		dy = (double)(param->result[i + param->nb_columns].x1 - 	\
		param->result[i + 1].x1) / (y2 - y1);
		while (ft_abs(y2 - y1))
		{
			ft_init_y_line_dark_direction(param, i, (y1 - b) * dy, y1);
			y1 = y1 <= y2 ? y1 + 1 : y1 - 1;
		}
	}
	else
		ft_op_vert_dark_bis(param, i, b);
}

void		ft_op_dark(t_param *param, int i, int direction)
{
	double	b;
	double	dx;
	double	dy;

	if (ft_op_straight_dark(param, i, direction))
		return ;
	if (direction)
	{
		dx = param->result[i + param->nb_columns].x1 - param->result[i + 1].x1;
		dy = param->result[i + param->nb_columns].y1 - param->result[i + 1].y1;
		b = param->result[i + 1].y1 - param->result[i + 1].x1 * dy / dx;
	}
	else
	{
		dx = param->result[i + param->nb_columns + 1].x1 - param->result[i].x1;
		dy = param->result[i + param->nb_columns + 1].y1 - param->result[i].y1;
		b = param->result[i].y1 - param->result[i].x1 * dy / dx;
	}
	if (ft_abs(dx / dy))
		ft_op_horiz_dark(param, i, b, direction);
	else
		ft_op_vert_dark(param, i, b, direction);
}

void		ft_create_img(t_param *param)
{
	param->mlx->img_ptr = mlx_new_image(param->mlx->mlx_ptr, WIDTH, HEIGHT);
	param->mlx->img = mlx_get_data_addr(param->mlx->img_ptr, 				\
	&param->mlx->bpp, &param->mlx->s_l, &param->mlx->endian);
	if (param->map->lines)
		ft_display_lines(param);
}

void		ft_put_destroy_img(t_param *param)
{
	mlx_put_image_to_window(param->mlx, param->mlx->win_ptr, 				\
	param->mlx->img_ptr, DIS, 0);
	mlx_destroy_image(param->mlx->mlx_ptr, param->mlx->img_ptr);
}
