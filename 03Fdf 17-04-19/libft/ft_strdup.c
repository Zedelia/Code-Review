/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:29:26 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 11:39:36 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	if (!s1 || !(cpy = (char*)malloc(sizeof(*cpy) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}
