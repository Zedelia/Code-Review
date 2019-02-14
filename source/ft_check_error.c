/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_error.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/29 19:25:36 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/30 05:44:21 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

/*
** initialise la structure pour les caracteres normalement presents
*/

t_check	*ft_init_check(void)
{
	t_check		*ch;

	if (!(ch = (t_check *)malloc(sizeof(*ch))))
		return (0);
	ch->dieze = 0;
	ch->point = 0;
	ch->line = 0;
	return (ch);
}

/*
** verifie si le caractere est bon et l'incremente dans la structure
*/

int		ft_check_c(char c, t_check *ch)
{
	if (c == '#')
		ch->dieze = ch->dieze + 1;
	else if (c == '.')
		ch->point++;
	else if (c == '\n')
	{
		if ((ch->point + ch->dieze) % 4)
			return (WRG_L);
		ch->line++;
	}
	else
		return (WRG_C);
	return (1);
}

/*
** verifie la figure en la comparant au tableau de reference
*/

int		ft_check_fig(char *buff, int size, int *ref)
{
	int		conv;
	int		i;
	int		j;

	j = 0;
	while (j < size)
	{
		i = 0;
		if (!(conv = convert_tetri(buff)))
			return (0);
		while (conv > ref[i] && ref[i])
			i++;
		if (conv != ref[i])
			return (0);
		j = j + 21;
		buff = buff + 21;
	}
	return (1);
}

/*
** Tour de Controle check des erreurs
*/

int		ft_check_error(char *buff, int *ref)
{
	int		i;
	int		size;
	t_check	*ch;

	ch = ft_init_check();
	size = ft_strlen(buff);
	i = -1;
	while (++i < size)
	{
		if (ft_check_c(buff[i], ch) != 1)
			ft_error_buff_ch(buff, ch, ref);
		if (((ch->line + 1) % 5) == 0)
			if ((ch->point % 12) != 0 || (ch->dieze % 4) != 0)
				ft_error_buff_ch(buff, ch, ref);
	}
	if (((ch->line) % 5) != 4)
		ft_error_buff_ch(buff, ch, ref);
	if (ft_check_fig(buff, size, ref) == 0)
		ft_error_buff_ch(buff, ch, ref);
	free(ch);
	free(ref);
	return (1);
}
