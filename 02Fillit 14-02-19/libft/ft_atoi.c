/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:18 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:18 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int			ft_is_op(int c)
{
	return (c == '-' || c == '+');
}

static int			len_nbr(const char *nbr)
{
	int		i;

	i = 0;
	while (ft_isdigit(nbr[i]) == 1)
		i++;
	return (i);
}

static int			ft_is_space(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static const char	*check_str(const char *str)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '-' && str[i] != '+' && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (ft_isdigit(str[i + 1]) == 0)
			return (0);
	}
	while (ft_isdigit(*str) == 0 && ft_is_op(*str) == 0
			&& *str != '\0')
	{
		if (ft_is_space(*str) == 0)
			return (0);
		str++;
	}
	return (str);
}

int					ft_atoi(const char *str)
{
	int		mult;
	int		i;
	int		nb;
	int		neg;

	nb = 0;
	mult = 1;
	neg = 1;
	if ((str = check_str(str)) == 0)
		return (0);
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	if (str[0] == '-')
		neg = -1;
	if (ft_is_op(*str) == 1)
		str++;
	i = len_nbr(str);
	while (i-- > 0)
	{
		nb = nb + (str[i] - '0') * mult;
		mult = mult * 10;
	}
	return (nb * neg);
}
