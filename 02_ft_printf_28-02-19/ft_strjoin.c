#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *sres;

	sres = NULL;
	if (s1 && s2)
		sres = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (sres == NULL)
		return (NULL);
	ft_strcpy(sres, s1);
	ft_strcat(sres, s2);
	return (sres);
}
