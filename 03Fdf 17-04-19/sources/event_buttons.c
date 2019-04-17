/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_buttons.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 14:05:11 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_button_degraded(int key, int x, int y, t_param *param)
{
	if (key == 1)
		param->height = 													\
		ft_color_average(ft_color_average(ft_color_hex_to_rgb("0xff00"), 	\
		ft_color_hex_to_rgb("0x0000ff"), 									\
		(double)(x - param->params->dep) / 256), 							\
		ft_color_average(ft_color_hex_to_rgb("0x00ff00"), 					\
		ft_color_hex_to_rgb("0xff"), 										\
		(double)(x - param->params->dep) / 256), 							\
		(double)(y - param->params->color) / 256);
	else
		param->ground = 													\
		ft_color_average(ft_color_average(ft_color_hex_to_rgb("0xff00"), 	\
		ft_color_hex_to_rgb("0x0000ff"), 									\
		(double)(x - param->params->dep) / 256), 							\
		ft_color_average(ft_color_hex_to_rgb("0x00ff00"), 					\
		ft_color_hex_to_rgb("0xff"), 										\
		(double)(x - param->params->dep) / 256), 							\
		(double)(y - param->params->color) / 256);
}

static void	ft_button_black(int key, int y, t_param *param)
{
	if (key == 1)
		param->height = ft_color_average(ft_color_hex_to_rgb("0xff"), 		\
		ft_color_hex_to_rgb("0x00"), (double)(y - param->params->color) / 	\
		(param->params->manual + param->params->square - param->params->color));
	else
		param->ground = ft_color_average(ft_color_hex_to_rgb("0xff"), 		\
		ft_color_hex_to_rgb("0x00"), (double)(y - param->params->color) / 	\
		(param->params->manual + param->params->square - param->params->color));
}

static void	ft_color_small_button(int key, t_param *param, char *color)
{
	if (key == 1)
		param->height = ft_color_hex_to_rgb(color);
	else
		param->ground = ft_color_hex_to_rgb(color);
}

static void	ft_color_small_buttons(int key, int x, int y, t_param *param)
{
	if (x >= param->params->dep && 										\
	x < param->params->dep + param->params->square && 					\
	y >= param->params->manual && 										\
	y < param->params->manual + param->params->square && 				\
	(key == 1 || key == 2))
		ft_color_small_button(key, param, "0xFFFF00");
	else if (x >= (DIS - param->params->space - param->params->l - 		\
	param->params->square) / 2 && 										\
	x < (DIS - param->params->space - param->params->l + 				\
	param->params->square) / 2 && y >= param->params->manual && 		\
	y < param->params->manual + param->params->square && 				\
	(key == 1 || key == 2))
		ft_color_small_button(key, param, "0xFF00FF");
	else if (x >= param->params->dep + 256 - param->params->square && 	\
	x < param->params->dep + 256 && y >= param->params->manual && 		\
	y < param->params->manual + param->params->square && 				\
	(key == 1 || key == 2))
		ft_color_small_button(key, param, "0x00FFFF");
}

void		ft_color_buttons(int key, int x, int y, t_param *param)
{
	if (x >= param->params->dep - 1 && x < param->params->dep + 256 && 	\
	y >= param->params->color && y < param->params->color + 256 && 		\
	(key == 1 || key == 2))
		ft_button_degraded(key, x, y, param);
	if (x >= param->params->end - param->params->l && 					\
	x < param->params->end && y >= param->params->color && 				\
	y < param->params->manual + param->params->square && 				\
	(key == 1 || key == 2))
		ft_button_black(key, y, param);
	ft_color_small_buttons(key, x, y, param);
}
