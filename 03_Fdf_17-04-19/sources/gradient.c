/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gradient.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 12:28:42 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_display_degraded_borders(t_param *param)
{
	int		i;
	int		j;
	double	c;
	t_rgb	color;

	color = ft_color_hex_to_rgb("0xFFFFFF");
	i = param->params->end - param->params->l - 1;
	j = param->params->color - 1;
	c = 0;
	while (c < param->params->l + 2)
	{
		ft_pixel_put_params(param, i + c, j, color);
		ft_pixel_put_params(param, i + c, j + param->params->manual + 	\
		param->params->square - param->params->color + 1, color);
		c++;
	}
	c = 0;
	while (c < param->params->manual + param->params->square - 			\
	param->params->color + 2)
	{
		ft_pixel_put_params(param, i, j + c, color);
		ft_pixel_put_params(param, i + param->params->l + 2, j + c, color);
		c++;
	}
}

static void	ft_display_degraded(t_param *param)
{
	int		i;
	int		j;
	double	c;

	c = 0;
	j = param->params->color - 1;
	while (++j < param->params->manual + param->params->square)
	{
		i = param->params->end - param->params->l - 1;
		while (++i <= param->params->end)
			ft_pixel_put_params(param, i, j, 							\
			ft_color_average(ft_color_hex_to_rgb("0xff"), 				\
			ft_color_hex_to_rgb("0x00"), c / (param->params->manual + 	\
			param->params->square - param->params->color)));
		c++;
	}
	ft_display_degraded_borders(param);
}

static void	ft_degraded_borders(t_param *param)
{
	int		i;
	int		j;
	double	c;
	t_rgb	color;

	color = ft_color_hex_to_rgb("0xFFFFFF");
	i = param->params->dep - 1;
	j = param->params->color - 1;
	c = 0;
	while (c < 258)
	{
		ft_pixel_put_params(param, i, j + c, color);
		ft_pixel_put_params(param, i + c, j, color);
		ft_pixel_put_params(param, i + 257, j + c, color);
		ft_pixel_put_params(param, i + c, j + 257, color);
		c++;
	}
}

static void	ft_main_degraded(t_param *param)
{
	ft_degraded_borders(param);
	ft_display_color(param, param->params->dep, param->params->manual, 		\
	ft_color_hex_to_rgb("0xFFFF00"));
	ft_display_color(param, (DIS - param->params->space - param->params->l 	\
	- param->params->square) / 2, param->params->manual, 					\
	ft_color_hex_to_rgb("0xFF00FF"));
	ft_display_color(param, param->params->dep + 256 - 						\
	param->params->square, param->params->manual, 							\
	ft_color_hex_to_rgb("0x00FFFF"));
	ft_display_degraded(param);
}

void		ft_degraded(t_param *param)
{
	int		i;
	int		j;
	double	c1;
	double	c2;

	c1 = 0;
	j = param->params->color - 1;
	while (++j < param->params->color + 256)
	{
		c2 = 0;
		i = param->params->dep - 1;
		while (++i < param->params->dep + 256)
		{
			ft_pixel_put_params(param, i, j, 								\
			ft_color_average(ft_color_average(ft_color_hex_to_rgb("0xff0"), \
			ft_color_hex_to_rgb("0x0000ff"), c2 / 256), 					\
			ft_color_average(ft_color_hex_to_rgb("0x00ff00"), 				\
			ft_color_hex_to_rgb("0xff"), c2 / 256), c1 / 256));
			c2++;
		}
		c1++;
	}
	ft_main_degraded(param);
}
