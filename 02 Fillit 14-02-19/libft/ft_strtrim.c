/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:28 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:28 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	a;

	if (!(s))
		return (NULL);
	a = 0;
	while (ft_is_tnsp(s[a]) == 1)
		a++;
	size = ft_strlen(s);
	while (ft_is_tnsp(s[size - 1]) == 1 && size > a)
		size--;
	if (!(str = (char *)malloc(sizeof(*str) * (size - a + 1))))
		return (NULL);
	i = 0;
	while (a < size)
		str[i++] = s[a++];
	str[i] = '\0';
	return (str);
}
