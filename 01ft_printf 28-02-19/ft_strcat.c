#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int size_s1;
	int i;

	size_s1 = ft_strlen(s1);
	i = 0;
	while (s2[i] != '\0')
	{
		s1[size_s1 + i] = s2[i];
		i++;
	}
	s1[size_s1 + i] = '\0';
	return (s1);
}
