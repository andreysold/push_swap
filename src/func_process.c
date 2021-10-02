#include "../push_swap.h"

void	process2(t_element **ast, t_element **bst, t_value **val)
{
	t_element	*cst;
	t_element	*head;
	t_element	*b;

	cst = NULL;
	head = NULL;
	b = *ast;
	medAtoB(ast, bst, val, &cst);
	while (*bst)
		medBtoA(ast, bst, val, &cst);
	process3(ast, val, &cst, bst);
	(*val)->flag = (*ast)->flag;
	(*val)->count = 0;
	while ((*ast)->flag != -1)
	{
		(*val)->count = fromAtoBf(ast, bst, val, &cst);
		while ((*val)->count-- > 0)
			rra(ast, &cst);
		while (*bst)
			medBtoA(ast, bst, val, &cst);
	}
	circle_cst(&cst);
	freelst(cst);
}

void	process(int *massiv, int len, int i, t_element *ast)
{
	t_element	*tmp;
	t_value		*val;
	long int	t;

	i = len - 1;
	val = malloc(sizeof(t_value));
	while (i >= 0)
	{
		tmp = malloc(sizeof(t_element));
		tmp->data = massiv[i];
		tmp->next = ast;
		tmp->flag = 0;
		ast = tmp;
		i--;
	}
	massiv = sort_mass(massiv, len, &t);
	if (t == 2147483649)
		exit(1);
	index_for_list(massiv, len, ast);
	before_process(&ast, &val, len);
	free (val);
	freelst(ast);
}

void	medAtoB(t_element **ast, t_element **bst, t_value **val, t_element **c)
{
	(*val)->max = maxlist(*ast);
	(*val)->next = minlist(*ast);
	(*val)->mid = (*val)->max / 2 + (*val)->next + 1;
	(*val)->flag = (*ast)->flag;
	while ((*ast) && (*ast)->flag == (*val)->flag)
	{
		(*ast)->flag++;
		if ((*ast)->order <= (*val)->mid)
			pb(ast, bst, c);
		else
			ra(ast, c);
	}
}

void	medBtoA(t_element **ast, t_element **bst, t_value **val, t_element **c)
{
	value_sort(val, bst);
	while ((*bst) && (*bst)->flag == (*val)->flag)
	{
		(*bst)->flag++;
		if ((*bst)->order == (*val)->next)
		{
			(*bst)->flag = -1;
			pa(ast, bst, c);
			ra(ast, c);
			(*val)->next++;
		}
		else if ((*bst)->order >= (*val)->mid)
		{
			(*bst)->flag++;
			pa(ast, bst, c);
		}
		else
			rb(bst, c);
	}
}

int	fromAtoBf(t_element **ast, t_element **bst, t_value **v, t_element **c)
{
	int	count;

	count = 0;
	sorting_info(ast, v, c);
	while ((*ast) && (*v)->flag == (*ast)->flag)
	{
		(*ast)->flag++;
		if ((*ast)->order <= (*v)->mid)
			pb(ast, bst, c);
		else
		{
			count++;
			ra(ast, c);
		}
	}
	return (count);
}
