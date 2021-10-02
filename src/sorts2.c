#include "../push_swap.h"

void	sorting_info(t_element **ast, t_value **val, t_element **cst)
{
	(*val)->flag = (*ast)->flag;
	(*val)->max = maxlistflag(*ast, (*val)->flag);
	(*val)->next = minlistflag(*ast);
	(*val)->mid = ((*val)->max - (*val)->next) / 2 + (*val)->next + 3;
	(*val)->flag = (*ast)->flag;
	if ((*ast)->order == (*val)->next)
	{
		(*ast)->flag = -1;
		ra(ast, cst);
		(*val)->next++;
	}
	if ((*ast)->next->order == (*val)->next)
	{
		sa(ast, cst);
		(*ast)->flag = -1;
		ra(ast, cst);
		(*val)->next++;
	}
}

void	sort_three_part1b(t_element **ast, t_value **val)
{
	if ((*ast)->order != (*val)->next && (*ast)->order > (*ast)->next->order)
	{
		sa1(ast);
		write(1, "sb\n", 3);
	}
	if ((*ast)->order != (*val)->next && (*ast)->order < (*ast)->next->order)
	{
		rra1(ast);
		write(1, "rrb\n", 4);
	}
}

void	sort_threeb(t_element **ast, t_value **val)
{
	(*val)->max = maxlist(*ast);
	(*val)->next = minlist(*ast);
	(*val)->mid = (*val)->max / 2 + (*val)->next;
	if ((*ast)->order == (*val)->max)
	{
		ra1(ast);
		write(1, "rb\n", 3);
	}
	if ((*ast)->order == (*val)->next && (*ast)->next->order == (*val)->max)
	{
		rra1(ast);
		write(1, "rrb\n", 4);
		sa1(ast);
		write(1, "sb\n", 3);
	}
	else
		sort_three_part1b(ast, val);
}

void	sort_three_part1(t_element **ast, t_value **val)
{
	if ((*ast)->order != (*val)->next && (*ast)->order > (*ast)->next->order)
	{
		sa1(ast);
		write(1, "sa\n", 3);
	}
	if ((*ast)->order != (*val)->next && (*ast)->order < (*ast)->next->order)
	{
		rra1(ast);
		write(1, "rra\n", 4);
	}
}

void	sort_three(t_element **ast, t_value **val)
{
	(*val)->max = maxlist(*ast);
	(*val)->next = minlist(*ast);
	(*val)->mid = (*val)->max / 2 + (*val)->next;
	if ((*ast)->order == (*val)->max)
	{
		ra1(ast);
		write(1, "ra\n", 3);
	}
	if ((*ast)->order == (*val)->next && (*ast)->next->order == (*val)->max)
	{
		rra1(ast);
		write(1, "rra\n", 4);
		sa1(ast);
		write(1, "sa\n", 3);
	}
	else
		sort_three_part1(ast, val);
}
