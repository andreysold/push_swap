#include "push_swap.h"

long int	ft_atoippart(const char *s, long int *i, long int *r, long int *m)
{
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			(*m) *= -1;
		(*i)++;
	}
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		(*r) = ((*r) * 10) + (s[*i] - '0');
		(*i)++;
	}
	if (s[*i] >= 'A' && s[*i] <= 'z')
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return ((*r));
}

long int	ft_atoip(const char *s)
{
	long int	i;
	long int	min;
	long int	res;
	long int	k;

	min = 1;
	res = 0;
	i = 0;
	k = 0;
	while ((s[i] >= 0x09 && s[i] <= 0x0D) || (s[i] == ' '))
		i++;
	res = ft_atoippart(s, &i, &res, &min);
	k = res * min;
	if (k > 2147483647 || k < -2147483648)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	return (res * min);
}

int	check_valid(int *massiv, int i, int len)
{
	int	flag;
	int	k;

	k = 0;
	i = 0;
	flag = 1;
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if (massiv[i] == massiv[k])
				flag = -1;
			k++;
		}
		i++;
	}
	return (flag);
}

int	main(int ac, char **av)
{
	int			*massiv;
	int			i;
	int			j;
	t_element	*ast;

	i = 1;
	ast = NULL;
	j = 0;
	if (ac == 1)
		return (-1);
	massiv = (int *)malloc(sizeof(int) * (ac - 1));
	if (!massiv)
		return (-1);
	while (i < ac)
		massiv[j++] = ft_atoip(av[i++]);
	if (check_valid(massiv, i, j) == 1)
		process(massiv, j, i, ast);
	else
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	free (massiv);
}
