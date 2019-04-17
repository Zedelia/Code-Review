/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hex_color_complete.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 16:09:18 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 16:09:50 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hex_color_complete(char *c)
{
	int		i;
	char	*color;
	char	tmp;

	if (!c)
		return (ft_strdup("0xffffff"));
	if (!(color = (char*)malloc(sizeof(*color) * 9)))
		ft_error("error");
	i = -1;
	while (++i < 8 && c[i])
		color[i] = c[i];
	i--;
	tmp = c[i];
	while (++i < 8)
		color[i] = tmp;
	color[i] = '\0';
	return (color);
}
