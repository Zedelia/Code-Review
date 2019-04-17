/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 15:01:19 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 13:05:18 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_display_down_right(t_param *param)
{
	int	i;

	ft_create_img(param);
	i = param->nb_lines * param->nb_columns;
	while (--i)
	{
		if (param->hide && i >= param->nb_columns && i % param->nb_columns 	\
		&& ((!param->map->adaptx && param->result[i - 1].z < 				\
		param->result[i].z) || (!param->map->adapty && 						\
		param->result[i - param->nb_columns].z < param->result[i].z)))
			ft_op_dark(param, i - param->nb_columns - 1, 1);
		else if (param->hide && i >= param->nb_columns && i % param->nb_columns)
			ft_op_dark(param, i - param->nb_columns - 1, 0);
		if (i % param->nb_columns)
			ft_line(param, i, i - 1);
		if (i >= param->nb_columns)
			ft_line(param, i, i - param->nb_columns);
	}
	ft_put_destroy_img(param);
}

static void	ft_display_top_right(t_param *param)
{
	int	i;
	int	j;

	ft_create_img(param);
	i = -1;
	while (++i < param->nb_lines)
	{
		j = param->nb_columns;
		while (j--)
		{
			if (param->hide && i * param->nb_columns + j < 				\
			(param->nb_lines - 1) * param->nb_columns && 				\
			(i * param->nb_columns + j) % param->nb_columns)
				ft_op_dark(param, i * param->nb_columns + j - 1, 1);
			if ((i * param->nb_columns + j) % param->nb_columns)
				ft_line(param, i * param->nb_columns + j, i * 				\
				param->nb_columns + j - 1);
			if (i * param->nb_columns + j < (param->nb_lines - 1) * 	\
			param->nb_columns)
				ft_line(param, i * param->nb_columns + j, i * 				\
				param->nb_columns + j + param->nb_columns);
		}
	}
	ft_put_destroy_img(param);
}

static void	ft_display_down_left(t_param *param)
{
	int	i;
	int	j;

	ft_create_img(param);
	i = param->nb_lines;
	while (i--)
	{
		j = -1;
		while (++j < param->nb_columns)
		{
			if (param->hide && i * param->nb_columns + j >= 			\
			param->nb_columns && (i * param->nb_columns + j + 1) % 		\
			param->nb_columns)
				ft_op_dark(param, i * param->nb_columns + j - 			\
				param->nb_columns, 1);
			if ((i * param->nb_columns + j + 1) % param->nb_columns)
				ft_line(param, i * param->nb_columns + j, i * 			\
				param->nb_columns + j + 1);
			if (i * param->nb_columns + j >= param->nb_columns)
				ft_line(param, i * param->nb_columns + j, i * 			\
				param->nb_columns + j - param->nb_columns);
		}
	}
	ft_put_destroy_img(param);
}

static int	ft_update(t_param *param)
{
	if (param->help)
		ft_help(param);
	else
		ft_informations(param);
	if (!param->proj)
		ft_map_update(param);
	else if (param->proj == 1)
	{
		ft_map_update_p(param);
		if (param->map->adaptx >= 0 && param->map->adapty <= 0)
			ft_display_down_right(param);
		else if (param->map->adaptx > 0 && param->map->adapty > 0)
			ft_display_top_right(param);
		else if (param->map->adaptx < 0 && param->map->adapty < 0)
			ft_display_down_left(param);
		if (!(param->map->adaptx <= 0 && param->map->adapty >= 0))
			return (1);
	}
	else
		ft_map_update_c(param);
	return (0);
}

void		ft_display(t_param *param)
{
	int	i;

	if (ft_update(param))
		return ;
	ft_create_img(param);
	i = -1;
	while (++i < param->nb_columns * param->nb_lines)
	{
		if (param->hide && param->verif_hide && 							\
		i < (param->nb_lines - 1) * param->nb_columns && 					\
		((!param->map->adaptx && param->result[i + 1].z < 					\
		param->result[i + param->nb_columns + 1].z) || 						\
		(!param->map->adapty && param->result[i + param->nb_columns].z < 	\
		param->result[i + param->nb_columns + 1].z)))
			ft_op_dark(param, i, 1);
		else if (param->hide && param->verif_hide && 						\
		i < (param->nb_lines - 1) * param->nb_columns && 					\
		(i + 1) % param->nb_columns)
			ft_op_dark(param, i, 0);
		if ((i + 1) % param->nb_columns)
			ft_line(param, i, i + 1);
		if (i < (param->nb_lines - 1) * param->nb_columns)
			ft_line(param, i, i + param->nb_columns);
	}
	ft_put_destroy_img(param);
}
