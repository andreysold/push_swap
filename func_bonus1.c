#include "push_swap.h"
void	ra1(t_element **ast)
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
}

void	rb1(t_element **bst)
{
	t_element	*head;
	t_element	*tmp;
	t_element	*spec;

	if (*bst != NULL)
	{
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
	}
}

void	rra1(t_element **ast)
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
}

void	rrb1(t_element **bst)
{
	t_element	*tmp;
	t_element	*head;
	t_element	*spec;

	head = (*bst);
	spec = head;
	if ((*bst) != NULL)
	{
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
	}
}

void	rrr1(t_element **ast, t_element **bst)
{
	rra1(ast);
	rrb1(bst);
}
