#include "../push_swap.h"

void	sort_five_circle(t_element **bst, t_value **v, t_element **ast)
{
	(*v)->flag = (*bst)->flag;
	while ((*bst) && (*v)->flag == (*bst)->flag)
	{
		(*bst)->flag++;
		pa1(ast, bst);
		ra1(ast);
		write(1, "pa\n", 3);
		write(1, "ra\n", 3);
	}
}

void	sort_five(t_element **ast, t_element **bst, t_value **v)
{
	info_sort_five(*ast, v);
	while ((*ast) && (*v)->flag == (*ast)->flag)
	{
		(*ast)->flag++;
		if ((*ast)->order >= (*v)->mid)
		{
			pb1(ast, bst);
			write(1, "pb\n", 3);
		}
		else
		{
			ra1(ast);
			write(1, "ra\n", 3);
		}
	}
	if ((*bst)->order > (*bst)->next->order)
	{
		sb1(bst);
		write(1, "sb\n", 3);
	}
	sort_three(ast, v);
	sort_five_circle(bst, v, ast);
}

void	sort_six_info(t_value **v, t_element **ast)
{
	(*v)->max = maxlist(*ast);
	(*v)->next = minlist(*ast);
	(*v)->mid = (*v)->max / 2 + (*v)->next;
	(*v)->flag = (*ast)->flag;
}

void	sort_six(t_element **ast, t_element **bst, t_value **v)
{
	sort_six_info(v, ast);
	while ((*ast) && (*v)->flag == (*ast)->flag)
	{
		(*ast)->flag++;
		if ((*ast)->order >= (*v)->mid)
		{
			pb1(ast, bst);
			write(1, "pb\n", 3);
		}
		else
		{
			ra1(ast);
			write(1, "ra\n", 3);
		}
	}
	sort_threeb(bst, v);
	sort_three(ast, v);
	while ((*bst))
	{
		pa1(ast, bst);
		write(1, "pa\n", 3);
		ra1(ast);
		write(1, "ra\n", 3);
	}
}

void	sort_mini(t_element **ast, t_element **bst, t_value **val)
{
	int			count;

	count = count_node(*ast);
	if (count == 1)
		return ;
	else if (count == 2)
	{
		if ((*ast)->next->order < (*ast)->order)
		{
			sa1(ast);
			write(1, "sa\n", 3);
		}
		exit(0);
	}
	else if (count == 3)
		sort_three(ast, val);
	else if (count > 3 && count <= 5)
		sort_five(ast, bst, val);
	else if (count == 6)
		sort_six(ast, bst, val);
}
