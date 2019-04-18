/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 18:30:37 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 18:40:47 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa_base(int n, int base)
{
	char	*str_b;
	char	*nbr;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_nbrlen(n, base);
	if (!(nbr = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str_b = ft_strdup("0123456789ABCDEF");
	if (n < 0 && base == 10)
		nbr[0] = '-';
	nbr[i--] = '\0';
	while (n != 0)
	{
		nbr[i--] = str_b[ft_abs(n % base)];
		n = n / base;
	}
	return (nbr);
}
