#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*tmp_src = src;
	unsigned char		*tmp_dst;
	size_t				i;

	tmp_dst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		if (tmp_src[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
