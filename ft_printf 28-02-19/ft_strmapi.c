#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*sres;
	int		i;

	sres = NULL;
	if (s)
		sres = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (sres == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		sres[i] = f(i, s[i]);
		i++;
	}
	sres[i] = '\0';
	return (sres);
}
