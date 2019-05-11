/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 12:11:48 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_init_params(t_param *param)
{
	param->params->size_button = 5 * ft_strlen(" Projection isometrique ") + 10;
	param->params->proj1 = 100;
	param->params->proj2 = 160;
	param->params->proj3 = 220;
	param->params->button_color = 370;
	param->params->color = 450;
	param->params->space = 24;
	param->params->l = 30;
	param->params->dep = 	\
	(DIS - 256 - param->params->space - param->params->l) / 2;
	param->params->end = 	\
	(DIS + 256 + param->params->space + param->params->l) / 2;
	param->params->square = 40;
	param->params->manual = 730;
}

void		ft_params(t_param *param)
{
	int	i;

	param->mlx->img_ptr2 = mlx_new_image(param->mlx->mlx_ptr, DIS, HEIGHT);
	param->mlx->img2 = mlx_get_data_addr(param->mlx->img_ptr2, 	\
	&param->mlx->bpp2, &param->mlx->s_l2, &param->mlx->endian2);
	ft_init_params(param);
	mlx_clear_window(param->mlx->mlx_ptr, param->mlx->win_ptr);
	ft_display_bg(param);
	i = -1;
	while (++i < HEIGHT)
		ft_pixel_put_params(param, DIS - 1, i, ft_color_hex_to_rgb("0xFFFFFF"));
	ft_display_buttons_bg(param);
	ft_display_color_buttons(param);
	i = -1;
	while (++i < DIS)
		ft_pixel_put_params(param, i, HEIGHT - 300, 			\
		ft_color_hex_to_rgb("0xFFFFFF"));
	mlx_put_image_to_window(param->mlx, param->mlx->win_ptr, 	\
	param->mlx->img_ptr2, 0, 0);
	if (param->help)
		ft_help(param);
	else
		ft_informations(param);
	ft_display(param);
}

static void	ft_init_bis(t_param *param)
{
	param->mouse->left = 0;
	param->mouse->right = 0;
	param->mouse->space = 0;
	param->theta = 2 * M_PI / 3 / (param->nb_columns - 1);
	param->conic = 10;
	param->mouse->stop = 0;
	param->hide = 0;
	param->help = 0;
	param->verif_hide = 1;
}

void		ft_init(t_param *param)
{
	param->map->a = WIDTH < HEIGHT ? WIDTH * 2 / (param->nb_columns + 	\
	param->nb_lines) : HEIGHT * 2 / (param->nb_columns + param->nb_lines);
	param->map->h = ZOOM / 10;
	param->map->x = WIDTH / 2;
	param->map->y = HEIGHT / 2;
	param->map->x2 = WIDTH / 2;
	param->map->y2 = HEIGHT / 2;
	param->map->rotate_fdf->x = 30;
	param->map->rotate_fdf->y = 60;
	param->map->rotate_fdf->z = 45;
	param->map->rotate_map->x = 0;
	param->map->rotate_map->y = 90;
	param->map->rotate_map->z = 0;
	param->map->lines = 0;
	param->map->adaptx = param->map->h;
	param->map->adapty = param->map->h;
	param->color = 0;
	param->height.r = 255;
	param->height.g = 255;
	param->height.b = 255;
	param->ground.r = 255;
	param->ground.g = 255;
	param->ground.b = 255;
	ft_init_bis(param);
	ft_params(param);
}

void		ft_search_max(t_param *param)
{
	int	i;

	param->max = 0;
	i = -1;
	while (++i < param->nb_columns * param->nb_lines)
		if (param->result[i].z > param->max)
			param->max = param->result[i].z;
	param->min = param->max;
	i = -1;
	while (++i < param->nb_columns * param->nb_lines)
		if (param->result[i].z && param->result[i].z < param->min)
			param->min = param->result[i].z;
}
