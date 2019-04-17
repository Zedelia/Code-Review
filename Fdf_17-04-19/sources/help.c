/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   help.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 12:19:59 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_help(t_param *param)
{
	mlx_clear_window(param->mlx->mlx_ptr, param->mlx->win_ptr);
	mlx_put_image_to_window(param->mlx, param->mlx->win_ptr, 	\
	param->mlx->img_ptr2, 0, 0);
	ft_string_put(param);
}

static void	ft_display_help_bis(t_param *param)
{
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 				\
	DIS / 2 - 5 * ft_strlen("Window's Z axis - : Button 1"), 				\
	HEIGHT - 230, 0xCCCCCC, "Window's Z axis - : Button 1");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 				\
	DIS / 2 - 5 * ft_strlen("Window's Z axis + : Button 2"), 				\
	HEIGHT - 210, 0xCCCCCC, "Window's Z axis + : Button 2");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 				\
	DIS / 2 - 5 * ft_strlen("Figure's Z axis - : Button 3"), 				\
	HEIGHT - 180, 0xCCCCCC, "Figure's Z axis - : Button 3");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 				\
	DIS / 2 - 5 * ft_strlen("Figure's Z axis + : Button 4"), 				\
	HEIGHT - 160, 0xCCCCCC, "Figure's Z axis + : Button 4");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 				\
	DIS / 2 - 5 * ft_strlen("Span of conical projection - : Button -"), 	\
	HEIGHT - 130, 0xCCCCCC, "Span of conical projection - : Button -");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 				\
	DIS / 2 - 5 * ft_strlen("Span of conical projection + : Button +"), 	\
	HEIGHT - 110, 0xCCCCCC, "Span of conical projection + : Button +");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 				\
	DIS / 2 - 5 * ft_strlen("To display the lines : Button L"), 			\
	HEIGHT - 80, 0xCCCCCC, "To display the lines : Button L");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 				\
	DIS / 2 - 5 * ft_strlen("Hidden faces : Button H"), 					\
	HEIGHT - 50, 0xCCCCCC, "Hidden faces : Button H");
}

static void	ft_display_help(t_param *param)
{
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 				\
	DIS / 2 - 5 * ft_strlen("Help"), HEIGHT - 270, 0xCCCCCC, "Help");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 				\
	25 - 5 * ft_strlen("X"), HEIGHT - 275, 0xFFFFFF, "X");
	ft_display_help_bis(param);
}

void		ft_string_put(t_param *param)
{
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 		\
	DIS / 2 - 5 * ft_strlen("Projections"), 30, 0xCCCCCC, "Projections");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 		\
	DIS / 2 - 5 * ft_strlen("Couleurs"), 300, 0xCCCCCC, "Couleurs");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 		\
	DIS / 2 - 5 * ft_strlen(" Projection isometrique "), 			\
	param->params->proj1, 0xFFFFFF, " Projection isometrique ");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 		\
	DIS / 2 - 5 * ft_strlen("  Projection parallele  "), 			\
	param->params->proj2, 0xFFFFFF, "  Projection parallele  ");
	mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 		\
	DIS / 2 - 5 * ft_strlen("   Projection conique   "), 			\
	param->params->proj3, 0xFFFFFF, "   Projection conique   ");
	if (param->help)
		ft_display_help(param);
	else
		ft_display_informations(param);
	if (param->color)
		mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
		DIS / 2 - 5 * ft_strlen("   Couleurs manuelles   "), 		\
		param->params->button_color, 0xFFFFFF, "   Couleurs manuelles   ");
	else
		mlx_string_put(param->mlx->mlx_ptr, param->mlx->win_ptr, 	\
		DIS / 2 - 5 * ft_strlen("  Couleurs du fichier   "), 		\
		param->params->button_color, 0xFFFFFF, "  Couleurs du fichier   ");
}
