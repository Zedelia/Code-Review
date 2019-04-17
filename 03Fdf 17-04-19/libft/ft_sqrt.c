/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/05 10:41:56 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/05 11:25:06 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int	result;

	result = nb;
	while (result && result * result >= nb)
		result--;
	return (result + 1);
}
