#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;

	res = NULL;
	if (s)
		res = malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	ft_strncpy(res, s + start, len);
	res[len] = '\0';
	return (res);
}
