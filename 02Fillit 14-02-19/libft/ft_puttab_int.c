/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puttab_int.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 18:06:11 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 20:22:07 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_int(int *tab, int end, char sep)
{
	while (*tab != end)
	{
		ft_putnbr(*(tab++));
		ft_putchar(sep);
	}
}
