/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puterror.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 15:39:41 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 15:46:27 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_puterror(char const *s)
{
	if (s)
		write(2, s, ft_strlen(s));
}
