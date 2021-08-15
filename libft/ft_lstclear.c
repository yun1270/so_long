#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*a;
	t_list	*b;

	if (!lst)
		return ;
	b = *lst;
	while (b)
	{
		a = b->next;
		ft_lstdelone(b, del);
		b = a;
	}
	*lst = NULL;
}
