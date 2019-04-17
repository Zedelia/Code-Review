#include "libft.h"

void	**ft_freetab(void **t, size_t len)
{
	if (t == NULL)
		return (t);
	while (len)
	{
		if (t[len] != NULL)
			free(t[len]);
		len--;
	}
	free(t);
	return (t);
}
