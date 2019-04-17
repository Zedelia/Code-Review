/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_projections.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 14:02:22 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_deal_key_proj1(int key, t_param *param)
{
	if (key == ONE)
		param->map->rotate_map->z--;
	else if (key == TWO)
		param->map->rotate_map->z++;
	else if (key == THREE)
	{
		param->map->rotate_fdf->z--;
		param->verif_hide = 0;
	}
	else if (key == FOUR)
	{
		param->map->rotate_fdf->z++;
		param->verif_hide = 0;
	}
}

static void	ft_deal_key_proj2(int key, t_param *param)
{
	if (key == D)
		param->map->adaptx += param->map->h;
	else if (key == A)
		param->map->adaptx -= param->map->h;
	else if (key == S)
		param->map->adapty -= param->map->h;
	else if (key == W)
		param->map->adapty += param->map->h;
}

static void	ft_deal_key_proj3(int key, t_param *param)
{
	if (key == H_ && param->theta > 0)
		param->theta -= M_PI / 6 / (param->nb_columns - 1);
	else if (key == H__ && param->theta < 2 * M_PI)
		param->theta += M_PI / 6 / (param->nb_columns - 1);
}

void		ft_deal_key_projs(int key, t_param *param)
{
	if (!param->proj)
		ft_deal_key_proj1(key, param);
	else if (param->proj == 1)
		ft_deal_key_proj2(key, param);
	else
		ft_deal_key_proj3(key, param);
}

int			ft_button_change(int y, t_param *param)
{
	if (y >= param->params->proj1 - 10 && y <= param->params->proj1 + 30)
	{
		param->proj = 0;
		return (1);
	}
	if (y >= param->params->proj2 - 10 && y <= param->params->proj2 + 30)
	{
		param->proj = 1;
		return (1);
	}
	if (y >= param->params->proj3 - 10 && y <= param->params->proj3 + 30)
	{
		param->proj = 2;
		return (1);
	}
	if (y >= param->params->button_color - 10 && y <= 	\
	param->params->button_color + 30)
	{
		param->color = param->color ? 0 : 1;
		return (1);
	}
	return (0);
}
