#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	size_s1;
	size_t	i;

	size_s1 = ft_strlen(s1);
	i = 0;
	while (i < n && s2[i] != '\0')
	{
		s1[size_s1 + i] = s2[i];
		i++;
	}
	s1[size_s1 + i] = '\0';
	return (s1);
}
