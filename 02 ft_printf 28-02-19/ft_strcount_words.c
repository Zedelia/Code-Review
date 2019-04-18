#include "libft.h"

int	ft_strcount_words(char *s, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	if (s[0] != c && s[i] != '\0')
		words++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != c && s[i] != '\0')
				words++;
			i--;
		}
		i++;
	}
	return (words);
}
