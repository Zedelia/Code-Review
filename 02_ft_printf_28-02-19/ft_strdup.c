#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dst == NULL)
		return (dst);
	dst = ft_strcpy(dst, src);
	return (dst);
}
