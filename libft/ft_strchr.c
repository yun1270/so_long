#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*d;

	d = (char *)s;
	while (*d != c)
	{
		if (*d == '\0')
			return (0);
		d++;
	}
	return (d);
}
