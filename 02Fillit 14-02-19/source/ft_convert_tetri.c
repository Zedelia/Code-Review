/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ref.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 17:45:01 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/25 21:17:35 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

/*
** converti un tetrimino en sa valeur en puissance de 2
*/

int		convert_tetri(char *buff)
{
	int		i;
	int		ct;
	int		nb;

	i = 0;
	ct = 0;
	nb = 0;
	while (buff[i] != '#' && i < 21)
		i++;
	while (i < 21)
	{
		if (buff[i] == '\n')
			ct = ct - 1;
		else if (buff[i] == '#')
			nb = nb + ft_pow(2, ct);
		ct++;
		i++;
	}
	return (nb);
}
