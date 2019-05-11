/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrimsplit.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/29 15:29:53 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 15:39:12 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtrimsplit(char **str, char *n, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (n[i])
	{
		j = 0;
		while (n[i] && n[i] != c)
		{
			i++;
			j++;
		}
		str[k++] = ft_strsub((const char*)n, i - j, j);
		while (n[i] == c)
			i++;
	}
	str[k] = 0;
	return (str);
}
