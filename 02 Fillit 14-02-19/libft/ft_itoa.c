/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:20 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 16:17:47 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*nbr;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_nbrlen(n, 10);
	if (!(nbr = (char *)malloc(sizeof(*nbr) * (ft_nbrlen(n, 10) + 1))))
		return (NULL);
	if (n < 0)
		nbr[0] = '-';
	nbr[i--] = '\0';
	while (n != 0)
	{
		nbr[i--] = ft_abs(n % 10) + '0';
		n = n / 10;
	}
	return (nbr);
}
