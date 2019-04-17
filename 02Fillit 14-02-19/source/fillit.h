/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 18:24:35 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/30 05:44:30 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define TOO_MUCH_C -1
# define WRG_L -2
# define WRG_C -3
# define WRG_PDL -4
# define WRG_FIG -5
# define WRG_NB_L -6

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_check
{
	int	dieze;
	int	point;
	int line;
}				t_check;

typedef struct	s_tetri
{
	int				height;
	int				lenght;
	char			**tetri;
	char			name;
}				t_tetri;

typedef struct	s_all
{
	int		size_map;
	int		size_sqr;
	char	**map;
	int		nb;
}				t_all;

t_all			*ft_init_gl(int nb_tetri);
void			ft_fail(void);

char			*ft_read(int fd);

t_check			*ft_init_check(void);
int				ft_check_c(char c, t_check *ch);
int				ft_check_error(char *buff, int *ref);

int				convert_tetri(char *buff);

void			ft_set_tetri(char **map, t_tetri t, int x, int y);
void			ft_delete_tetri(char **map, t_tetri t, int x, int y);
int				ft_check_pos(t_all *gl, t_tetri t, int x, int y);

void			ft_swap_line(char **s1, char **s2);
void			ft_swap_col(char *t1, char *t2);

int				ft_empty_col(char **tetri, int x);
char			**ft_cut_tetri(char **tetri);
t_tetri			ft_do_minos(char *buff, int len, char name);
t_tetri			*ft_do_tetri(char *buff, int len);

int				ft_size_height(char **map, int len);
int				ft_size_line(char **map, int len);
int				ft_size_square(char **map, int len);

void			ft_clean_map(char **map, int size);

char			**ft_map(int nb);
int				ft_algo(char *buff, int len);

int				ft_free_coord(t_coord *c, int ret);
void			ft_free_tetri(t_tetri *stab, int nb);
void			ft_free_all(t_all *gl);

void			ft_error_buff(char *buff);
void			ft_error_buff_ref(char *buff, int *ref);
void			ft_error_buff_ch(char *buff, t_check *ch, int *ref);

#endif
