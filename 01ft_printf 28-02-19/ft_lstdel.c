#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*next;

	current = *alst;
	next = current->next;
	while (current != NULL)
	{
		del((void *)current->content, current->content_size);
		ft_memdel((void **)&current);
		current = next;
		if (current != NULL)
			next = current->next;
	}
	*alst = NULL;
}
