/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:27 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:27 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last;

	i = 0;
	last = 0;
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (s[i] != '\0')
		if (s[i++] == c)
			last++;
	if (last == 0 || *s == '\0')
		return (NULL);
	while (*s && last > 0)
	{
		if (*s == c)
			last--;
		if (last > 0)
			s++;
	}
	return ((char *)s);
}
