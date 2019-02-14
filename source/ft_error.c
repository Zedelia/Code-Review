/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/30 05:43:12 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/30 05:45:25 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error_buff(char *buff)
{
	free(buff);
	ft_fail();
}

void	ft_error_buff_ref(char *buff, int *ref)
{
	free(buff);
	free(ref);
	ft_fail();
}

void	ft_error_buff_ch(char *buff, t_check *ch, int *ref)
{
	free(buff);
	free(ch);
	free(ref);
	ft_fail();
}
