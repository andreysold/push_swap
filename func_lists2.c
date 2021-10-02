#include "../push_swap.h"

int	*sort_mass(int *mas, int len, long int *t)
{
	int	i;
	int	j;

	i = 0;
	(*t) = 2147483649;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (mas[j] > mas[j + 1])
			{
				(*t) = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = (*t);
			}
			j++;
		}
		i++;
	}
	return (mas);
}

void	index_for_list(int *mas, int len, t_element *ast)
{
	t_element	*tmp;
	int			i;

	tmp = ast;
	while (tmp != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (mas[i] == tmp->data)
				tmp->order = i + 1;
			i++;
		}
		tmp = tmp->next;
	}
}

void	pb(t_element **ast, t_element **bst, t_element **cst)
{
	t_element	*first;

	if (*ast)
	{
		first = (*ast);
		(*ast) = (*ast)->next;
		first->next = (*bst);
		(*bst) = first;
	}
	ft_add_to(cst, 22);
}

void	pa(t_element **ast, t_element **bst, t_element **cst)
{
	t_element	*first;

	if (*bst)
	{
		first = (*bst);
		(*bst) = (*bst)->next;
		first->next = (*ast);
		(*ast) = first;
	}
	ft_add_to(cst, 21);
}

void	rr(t_element **ast, t_element **bst, t_element **cst)
{
	ra(ast, cst);
	rb(bst, cst);
	ft_add_to(cst, 203);
}
