/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	s;

	if (!(s1 && s2))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str)
				* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	s = 0;
	i = 0;
	while (s1[i])
		str[s++] = s1[i++];
	i = 0;
	while (s2[i])
		str[s++] = s2[i++];
	str[s] = '\0';
	return (str);
}
