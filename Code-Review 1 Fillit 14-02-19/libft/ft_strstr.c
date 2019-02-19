/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:28 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:28 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		cmp;

	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		cmp = 0;
		while (needle[cmp] == haystack[cmp] && needle[cmp])
			cmp++;
		if (needle[cmp] == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
