#include "push_swap.h"
#include "get_next_line.h"

int	is_dubl(t_element *a)
{
	t_element	*tmp;

	while (a->next != NULL)
	{
		tmp = a;
		while (tmp->next != NULL)
		{
			if (tmp->next->data == a->data)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
