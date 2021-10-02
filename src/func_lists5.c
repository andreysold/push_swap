#include "../push_swap.h"

void	circle_cst2(t_element **head)
{
	if ((*head)->data == 102)
		write(1, "rb\n", 3);
	else if ((*head)->data == 101)
		write(1, "ra\n", 3);
	else if ((*head)->data == 206)
		write(1, "rra\n", 4);
	else if ((*head)->data == 201)
		write(1, "sa\n", 3);
	else if ((*head)->data == 202)
		write(1, "sb\n", 3);
}

void	circle_cst(t_element **cst)
{
	t_element	*head;

	head = *cst;
	while (head->next != NULL)
	{
		if (head->data == 21)
			write(1, "pa\n", 3);
		else if (head->data == 22)
			write(1, "pb\n", 3);
		else if (head->data == 101 && head->next->data == 102)
		{
			write(1, "rr\n", 3);
			head = head->next;
		}
		else
			circle_cst2(&head);
		head = head->next;
	}
	write(1, "ra\n", 3);
}

void	process3(t_element **ast, t_value **v, t_element **c, t_element **b)
{
	while ((*ast)->flag != 1)
	{
		(*v)->flag = (*ast)->flag;
		(*v)->count = fromAtoBf(ast, b, v, c);
		while ((*v)->count-- > 0)
			rra(ast, c);
		while ((*b))
			medBtoA(ast, b, v, c);
	}
}

void	ft_add_to(t_element **cst, int value)
{
	t_element	*head;

	head = (*cst);
	if (head == NULL)
	{
		head = malloc(sizeof(t_element));
		head->data = value;
		(*cst) = head;
	}
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = malloc(sizeof(t_element));
		head->next->data = value;
		head->next->next = NULL;
	}
}

void	value_sort(t_value **val, t_element **bst)
{
	(*val)->max = (*val)->mid;
	(*val)->next = minlist(*bst);
	(*val)->mid = ((*val)->max - (*val)->next) / 2 + (*val)->next + 3;
	(*val)->flag = (*bst)->flag;
}
