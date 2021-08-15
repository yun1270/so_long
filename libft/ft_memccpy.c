#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
	{
		if (*s == (unsigned char)c)
		{
			*d++ = *s++;
			return (d);
		}
		*d++ = *s++;
	}
	return (NULL);
}
