/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 12:28:44 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 18:00:47 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_pixel_put(t_param *param, int x, int y, t_rgb color)
{
	int	p;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	p = y * param->mlx->s_l + x * 4;
	param->mlx->img[p] = (char)(color.b);
	param->mlx->img[p + 1] = (char)(color.g);
	param->mlx->img[p + 2] = (char)(color.r);
}

void		ft_pixel_put_params(t_param *param, int x, int y, t_rgb color)
{
	int	p;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	p = y * param->mlx->s_l2 + x * 4;
	param->mlx->img2[p] = (char)(color.b);
	param->mlx->img2[p + 1] = (char)(color.g);
	param->mlx->img2[p + 2] = (char)(color.r);
}

static void	ft_malloc(t_param **param, int ac)
{
	if (ac != 2 || (!((*param) = (t_param*)malloc(sizeof(*(*param))))) || 	\
	!((*param)->map = (t_map*)malloc(sizeof(*(*param)->map))) || 			\
	!((*param)->mlx = (t_mlx*)malloc(sizeof(*(*param)->mlx))) || 			\
	!((*param)->map->rotate_map = 											\
	(t_rotate_map*)malloc(sizeof(*(*param)->map->rotate_map))) || 			\
	!((*param)->map->rotate_fdf = 											\
	(t_rotate_fdf*)malloc(sizeof(*(*param)->map->rotate_fdf))) || 			\
	!((*param)->params = (t_params*)malloc(sizeof(*(*param)->params))) || 	\
	!((*param)->mouse = (t_mouse_set*)malloc(sizeof(*(*param)->mouse))))
		ft_error("error");
}

static void	ft_free_all(t_param *param, t_lines *lines)
{
	t_lines	*tmp;
	int		i;

	while (lines)
	{
		tmp = lines->next;
		i = -1;
		while (++i < param->nb_columns)
			ft_memdel((void **)&lines->color[i]);
		ft_memdel((void **)&lines->z);
		ft_memdel((void **)&lines->color);
		ft_memdel((void **)&lines);
		lines = tmp;
	}
	free(param->result);
	free(param->mlx);
	free(param->map->rotate_fdf);
	free(param->map->rotate_map);
	free(param->map);
	free(param->params);
	free(param->mouse);
	free(param);
}

int			main(int ac, char **av)
{
	t_param	*param;
	t_lines	*lines;

	param = NULL;
	ft_malloc(&param, ac);
	lines = NULL;
	ft_read_file(param, av[1], &lines);
	ft_convert_array(param, lines);
	ft_search_max(param);
	param->proj = 0;
	param->mlx->mlx_ptr = mlx_init();
	param->mlx->win_ptr = mlx_new_window(param->mlx->mlx_ptr, WIDTH + DIS, 	\
	HEIGHT, "Fdf");
	ft_init(param);
	mlx_hook(param->mlx->win_ptr, 2, 0, ft_deal_key, param);
	mlx_mouse_hook(param->mlx->win_ptr, ft_mouse_event_scroll, param);
	mlx_hook(param->mlx->win_ptr, 6, 0, ft_mouse_move, param);
	mlx_hook(param->mlx->win_ptr, 5, 0, ft_deal_key_release, param);
	mlx_hook(param->mlx->win_ptr, 17, 0, ft_exit, param);
	mlx_loop(param->mlx->mlx_ptr);
	ft_free_all(param, lines);
	return (0);
}
