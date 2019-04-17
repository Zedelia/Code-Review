/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 14:44:11 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 17:55:52 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = 0;
	if (!(s && f && (new = (char*)malloc(sizeof(*new) * 	\
						(ft_strlen(s) + 1)))))
		return (NULL);
	while (*s)
		new[i++] = f(*s++);
	new[i] = '\0';
	return (new);
}
