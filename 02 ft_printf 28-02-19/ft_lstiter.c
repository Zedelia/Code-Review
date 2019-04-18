#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *crawler;

	crawler = lst;
	while (crawler->next != NULL)
	{
		f(crawler);
		crawler = crawler->next;
	}
	f(crawler);
}
