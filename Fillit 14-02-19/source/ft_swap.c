/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_swap.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 05:26:12 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 05:27:22 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** swap 2 lignes entre elles
*/

void		ft_swap_line(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

/*
** Swap 2 caracteres d'une colonne entre eux
*/

void		ft_swap_col(char *t1, char *t2)
{
	char	tmp;

	tmp = *t1;
	*t1 = *t2;
	*t2 = tmp;
}
