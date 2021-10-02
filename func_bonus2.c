#include "push_swap.h"
void	sa1(t_element **ast)
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
}

void	sb1(t_element **bst)
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
}

void	ss1(t_element **ast, t_element **bst)
{
	sa1(ast);
	sb1(bst);
}

void	pb1(t_element **ast, t_element **bst)
{
	t_element	*first;

	if (*ast)
	{
		first = (*ast);
		(*ast) = (*ast)->next;
		first->next = (*bst);
		(*bst) = first;
	}
}

void	pa1(t_element **ast, t_element **bst)
{
	t_element	*first;

	if (*bst)
	{
		first = (*bst);
		(*bst) = (*bst)->next;
		first->next = (*ast);
		(*ast) = first;
	}
}
