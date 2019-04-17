/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 20:50:33 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 15:03:47 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int tmp;

	tmp = 0;
	while (*needle && *haystack)
	{
		haystack -= tmp;
		needle -= tmp;
		while (*haystack && *haystack != *needle)
			haystack++;
		if (!*haystack)
			return (NULL);
		tmp = 0;
		while (*haystack && *needle && *haystack++ == *needle)
		{
			tmp++;
			needle++;
		}
	}
	if (!*needle)
		return ((char*)haystack - tmp);
	return (NULL);
}
