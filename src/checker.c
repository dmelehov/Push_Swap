#include <stdio.h>
#include "../includes/push_swap.h"


enum {ONE,TWO = 10,SRAV = TWO - 5, SRAV2};

static void	display_usage()
{
	exit(0);
}



int		executor(t_main *m, char *s)
{
	int i;

	i = 0;
	while (m->cmd_name[i])
	{
		if (ft_strequ(m->cmd_name[i], s))
		{
			m->op[i](m);
			print_stacks(m);
			return (1);
		}
		i++;
	}
	M_ERROR(-1, "Wrong command input");
	return (0);
}

void	read_commands(t_main *m)
{
	char	*cmd;
	int 	r;
	int 	i;

	cmd = ft_strnew(5);
	i = 0;
	while ((r = (int)read(0, &cmd[i], 1)) > 0)
	{
		if (i > 4)
			M_ERROR(-1, "Wrong command input");
		if (cmd[i] == '\n')
		{
			if (!executor(m, cmd))
				M_ERROR(-1, "Wrong command input");
			i = -1;
			ft_strclr(cmd);
		}
		i++;

	}
	if (r == 0 && !ft_strequ("", cmd))
		executor(m, cmd);
	if (r < 0)
		M_ERROR(-1, "Reading error");
	ft_strdel(&cmd);
}

int main(int ac, char **av)
{
	t_main	*m;
	t_stack *st;

	m = init_main_struct(CHECKER);
	if (ac < 2)
		display_usage();
	ac--;
	av++;
	check_arguments(m, ac, av);
	print_stacks(m);
	read_commands(m);
	st = m->a;
//	printf("%p\n", st);
	while (st)
	{
		printf("Stack value == %d\n", st->val);
		st = st->next;
	}
	check_sorting(m->a);
    return (0);
}