/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:26 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:26 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	t;
	size_t	lend;

	lend = ft_strlen(dest);
	t = 0;
	i = 0;
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	while (dest[t] && t < size - 1)
		t++;
	while (src[i] && t < size - 1)
		dest[t++] = src[i++];
	dest[t] = '\0';
	return (ft_strlen(src) + lend);
}
