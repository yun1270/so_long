#include "libft.h"

void	ft_bzero(void *b, size_t n)
{
	char	*pb;

	pb = (char *)b;
	while (n--)
		pb[n] = 0;
}
