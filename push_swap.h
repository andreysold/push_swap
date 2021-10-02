#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_element
{
	int					data;
	int					order;
	int					min;
	int					max;
	int					mid;
	int					flag;

	struct s_element	*next;
}						t_element;

typedef struct s_value
{
	int		i;
	int		k;
	int		min;
	int		max;
	int		mid;
	int		next;
	int		flag;
	int		count;
	int		small;
}			t_value;

void		ra(t_element **ast, t_element **cst);
void		rb(t_element **bst, t_element **cst);
void		rra(t_element **ast, t_element **cst);
void		rrb(t_element **bst, t_element **cst);
void		rrr(t_element **ast, t_element **bst, t_element **cst);
void		index_for_list(int *mas, int len, t_element *ast);
void		pb(t_element **ast, t_element **bst, t_element **cst);
void		pa(t_element **ast, t_element **bst, t_element **cst);
void		sa(t_element **ast, t_element **cst);
void		sb(t_element **bst, t_element **cst);
void		rr(t_element **ast, t_element **bst, t_element **cst);
void		ss(t_element **ast, t_element **bst, t_element **cst);
void		ra1(t_element **ast);
void		rb1(t_element **bst);
void		rra1(t_element **ast);
void		rrb1(t_element **bst);
void		rrr1(t_element **ast, t_element **bst);
void		pb1(t_element **ast, t_element **bst);
void		pa1(t_element **ast, t_element **bst);
void		sa1(t_element **ast);
void		sb1(t_element **bst);
void		rr1(t_element **ast, t_element **bst);
void		ss1(t_element **ast, t_element **bst);
void		process2(t_element **ast, t_element **bst, t_value **val);
void		process3(t_element **a, t_value **v, t_element **c, t_element **b);
void		circle_cst(t_element **cst);
void		circle_cst2(t_element **head);
void		sort_threeb(t_element **ast, t_value **val);
void		freelst(t_element *ast);
void		value_sort(t_value **val, t_element **bst);
void		sorting_info(t_element **ast, t_value **val, t_element **cst);
void		sort_three(t_element **ast, t_value **val);
void		sort_five(t_element **ast, t_element **bst, t_value **val);
void		sort_mini(t_element **ast, t_element **bst, t_value **val);
void		medBtoA(t_element **a, t_element **b, t_value **v, t_element **c);
void		medAtoB(t_element **a, t_element **b, t_value **v, t_element **c);
void		process(int *massiv, int len, int i, t_element *ast);
void		process2(t_element **ast, t_element **bst, t_value **val);
void		ft_add_to(t_element **cst, int value);
void		process_bonus(int *massiv, int len, int i, t_element **ast);
void		before_process(t_element **ast, t_value **val, int len);
void		sort_six(t_element **ast, t_element **bst, t_value **v);
void		sort_six_info(t_value **v, t_element **ast);
void		sort_three_part1(t_element **ast, t_value **val);
void		sort_five_circle(t_element **bst, t_value **v, t_element **ast);
void		info_sort_five(t_element *ast, t_value **val);
void		sort_three(t_element **ast, t_value **val);
void		funct2(t_element **ast, t_element **bst, char **tmp);
void		funct(t_element **ast, t_element **bst, char *tmp);
void		checker2(t_element **ast, t_element **bst);
void		checker3(t_element **ast, t_element **bst);
int			ft_strcmp(const char *s1, const char *s2);
int			is_sorted(t_element *a);
int			is_dubl(t_element *a);
int			*sort_mass(int *mas, int len, long int *t);
int			maxlist(t_element *ast);
int			minlist(t_element *ast);
int			count_node(t_element *st);
int			maxlistflag(t_element *ast, int flag);
int			minlistflag(t_element *ast);
int			fromAtoBf(t_element **a, t_element **b, t_value **v, t_element **c);
long int	ft_atoip(const char *s);
long int	ft_atoippart(const char *s, long int *i, long int *r, long int *m);
#endif