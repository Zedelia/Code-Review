/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncdelete.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 16:59:14 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 17:04:35 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strncdelete(char *str, char letter, char replace, int count)
{
	int	i;

	i = -1;
	while (str[++i] && count)
		if (str[i] == letter)
		{
			str[i] = replace;
			count--;
		}
}
