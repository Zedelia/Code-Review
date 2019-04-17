/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isgraph.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:19 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:19 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_isgraph(int c)
{
	return (c >= 33 && c <= 126);
}
