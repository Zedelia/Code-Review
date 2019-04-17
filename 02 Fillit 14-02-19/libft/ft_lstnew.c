/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:21 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:21 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;

	if (!(ptr = (t_list *)malloc(sizeof(*ptr))))
		return (NULL);
	if (content)
	{
		if (!(ptr->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(ptr->content, content, content_size);
		ptr->content_size = content_size;
	}
	else
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	ptr->next = NULL;
	return (ptr);
}
