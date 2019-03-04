/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlowcase.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:26 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:26 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(const char *str)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)str;
	while (str[i])
	{
		s[i] = ft_tolower(str[i]);
		i++;
	}
	s[i] = '\0';
	return (s);
}
