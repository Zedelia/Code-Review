/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stractrim.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/05 11:18:46 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 15:37:39 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stractrim(const char *str, const char c)
{
	char	*new;
	int		i;

	if (!(c && str && (new = (char*)malloc(sizeof(*new) * 	\
						(ft_strlen(str) - ft_occur(str, c) + 1)))))
		return (NULL);
	i = 0;
	if (*str != c)
		new[i] = *str;
	while (*++str)
		if (*str != c)
			new[++i] = *str;
	new[++i] = '\0';
	return (new);
}
