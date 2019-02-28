#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;
	char			stmp[12];
	int				i;

	i = 0;
	nb = n < 0 ? -n : n;
	while (nb > 0)
	{
		stmp[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
	{
		stmp[i] = '-';
		i++;
	}
	if (n == 0)
	{
		stmp[i] = '0';
		i++;
	}
	stmp[i] = '\0';
	ft_strrev(stmp);
	ft_putstr(stmp);
}
