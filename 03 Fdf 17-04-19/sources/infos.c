/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   infos.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 12:09:24 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_free_infos(t_infos i)
{
	if (i.f_x)
		free(i.f_x);
	if (i.f_y)
		free(i.f_y);
	if (i.f_z)
		free(i.f_z);
	if (i.m_x)
		free(i.m_x);
	if (i.m_y)
		free(i.m_y);
	if (i.m_z)
		free(i.m_z);
}

void		ft_informations(t_param *param)
{
	t_infos	i;

	i.f_x = ft_itoa(param->map->rotate_fdf->x);
	i.f_y = ft_itoa(param->map->rotate_fdf->y);
	i.f_z = ft_itoa(param->map->rotate_fdf->z);
	i.m_x = ft_itoa(param->map->rotate_map->x);
	i.m_y = ft_itoa(param->map->rotate_map->y);
	i.m_z = ft_itoa(param->map->rotate_map->z);
	mlx_clear_window(param->mlx->mlx_ptr, param->mlx->win_ptr);
	mlx_put_image_to_window(param->mlx, param->mlx->win_ptr, 	\
	param->mlx->img_ptr2, 0, 0);
	ft_string_put(param);
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * 4 + 90, HEIGHT - 220, 0xCCCCCC, i.f_x);
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * 4 + 90, HEIGHT - 190, 0xCCCCCC, i.f_y);
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * 4 + 90, HEIGHT - 160, 0xCCCCCC, i.f_z);
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * 4 + 90, HEIGHT - 120, 0xCCCCCC, i.m_x);
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * 4 + 90, HEIGHT - 90, 0xCCCCCC, i.m_y);
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * 4 + 90, HEIGHT - 60, 0xCCCCCC, i.m_z);
	ft_free_infos(i);
}

void		ft_display_informations(t_param *param)
{
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * ft_strlen("Informations"), 					\
	HEIGHT - 270, 0xCCCCCC, "Informations");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	25 - 5 * ft_strlen("?"), HEIGHT - 275, 0xFFFFFF, "?");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * ft_strlen("Axe X de la figure :      deg"), 	\
	HEIGHT - 220, 0xCCCCCC, "Axe X de la figure :      deg");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * ft_strlen("Axe Y de la figure :      deg"), 	\
	HEIGHT - 190, 0xCCCCCC, "Axe Y de la figure :      deg");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * ft_strlen("Axe Z de la figure :      deg"), 	\
	HEIGHT - 160, 0xCCCCCC, "Axe Z de la figure :      deg");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * ft_strlen("Axe X de la fenetre :      deg"), 	\
	HEIGHT - 120, 0xCCCCCC, "Axe X de la fenetre :      deg");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * ft_strlen("Axe Y de la fenetre :      deg"), 	\
	HEIGHT - 90, 0xCCCCCC, "Axe Y de la fenetre :      deg");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
	DIS / 2 - 5 * ft_strlen("Axe Z de la fenetre :      deg"), 	\
	HEIGHT - 60, 0xCCCCCC, "Axe Z de la fenetre :      deg");
}

void		ft_display_buttons_bg(t_param *param)
{
	ft_display_button_dark(param, DIS / 2, param->params->proj1, 	\
	ft_strlen(" Projection isometrique "));
	ft_display_button_dark(param, DIS / 2, param->params->proj2, 	\
	ft_strlen("  Projection parallele  "));
	ft_display_button_dark(param, DIS / 2, param->params->proj3, 	\
	ft_strlen("   Projection conique   "));
	if (!param->proj)
		ft_display_button_bg(param, DIS / 2, param->params->proj1, 	\
		ft_strlen(" Projection isometrique "));
	else if (param->proj == 1)
		ft_display_button_bg(param, DIS / 2, param->params->proj2, 	\
		ft_strlen("  Projection parallele  "));
	else
		ft_display_button_bg(param, DIS / 2, param->params->proj3, 	\
		ft_strlen("   Projection conique   "));
	ft_display_button(param, DIS / 2, param->params->proj1, 		\
	" Projection isometrique ");
	ft_display_button(param, DIS / 2, param->params->proj2, 		\
	"  Projection parallele  ");
	ft_display_button(param, DIS / 2, param->params->proj3, 		\
	"   Projection conique   ");
	ft_display_button(param, 25, HEIGHT - 275, "?");
}

void		ft_display_color_buttons(t_param *param)
{
	if (param->color)
	{
		ft_display_button(param, DIS / 2, param->params->button_color, 	\
		"   Couleurs manuelles   ");
		ft_degraded(param);
	}
	else
		ft_display_button(param, DIS / 2, param->params->button_color, 	\
		"  Couleurs du fichier   ");
}
