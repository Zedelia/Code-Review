/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 15:57:18 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 11:49:42 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_gnl
{
	int				fd;
	char			*save;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(int fd, char **line);
#endif
