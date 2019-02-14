/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcasecmp.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:24 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:24 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasecmp(const char *s1, const char *s2)
{
	while (ft_toupper(*s1) == ft_toupper(*s2) && *s1)
	{
		s1++;
		s2++;
	}
	return ((int)(unsigned char)*s1 - (int)(unsigned char)*s2);
}
