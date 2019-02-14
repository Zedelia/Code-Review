/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:23 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 15:22:43 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		sqrt;

	if (nb <= 0)
		return (0);
	sqrt = 0;
	while (sqrt * sqrt < nb && sqrt < 46340)
		sqrt++;
	if (sqrt * sqrt == nb)
		return (sqrt);
	return (sqrt - 1);
}
