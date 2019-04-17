#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == (unsigned char)tmp[i])
			return ((void *)&tmp[i]);
		i++;
	}
	return (NULL);
}
