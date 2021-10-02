#include "../push_swap.h"

int	maxlistflag(t_element *ast, int flag)
{
	int	max;

	max = INT_MIN;
	while (ast && ast->flag == flag)
	{
		if (ast->order > max)
			max = ast->order;
		ast = ast->next;
	}
	return (max);
}

int	count_node(t_element *st)
{
	int	i;

	i = 0;
	while (st)
	{
		i++;
		st = st->next;
	}
	return (i);
}

void	freelst(t_element *ast)
{
	t_element	*tmp;

	while (ast)
	{
		tmp = ast;
		ast = ast->next;
		free(tmp);
	}
}

int	minlistflag(t_element *ast)
{
	int	min;

	min = INT_MAX;
	while (ast != NULL)
	{
		if (ast->order < min && ast->flag != -1)
			min = ast->order;
		ast = ast->next;
	}
	return (min);
}

void	before_process(t_element **ast, t_value **val, int len)
{
	t_element	*bst;

	bst = NULL;
	if (len <= 6)
		sort_mini(ast, &bst, val);
	else
		process2(ast, &bst, val);
	freelst(bst);
}
