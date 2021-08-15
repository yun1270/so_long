#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*pb;

	pb = (char *)b;
	while (len--)
		pb[len] = c;
	return (b);
}
