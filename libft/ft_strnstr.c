#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	char	*h;
	char	*n;

	n_len = ft_strlen(needle);
	n = (char *)needle;
	h = (char *)haystack;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*h && len-- >= n_len)
	{
		if (*h == *n && ft_strncmp(h, n, n_len) == 0)
			return ((char *)h);
		h++;
	}
	return (NULL);
}
