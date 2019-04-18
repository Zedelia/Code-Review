/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:08:27 by groubaud     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 16:08:27 by groubaud    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_word(char const *s, char c)
{
	size_t	ct;
	size_t	i;

	ct = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			ct++;
			while (s[i] != c && s[i])
				i++;
		}
		while (s[i] == c)
			i++;
	}
	return (ct);
}

static char		*ft_size_word(char const *s, size_t i, char c)
{
	size_t	a;
	char	*str;

	a = i;
	while (s[i] != c && s[i])
		i++;
	if (!(str = (char *)malloc(sizeof(*str) * (i - a + 1))))
		return (NULL);
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	t;
	size_t	a;
	size_t	i;

	i = 0;
	t = 0;
	if (!(s))
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(*tab) * (ft_count_word(s, c) + 1))))
		return (NULL);
	while (t < ft_count_word(s, c))
	{
		a = 0;
		while (s[i] == c)
			i++;
		if (!(tab[t] = ft_size_word(s, i, c)))
			return (NULL);
		while (s[i] != c && s[i])
			tab[t][a++] = s[i++];
		tab[t++][a] = '\0';
	}
	tab[t] = NULL;
	return (tab);
}
