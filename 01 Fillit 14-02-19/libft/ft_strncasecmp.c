/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncasecmp.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:26 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:26 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (ft_toupper(*s1) == ft_toupper(*s2) && *s1 && --n)
	{
		s1++;
		s2++;
	}
	return ((int)(unsigned char)*s1 - (int)(unsigned char)*s2);
}
