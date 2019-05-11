/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:20 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:20 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*n_ptr;

	ptr = *alst;
	while (ptr)
	{
		n_ptr = ptr->next;
		del(ptr->content, ptr->content_size);
		free(ptr);
		ptr = n_ptr;
	}
	*alst = NULL;
}
