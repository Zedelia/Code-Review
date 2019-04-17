/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   update.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 11:42:51 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_map_update(t_param *param)
{
	int				i;
	t_rotate_dup	rot;
	double			tmp_x;
	double			tmp_y;

	rot.r_x = ft_deg_to_rad(param->map->rotate_map->x);
	rot.r_y = ft_deg_to_rad(param->map->rotate_map->y);
	rot.r_z = ft_deg_to_rad(param->map->rotate_map->z);
	rot.f_x = ft_deg_to_rad(param->map->rotate_fdf->x);
	rot.f_y = ft_deg_to_rad(param->map->rotate_fdf->y);
	rot.f_z = ft_deg_to_rad(param->map->rotate_fdf->z);
	i = -1;
	while (++i < param->nb_lines * param->nb_columns)
	{
		tmp_x = ZOOM * (param->result[i].x * cos(rot.f_z) * cos(rot.f_x) - 	\
		param->result[i].y * sin(rot.f_z) * sin(rot.f_y)) * cos(rot.r_x) - 	\
		param->result[i].z * param->map->h * sin(rot.r_x);
		tmp_y = ZOOM * (param->result[i].x * sin(rot.f_z) * sin(rot.f_x) + 	\
		param->result[i].y * cos(rot.f_z) * cos(rot.f_y)) * sin(rot.r_y) - 	\
		param->result[i].z * param->map->h * cos(rot.r_y + rot.f_x - rot.f_y);
		param->result[i].x1 = (tmp_x * cos(rot.r_z) - tmp_y * 				\
		sin(rot.r_z)) + param->map->x;
		param->result[i].y1 = (tmp_x * sin(rot.r_z) + tmp_y * 				\
		cos(rot.r_z)) + param->map->y;
	}
}

void	ft_map_update_p(t_param *param)
{
	int	i;

	i = -1;
	while (++i < param->nb_lines * param->nb_columns)
	{
		param->result[i].x1 = param->result[i].x * ZOOM + param->map->x2 + 	\
		param->result[i].z * param->map->h / 2 * param->map->adaptx;
		param->result[i].y1 = param->result[i].y * ZOOM + param->map->y2 - 	\
		param->result[i].z * param->map->h / 2 * param->map->adapty;
	}
}

void	ft_map_update_c(t_param *param)
{
	int		i;
	double	tmp;

	i = -1;
	while (++i < param->nb_lines * param->nb_columns)
	{
		tmp = (param->result[i].y + param->nb_lines / 2 - 					\
		param->result[i].z * param->map->h / 30 + param->conic) * (ZOOM / 2);
		tmp = tmp < 0 ? 0 : tmp;
		param->result[i].x1 = tmp * sin(param->result[i].x * param->theta) 	\
		+ param->map->x;
		param->result[i].y1 = tmp * cos(param->result[i].x * param->theta) 	\
		+ param->map->y - param->conic * (ZOOM / 2);
	}
}

void	ft_display_lines(t_param *param)
{
	int	i;

	i = -1;
	while (++i < WIDTH)
	{
		ft_pixel_put(param, i, HEIGHT / 2, ft_color_hex_to_rgb("0xFF0000"));
		ft_pixel_put(param, WIDTH / 2, i, ft_color_hex_to_rgb("0xFF0000"));
	}
	i = -WIDTH / sqrt(3) - 1;
	while (!param->proj && ++i * sqrt(3) < WIDTH && i < HEIGHT)
	{
		ft_pixel_put(param, (i * sqrt(3) + WIDTH) / 2, (i + HEIGHT) / 2, 	\
		ft_color_hex_to_rgb("0x0000FF"));
		ft_pixel_put(param, (-i * sqrt(3) + WIDTH) / 2, (i + HEIGHT) / 2, 	\
		ft_color_hex_to_rgb("0x0000FF"));
	}
	i = -WIDTH / 2 - 1;
	while (param->proj != 2 && ++i < WIDTH / 2)
	{
		ft_pixel_put(param, i + WIDTH / 2, i + HEIGHT / 2, 					\
		ft_color_hex_to_rgb("0xFFFF00"));
		ft_pixel_put(param, i + WIDTH / 2, -i + HEIGHT / 2, 				\
		ft_color_hex_to_rgb("0xFFFF00"));
	}
}

void	ft_line(t_param *param, int a, int z)
{
	int		x1;
	int		y1;
	double	b;
	double	dx;
	double	dy;

	x1 = param->result[a].x1;
	y1 = param->result[a].y1;
	if (ft_line_straight(param, a, z))
		return ;
	dx = param->result[z].x1 - x1;
	dy = param->result[z].y1 - y1;
	b = y1 - x1 * dy / dx;
	if (ft_abs(dx / dy))
		ft_line_horiz(param, a, z, b);
	else
		ft_line_vert(param, a, z, b);
}
