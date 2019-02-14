/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_spec_rev.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:23 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 20:22:22 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_spec_rev(char *nbr)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(nbr) - 1;
	if (nbr[i] == '-')
		i++;
	while (i < len)
	{
		tmp = nbr[i];
		nbr[i] = nbr[len];
		nbr[len] = tmp;
		i++;
		len--;
	}
	return (nbr);
}
