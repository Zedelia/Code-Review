#include "libft.h"

char	*ft_itoa(int n)
{
	char			*sres;
	char			stmp[12];
	unsigned int	nb;
	int				i;

	i = 0;
	nb = n < 0 ? -n : n;
	while (nb > 0)
	{
		stmp[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	(n < 0) ? stmp[i++] = '-' : 0;
	(!n) ? stmp[i++] = '0' : 0;
	stmp[i] = '\0';
	sres = malloc(sizeof(char) * (ft_strlen(stmp) + 1));
	if (sres == NULL)
		return (NULL);
	ft_strcpy(sres, stmp);
	ft_strrev(sres);
	return (sres);
}
