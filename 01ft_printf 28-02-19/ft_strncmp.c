#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	n--;
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
