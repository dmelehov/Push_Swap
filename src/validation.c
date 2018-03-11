//
// Created by Dmitry Melehov on 3/4/18.
//

#include "../includes/push_swap.h"

static char	*get_apropriated_formating(char *s)
{
	char *res;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
//	printf("TRIMMED == \"%s\"\n", s);
	res = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			j = 0;
			res[k++] = s[i];
		}
		else if (j++ == 0)
			res[k++] = ' ';
		i++;
	}
	ft_strdel(&s);
	printf("RES == \"%s\"\n", res);
	return (res);
}

static int	ft_long_to_int(char *s)
{
	size_t		i;
	intmax_t	nb;
	int			neg;

	i = 0;
	nb = 0;
	neg = (s[i] == '-' ? 1 : 0);
	if (s[i] == '-' || s[i] == '+')
		s++;
	if (s[0] == '0' && s[1] != '\0')
		M_ERROR(-1, "Bad argument formating(zeroes at start)");
	if (ft_strlen(s) > 11)
		M_ERROR(-1, "Value is out of range");
	while (s[i])
		nb = nb * 10 + ((int)s[i++] - 48);
	if ((nb > 2147483647 && neg == 0) ||
		(nb > 2147483648 && neg == 1))
		M_ERROR(-1, "Value is out of range2");
	return (neg == 1 ? -(int)nb : (int)nb);
}

static int 	check_duplicates(t_stack *st, int num)
{
	while (st)
	{
		if (st->val != num)
			st = st->next;
		else
			return (1);
	}
	return (0);
}

static void	set_new_elem(t_main *m, char *str)
{
	t_stack *s;
	t_stack *p;
	int 	res;

	res = ft_long_to_int(str);
	if (check_duplicates(m->a, res))
		M_ERROR(-1, "Duplicate numbers");
	s = (t_stack *)ft_malloc_s(1, sizeof(t_stack));
	s->val = res;
	m->size_a += 1;
//	printf("The seted_value == %d\n", s->val);
	s->next = NULL;
	p = m->a;
	if (p == NULL)
		m->a = s;
	else
	{
		while (p->next)
			p = p->next;
		p->next = s;
	}
}

static void	validate_integer(t_main *m, char *s)
{
	int	i;

	i = 0;
	if (!s || *s == '\0')
		M_ERROR(-1, "An argument is an empty string");
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			M_ERROR(-1, "Argument is not a number");
		i++;
	}
	set_new_elem(m, s);
}

static void	validate_argument(t_main *m, char *s)
{
	char	**arr;
	char 	*arg;
	int 	i;

	i = 0;
	arg = get_apropriated_formating(s);
	if (!arg || ft_strequ(arg, ""))
		M_ERROR(-1, "An argument is an empty string");
	arr = ft_strsplit(arg, ' ');
	ft_strdel(&arg);
//	printf("\tARR[%d] == \"%s\"\n", i, arr[i]);
	while (arr[i])
	{
		printf("\tARR[%d] == \"%s\"\n", i, arr[i]);
		validate_integer(m, arr[i]);
		i++;
	}
	ft_free_2d_array((void **)arr);
}

void	check_arguments(t_main *m, int ac, char **av)
{
	int	i;

	i = 0;
	printf("AC = %d\n", ac);
	while (i < ac)
	{
//		printf("AV[%d] == %s\n",i, av[i]);
		validate_argument(m, ft_strtrim(av[i]));
		i++;

		;
	}
	;
}

void	check_sorting(t_stack *st)
{
	if (st && !st->next)
		ft_printf("{green}OK{eoc}\n");
	while (st && st->next)
	{
		if (st->val < st->next->val)
			st = st->next;
		else
			exit(ft_printf("{red}KO{eoc}\n"));
		if (!st->next)
			break ;
	}
	ft_printf("{green}OK{eoc}\n");
}