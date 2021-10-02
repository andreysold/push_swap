#include "../push_swap.h"

void	info_sort_five(t_element *ast, t_value **val)
{
	(*val)->max = maxlist(ast);
	(*val)->mid = (*val)->max - 1;
	(*val)->flag = ast->flag;
}

void	rr1(t_element **ast, t_element **bst)
{
	ra1(ast);
	rb1(bst);
}
