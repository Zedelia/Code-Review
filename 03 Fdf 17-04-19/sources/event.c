/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 11:55:18 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_deal_key_zoom(int key, t_param *param)
{
	int	dif;

	dif = (param->nb_columns + param->nb_lines) / 2 * ZOOM / 	\
	((WIDTH + HEIGHT) / 2);
	if (key == LESS && ZOOM > 1)
	{
		if (!dif)
			dif = 1;
		param->map->h = (ZOOM - dif) * param->map->h / ZOOM;
		ZOOM -= dif;
	}
	else if (key == MORE && ZOOM < (WIDTH + HEIGHT) / 2)
	{
		if (!dif)
			dif = 1;
		param->map->h = (ZOOM + dif) * param->map->h / ZOOM;
		ZOOM += dif;
	}
}

int		ft_deal_key(int key, t_param *param)
{
	if (key == ESC)
		exit(0);
	else if (key == R)
		ft_init(param);
	else if ((key == LESS || key == MORE) && ZOOM && ZOOM < 	\
	(param->nb_lines + param->nb_columns) / 2 + (WIDTH + HEIGHT) / 2)
		ft_deal_key_zoom(key, param);
	else if (key == L)
		param->map->lines = param->map->lines ? 0 : 1;
	else if (key == H)
	{
		if (param->hide)
			param->hide = 0;
		else if (param->verif_hide)
			param->hide = 1;
	}
	ft_deal_key_moves(key, param);
	ft_deal_key_projs(key, param);
	ft_display(param);
	return (0);
}

int		ft_deal_key_release(int key, int x, int y, t_param *param)
{
	(void)x;
	(void)y;
	if (key == 1)
	{
		param->mouse->left = 0;
		param->mouse->stop = 0;
	}
	else if (key == 2)
		param->mouse->right = 0;
	return (0);
}
