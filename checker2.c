#include "push_swap.h"
#include "get_next_line.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*k1;
	unsigned char	*k2;

	k1 = (unsigned char *)s1;
	k2 = (unsigned char *)s2;
	if (*k1 == '\0')
		return (-(*k2));
	if (*k2 == '\0')
		return (*k1);
	while (*k1 != '\0' || *k2 != '\0')
	{
		if (*k1 != *k2)
			return (*k1 - *k2);
		k1++;
		k2++;
	}
	return (0);
}

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

void	funct2(t_element **ast, t_element **bst, char **tmp)
{
	if (!ft_strcmp(*tmp, "rrb"))
		rrb1(bst);
	else if (!ft_strcmp(*tmp, "rrr"))
		rrr1(ast, bst);
	else if (!ft_strcmp(*tmp, "pa"))
		pa1(ast, bst);
	else if (!ft_strcmp(*tmp, "pb"))
		pb1(ast, bst);
	else
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	funct(t_element **ast, t_element **bst, char *tmp)
{
	if (!ft_strcmp(tmp, "sa"))
		sa1(ast);
	else if (!ft_strcmp(tmp, "sb"))
		sb1(bst);
	else if (!ft_strcmp(tmp, "ra"))
		ra1(ast);
	else if (!ft_strcmp(tmp, "rb"))
		rb1(bst);
	else if (!ft_strcmp(tmp, "rr"))
		rr1(ast, bst);
	else if (!ft_strcmp(tmp, "ss"))
		ss1(ast, bst);
	else if (!ft_strcmp(tmp, "rra"))
		rra1(ast);
	else
		funct2(ast, bst, &tmp);
}
