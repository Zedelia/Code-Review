/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:27 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:27 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ndl, size_t len)
{
	size_t	cmp;
	size_t	l;

	if (ndl[0] == '\0')
		return ((char *)hay);
	l = 0;
	while (*hay != '\0')
	{
		cmp = 0;
		while (ndl[cmp] == hay[cmp] && ndl[cmp] && l < len)
		{
			l++;
			cmp++;
		}
		if (ndl[cmp] == '\0')
			return ((char *)hay);
		hay++;
		l = l - cmp + 1;
	}
	return (NULL);
}
