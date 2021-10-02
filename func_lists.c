#include "../push_swap.h"

void	ra(t_element **ast, t_element **cst)
{
	t_element	*head;
	t_element	*tmp;
	t_element	*spec;

	if ((*ast)->next != NULL)
	{
		head = (*ast)->next;
		spec = head;
		tmp = (*ast);
		while (head != NULL)
		{
			if (head->next == NULL)
			{
				head->next = tmp;
				head->next->next = NULL;
			}
			head = head->next;
		}
		(*ast) = spec;
	}
	ft_add_to(cst, 101);
}

void	rb(t_element **bst, t_element **cst)
{
	t_element	*head;
	t_element	*tmp;
	t_element	*spec;

	if ((*bst)->next != NULL)
	{
		head = (*bst)->next;
		spec = head;
		tmp = (*bst);
		while (head != NULL)
		{
			if (head->next == NULL)
			{
				head->next = tmp;
				head->next->next = NULL;
			}
			head = head->next;
		}
		(*bst) = spec;
	}
	ft_add_to(cst, 102);
}

void	rra(t_element **ast, t_element **cst)
{
	t_element	*tmp;
	t_element	*head;
	t_element	*spec;

	head = (*ast);
	spec = head;
	if ((*ast)->next != NULL)
	{
		while (head != NULL)
		{
			if (head->next->next == NULL)
			{
				tmp = head->next;
				head->next = NULL;
			}
			head = head->next;
		}
		tmp->next = spec;
		(*ast) = tmp;
	}
	ft_add_to(cst, 206);
}

void	rrb(t_element **bst, t_element **cst)
{
	t_element	*tmp;
	t_element	*head;
	t_element	*spec;

	head = (*bst);
	spec = head;
	if ((*bst)->next != NULL)
	{
		while (head != NULL)
		{
			if (head->next->next == NULL)
			{
				tmp = head->next;
				head->next = NULL;
			}
			head = head->next;
		}
		tmp->next = spec;
		(*bst) = tmp;
	}
	ft_add_to(cst, 210);
}

void	rrr(t_element **ast, t_element **bst, t_element **cst)
{
	rra(ast, cst);
	rrb(bst, cst);
	ft_add_to(cst, 416);
}
