/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 17:56:53 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/14 01:58:42 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>

void	ft_fail(void)
{
	write(1, "error\n", 6);
	exit(0);
}

t_all	*ft_init_gl(int nb_tetri)
{
	t_all	*gl;

	if (!(gl = (t_all *)malloc(sizeof(*gl))))
		return (0);
	gl->nb = nb_tetri;
	gl->map = ft_map(nb_tetri * 4 + 1);
	gl->size_map = nb_tetri * 4;
	gl->size_sqr = ft_sqrt(nb_tetri * 4);
	return (gl);
}

/*
 ** Creation de mon tableau de reference des bons tetriminos
*/

int		*ft_reference(void)
{
	int		*ref;

	if (!(ref = (int *)malloc(sizeof(int) * 20)))
		return (0);
	ref[0] = 15;
	ref[1] = 23;
	ref[2] = 27;
	ref[3] = 29;
	ref[4] = 39;
	ref[5] = 51;
	ref[6] = 57;
	ref[7] = 71;
	ref[8] = 99;
	ref[9] = 113;
	ref[10] = 153;
	ref[11] = 275;
	ref[12] = 281;
	ref[13] = 305;
	ref[14] = 401;
	ref[15] = 547;
	ref[16] = 561;
	ref[17] = 785;
	ref[18] = 4369;
	ref[19] = 0;
	return (ref);
}

int		main(int ac, char **av)
{
	char	*buff;
	int		fd;
	int		*ref;
	char	**map;

	if (ac != 2)
		ft_fail();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_fail();
	if (!(buff = ft_read(fd)))
		ft_fail();
	if (!(ref = ft_reference()))
		ft_error_buff(buff);
	if (!(ft_check_error(buff, ref)))
		ft_error_buff_ref(buff, ref);
	if (!(map = ft_map(26)))
		ft_error_buff(buff);
	ft_algo(buff, ft_strlen(buff));
	free(buff);
	return (0);
}
