#include "push_swap.h"
#include "get_next_line.h"

void	process_bonus(int *massiv, int len, int i, t_element **ast)
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
		tmp->next = (*ast);
		tmp->flag = 0;
		(*ast) = tmp;
		i--;
	}
	massiv = sort_mass(massiv, len, &t);
	index_for_list(massiv, len, *ast);
	free (val);
}

int	is_sorted(t_element *a)
{
	while (a->next != NULL)
	{
		if ((a->order + 1) == a->next->order)
			a = a->next;
		else
			return (1);
	}
	return (0);
}

void	checker3(t_element **ast, t_element **bst)
{
	if (is_sorted(*ast) == 0 && (*bst) == NULL)
	{
		write(1, "OK\n", 3);
		exit(1);
	}
	else
	{
		write(1, "KO\n", 3);
		exit(1);
	}
}

void	checker2(t_element **ast, t_element **bst)
{
	char	*line;

	if (is_dubl(*ast) == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (is_sorted(*ast) == 0 && (*bst) == NULL)
	{
		write(1, "OK\n", 3);
		exit(1);
	}
	while (get_next_line(0, &line))
	{
		funct(ast, bst, line);
		free(line);
		line = NULL;
	}
	free (line);
	checker3(ast, bst);
}

int	main(int ac, char **av)
{
	int			*massiv;
	int			i;
	int			j;
	t_element	*ast;
	t_element	*bst;

	bst = NULL;
	ast = NULL;
	j = 0;
	i = 1;
	if (ac == 1)
		return (-1);
	massiv = (int *)malloc(sizeof(int) * (ac - 1));
	if (!massiv)
		return (-1);
	while (i < ac)
		massiv[j++] = ft_atoip(av[i++]);
	process_bonus(massiv, j, i, &ast);
	checker2(&ast, &bst);
	free (massiv);
	freelst(ast);
}
