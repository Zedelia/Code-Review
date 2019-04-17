/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_color_hex_to_rgb.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 16:10:18 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 16:10:36 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_rgb	ft_color_hex_to_rgb(char *color)
{
	t_rgb	rgb;

	color = ft_hex_color_complete(color);
	rgb.r = ft_digit_hex_to_int(color[2]) * 16 + ft_digit_hex_to_int(color[3]);
	rgb.g = ft_digit_hex_to_int(color[4]) * 16 + ft_digit_hex_to_int(color[5]);
	rgb.b = ft_digit_hex_to_int(color[6]) * 16 + ft_digit_hex_to_int(color[7]);
	if (color)
		free(color);
	return (rgb);
}
