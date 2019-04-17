/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_mouse.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/19 11:59:46 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/16 16:19:16 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_moves(int key, int x, int y, t_param *param)
{
	if (!param->proj && key == 1 && x >= DIS && x < WIDTH + DIS && y >= 0 	\
	&& y < HEIGHT)
	{
		if (!param->mouse->left)
		{
			param->mouse->s_left.x = x;
			param->mouse->s_left.y = y;
			param->verif_hide = 0;
		}
		param->mouse->left = 1;
	}
	else if (!param->proj && key == 2 && x >= DIS && x < WIDTH + DIS && 	\
	y >= 0 && y < HEIGHT)
	{
		if (!param->mouse->right)
		{
			param->mouse->s_right.x = x;
			param->mouse->s_right.y = y;
			param->verif_hide = 0;
		}
		param->mouse->right = 1;
	}
	else if (param->proj == 2 && key == 1 && x >= DIS && x < WIDTH + DIS 	\
	&& y >= 0 && y < HEIGHT)
		param->mouse->stop = 1;
}

int			ft_mouse_event_scroll(int key, int x, int y, t_param *param)
{
	if (x >= DIS / 2 - param->params->size_button && x <= DIS / 2 + 		\
	param->params->size_button && ft_button_change(y, param))
		ft_params(param);
	else if (x >= 25 - 16 && x <= 25 + 16 && y >= HEIGHT - 275 - 10 && y 	\
	<= HEIGHT - 275 + 30)
		param->help = param->help ? 0 : 1;
	if (param->color)
		ft_color_buttons(key, x, y, param);
	ft_moves(key, x, y, param);
	if (key == 4)
		param->map->h--;
	else if (key == 5 && (param->proj != 2 || param->min < 0 || 			\
	((param->result[param->nb_columns * param->nb_lines - 1].y + 			\
	param->nb_lines / 2 - param->min * param->map->h / 30 + param->conic) 	\
	* (ZOOM / 2)) > 0))
		param->map->h++;
	ft_display(param);
	return (0);
}

static void	ft_mouse_move_buttons(int x, int y, t_param *param)
{
	if (param->mouse->space)
	{
		param->mouse->s_left.x = x;
		param->mouse->s_left.y = y;
		param->mouse->s_right.x = x;
		param->mouse->s_right.y = y;
	}
	if (param->mouse->left)
	{
		param->map->rotate_map->x -= (x - param->mouse->s_left.x) / 3;
		param->map->rotate_map->y += (y - param->mouse->s_left.y) / 3;
		param->mouse->s_left.x = x;
		param->mouse->s_left.y = y;
	}
	else if (param->mouse->right)
	{
		param->map->rotate_fdf->x += (y - param->mouse->s_right.y) / 3;
		param->map->rotate_fdf->y += (x - param->mouse->s_right.x) / 3;
		param->mouse->s_right.x = x;
		param->mouse->s_right.y = y;
	}
	param->mouse->space = 0;
}

int			ft_mouse_move(int x, int y, t_param *param)
{
	if (!param->proj && x >= DIS && x < WIDTH + DIS && y >= 0 && y < HEIGHT)
		ft_mouse_move_buttons(x, y, param);
	else
		param->mouse->space = 1;
	if (param->proj == 2 && param->mouse->stop && x >= DIS && 	\
	x < WIDTH + DIS && y >= 0 && y < HEIGHT)
		param->conic = y - HEIGHT / 2 > 0 ? 0 : -2 * (y - HEIGHT / 2) / ZOOM;
	else
		param->mouse->stop = 0;
	ft_display(param);
	return (0);
}

void		ft_deal_key_moves(int key, t_param *param)
{
	if (key == LEFT)
	{
		param->map->x -= ZOOM / 2;
		param->map->x2 -= ZOOM / 2;
	}
	else if (key == RIGHT)
	{
		param->map->x += ZOOM / 2;
		param->map->x2 += ZOOM / 2;
	}
	else if (key == DOWN)
	{
		param->map->y += ZOOM / 2;
		param->map->y2 += ZOOM / 2;
	}
	else if (key == UP)
	{
		param->map->y -= ZOOM / 2;
		param->map->y2 -= ZOOM / 2;
	}
}
