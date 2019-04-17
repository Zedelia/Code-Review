/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/11 21:28:31 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 15:21:04 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "keys.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# define ZOOM param->map->a
# define DIS 400
# define WIDTH (2000 - DIS)
# define HEIGHT 1124

typedef struct		s_result
{
	int				x;
	int				y;
	int				z;
	int				x1;
	int				y1;
	t_rgb			color;
}					t_result;

typedef struct		s_rotate_fdf
{
	int				x;
	int				y;
	int				z;
}					t_rotate_fdf;

typedef struct		s_rotate_map
{
	int				x;
	int				y;
	int				z;
	int				theta;
}					t_rotate_map;

typedef struct		s_map
{
	double			a;
	double			x;
	double			y;
	double			x2;
	double			y2;
	double			h;
	t_rotate_fdf	*rotate_fdf;
	t_rotate_map	*rotate_map;
	double			adaptx;
	double			adapty;
	int				lines;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*img_ptr2;
	char			*img;
	char			*img2;
	int				bpp;
	int				bpp2;
	int				s_l;
	int				s_l2;
	int				endian;
	int				endian2;
}					t_mlx;

typedef struct		s_lines
{
	int				*z;
	char			**color;
	struct s_lines	*next;
}					t_lines;

typedef struct		s_params
{
	int				button_color;
	int				size_button;
	int				proj1;
	int				proj2;
	int				proj3;
	int				color;
	int				dep;
	int				space;
	int				l;
	int				end;
	int				manual;
	int				square;
}					t_params;

typedef struct		s_mouse_side
{
	int				x;
	int				y;
}					t_mouse_side;

typedef struct		s_mouse_set
{
	int				left;
	int				right;
	int				space;
	int				stop;
	t_mouse_side	s_left;
	t_mouse_side	s_right;
}					t_mouse_set;

typedef struct		s_param
{
	t_result		*result;
	t_mlx			*mlx;
	t_map			*map;
	int				nb_lines;
	int				nb_columns;
	int				color;
	t_rgb			ground;
	t_rgb			height;
	int				max;
	int				min;
	int				proj;
	t_params		*params;
	t_mouse_set		*mouse;
	double			theta;
	double			conic;
	int				hide;
	int				verif_hide;
	int				help;
}					t_param;

typedef struct		s_rotate_dup
{
	double			r_x;
	double			r_y;
	double			r_z;
	double			f_x;
	double			f_y;
	double			f_z;
}					t_rotate_dup;

typedef struct		s_infos
{
	char			*f_x;
	char			*f_y;
	char			*f_z;
	char			*m_x;
	char			*m_y;
	char			*m_z;
}					t_infos;

void				ft_insert_list(t_param *param, char **line, 	\
					t_lines **lines);
void				ft_read_file(t_param *param, char *file, t_lines **lines);
void				ft_convert_array(t_param *param, t_lines *lines);
void				ft_search_max(t_param *param);
void				ft_line_straight_horiz(t_param *param, int a, int z, 	\
					int x1);
void				ft_line_straight_vert(t_param *param, int a, int z, int y1);
int					ft_line_straight(t_param *param, int a, int z);
void				ft_line_horiz(t_param *param, int a, int z, double b);
void				ft_line_vert(t_param *param, int a, int z, double b);
void				ft_pixel_put(t_param *param, int x, int y, t_rgb color);
void				ft_pixel_put_params(t_param *param, int x, int y, 		\
					t_rgb color);
void				ft_line(t_param *param, int a, int z);
void				ft_map_update(t_param *param);
void				ft_map_update_p(t_param *param);
void				ft_display_lines(t_param *param);
void				ft_display(t_param *param);
void				ft_display_button(t_param *param, int x, int y, char *str);
void				ft_display_button_dark(t_param *param, int x, int y, 	\
					int len);
void				ft_display_button_bg(t_param *param, int x, int y, int len);
void				ft_display_bg(t_param *param);
void				ft_display_color(t_param *param, int x, int y, t_rgb color);
void				ft_degraded(t_param *param);
void				ft_params(t_param *param);
void				ft_init(t_param *param);
int					ft_deal_key(int key, t_param *param);
int					ft_mouse_event_scroll(int key, int x, int y, 			\
					t_param *param);
int					ft_line_straight_dark(t_param *param, int i, int x2, 	\
					int y2);
void				ft_line_horiz_dark(t_param *param, int i, int x2, int y2);
void				ft_line_vert_dark(t_param *param, int i, int x2, int y2);
void				ft_line_dark(t_param *param, int i, int x2, int y2);
int					ft_op_straight_dark(t_param *param, int i, int direction);
void				ft_op_horiz_dark(t_param *param, int i, double b, 		\
					int direction);
void				ft_op_dark(t_param *param, int i, int direction);
int					ft_mouse_move(int x, int y, t_param *param);
int					ft_deal_key_release(int key, int x, int y, t_param *param);
void				ft_map_update_c(t_param *param);
void				ft_informations(t_param *param);
void				ft_string_put(t_param *param);
void				ft_help(t_param *param);
int					ft_button_change(int y, t_param *param);
void				ft_color_buttons(int key, int x, int y, t_param *param);
void				ft_display_informations(t_param *param);
void				ft_display_buttons_bg(t_param *param);
void				ft_display_color_buttons(t_param *param);
void				ft_deal_key_moves(int key, t_param *param);
void				ft_deal_key_projs(int key, t_param *param);
void				ft_create_img(t_param *param);
void				ft_put_destroy_img(t_param *param);
void				ft_init_x_line_dark(t_param *param, int i, int x, int y);
void				ft_init_y_line_dark(t_param *param, int i, int x, int y);
void				ft_init_x_line_dark_direction(t_param *param, int i, 	\
					int x, int y);
void				ft_init_y_line_dark_direction(t_param *param, int i, 	\
					int x, int y);
void				ft_deal_key_zoom(int key, t_param *param);

#endif
