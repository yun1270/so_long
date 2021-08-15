#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ar;
	int		i;

	ar = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ar)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ar[i] = s1[i];
		i++;
	}
	ar[i] = '\0';
	return (ar);
}
