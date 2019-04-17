/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 17:43:23 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 12:59:44 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!(new = (char*)malloc(sizeof(*new) * (len + 1))) || !s)
		return (NULL);
	ft_strncpy(new, (char *)s + start, len);
	new[len] = '\0';
	return (new);
}
