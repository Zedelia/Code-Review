/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sleep.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 18:05:49 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 18:32:53 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_sleep(int nb)
{
	int		i;

	i = 0;
	while (nb >= 0)
	{
		while (i < 10000)
			i++;
		while (i > 0)
			i--;
		nb--;
	}
}