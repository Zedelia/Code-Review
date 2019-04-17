/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   options.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 11:57:21 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_display_button(t_param *param, int x, int y, char *str)
{
	int		i;
	t_rgb	color;

	color = ft_color_hex_to_rgb("0xFFFFFF");
	i = x - 5 * ft_strlen(str) - 11;
	while (++i < x + 5 * (int)ft_strlen(str) + 10)
	{
		ft_pixel_put_params(param, i, y - 10, color);
		ft_pixel_put_params(param, i, y + 30, color);
	}
	i = y - 11;
	while (++i <= y + 30)
	{
		ft_pixel_put_params(param, x - 5 * ft_strlen(str) - 10, i, color);
		ft_pixel_put_params(param, x + 5 * ft_strlen(str) + 10, i, color);
	}
}

void	ft_display_button_dark(t_param *param, int x, int y, int len)
{
	int	i;
	int	j;

	j = y - 10;
	while (++j < y + 30)
	{
		i = x - 5 * len - 10;
		while (++i < x + 5 * len + 10)
			ft_pixel_put_params(param, i, j, ft_color_hex_to_rgb("0x000000"));
	}
}

void	ft_display_button_bg(t_param *param, int x, int y, int len)
{
	int	i;
	int	j;

	j = y - 10;
	while (++j < y + 30)
	{
		i = x - 5 * len - 10;
		while (++i < x + 5 * len + 10)
			ft_pixel_put_params(param, i, j, ft_color_hex_to_rgb("0x353535"));
	}
}

void	ft_display_bg(t_param *param)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < DIS)
			ft_pixel_put_params(param, j, i, ft_color_hex_to_rgb("0x151515"));
	}
}

void	ft_display_color(t_param *param, int x, int y, t_rgb color)
{
	int		i;
	int		j;
	int		c;
	t_rgb	col;

	col = ft_color_hex_to_rgb("0xFFFFFF");
	j = y - 1;
	while (++j < y + param->params->square)
	{
		i = x - 1;
		while (++i < x + param->params->square)
			ft_pixel_put_params(param, i, j, color);
	}
	i = x - 1;
	j = y - 1;
	c = 0;
	while (c < param->params->square + 2)
	{
		ft_pixel_put_params(param, i, j + c, col);
		ft_pixel_put_params(param, i + c, j, col);
		ft_pixel_put_params(param, i + param->params->square + 1, j + c, col);
		ft_pixel_put_params(param, i + c, j + param->params->square + 1, col);
		c++;
	}
}
