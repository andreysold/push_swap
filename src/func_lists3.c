#include "../push_swap.h"

void	sa(t_element **ast, t_element **cst)
{
	t_element	*head;
	t_element	*second;

	if ((*ast)->next != NULL)
	{
		second = (*ast);
		head = (*ast)->next;
		second->next = (*ast)->next->next;
		head->next = second;
		(*ast) = head;
	}
	ft_add_to(cst, 201);
}

void	sb(t_element **bst, t_element **cst)
{
	t_element	*head;
	t_element	*second;

	if ((*bst)->next != NULL)
	{
		second = (*bst);
		head = (*bst)->next;
		second->next = (*bst)->next->next;
		head->next = second;
		(*bst) = head;
	}
	ft_add_to(cst, 202);
}

void	ss(t_element **ast, t_element **bst, t_element **cst)
{
	sa(ast, cst);
	sb(bst, cst);
	ft_add_to(cst, 403);
}

int	maxlist(t_element *ast)
{
	int	max;

	max = INT_MIN;
	while (ast != NULL)
	{
		if (ast->order > max)
			max = ast->order;
		ast = ast->next;
	}
	return (max);
}

int	minlist(t_element *ast)
{
	int	min;

	min = INT_MAX;
	while (ast != NULL)
	{
		if (ast->order < min)
			min = ast->order;
		ast = ast->next;
	}
	return (min);
}
