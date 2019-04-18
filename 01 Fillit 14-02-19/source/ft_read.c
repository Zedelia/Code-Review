/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 18:02:30 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/30 03:00:05 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

/*
** lis le fd et le retourne en char *
*/

char	*ft_read(int fd)
{
	int		rd;
	char	*buff;
	int		err;

	err = 1;
	if (!(buff = ft_memalloc(546)))
		return (0);
	if ((rd = read(fd, buff, 546)) == -1)
		err = 0;
	else if (rd > 545)
		err = 0;
	if (err == 0)
	{
		free(buff);
		ft_fail();
	}
	buff[rd] = '\0';
	return (buff);
}
