#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst != NULL)
	{
		del((void *)(*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
	}
}
