/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 18:05:31 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 20:23:04 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		size;

	if (!n)
		return (ft_strdup("0"));
	size = ft_intlen(n);
	if (!(s = ft_strnew(size)))
		return (NULL);
	while (size--)
	{
		s[size] = ft_digit_abs(n % 10) + '0';
		n /= 10;
	}
	if (*s == '0')
		*s = '-';
	return (s);
}
