/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isprime.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:19 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 15:10:58 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprime(int nb)
{
	int		sqrt;

	sqrt = 2;
	if (nb == 0)
		return (0);
	if (nb == 1 || nb == 2)
		return (1);
	while (sqrt * sqrt < nb && sqrt < 46340)
	{
		if (nb % sqrt == 0)
			return (0);
		sqrt++;
	}
	if (nb % sqrt == 0)
		return (0);
	return (1);
}
