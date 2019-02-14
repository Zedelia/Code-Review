/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strupcase.c                                   .::    .:/ .      .::   */
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

char	*ft_strupcase(const char *str)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)str;
	while (str[i])
	{
		s[i] = ft_toupper(str[i]);
		i++;
	}
	s[i] = '\0';
	return (s);
}
