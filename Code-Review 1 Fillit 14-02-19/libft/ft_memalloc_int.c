/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc_int.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 10:13:36 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 10:17:12 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		*ft_memalloc_int(int size, int full, int end)
{
	int		*tab;
	int		i;

	if (!(tab = (int *)malloc(sizeof(int) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
		tab[i++] = full;
	tab[i] = end;
	return (tab);
}
