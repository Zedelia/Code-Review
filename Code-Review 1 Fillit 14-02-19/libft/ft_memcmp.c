/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:21 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:21 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cmp1;
	unsigned char	*cmp2;
	size_t			i;

	cmp1 = (unsigned char *)s1;
	cmp2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (n);
	while (i < (n - 1) && cmp1[i] == cmp2[i])
		i++;
	return (cmp1[i] - cmp2[i]);
}
