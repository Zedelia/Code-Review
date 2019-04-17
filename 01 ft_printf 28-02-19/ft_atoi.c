#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	long int		res;
	int				sign;

	sign = 1;
	res = 0;
	while (*str == '\f' || *str == ' ' || *str == '\t'
			|| *str == '\n' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-' && str++)
		sign = -1;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		if (res < 0 && sign == 1)
			return (-1);
		if (res < 0 && sign == -1)
			return (0);
		i++;
	}
	return (int)(res * sign);
}
