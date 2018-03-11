//
// Created by Dmitry Melehov on 3/5/18.
//

#include "../includes/push_swap.h"

static void	init_arrays(t_main *m)
{
	m->cmd_name[0] = "sa\n";
	m->cmd_name[1] = "sb\n";
	m->cmd_name[2] = "ss\n";
	m->cmd_name[3] = "pa\n";
	m->cmd_name[4] = "pb\n";
	m->cmd_name[5] = "ra\n";
	m->cmd_name[6] = "rb\n";
	m->cmd_name[7] = "rr\n";
	m->cmd_name[8] = "rra\n";
	m->cmd_name[9] = "rrb\n";
	m->cmd_name[10] = "rrr\n";
	m->cmd_name[11] = NULL;
	m->op[0] = &op_sa;
	m->op[1] = &op_sb;
	m->op[2] = &op_ss;
	m->op[3] = &op_pa;
	m->op[4] = &op_pb;
	m->op[5] = &op_ra;
	m->op[6] = &op_rb;
	m->op[7] = &op_rr;
	m->op[8] = &op_rra;
	m->op[9] = &op_rrb;
	m->op[10] = &op_rrr;
	m->op[11] = NULL;
}

t_main	*init_main_struct(int prog)
{
	t_main *m;

	m = (t_main *)ft_malloc_s(1, sizeof(t_main));
	m->a = NULL;
	m->b = NULL;
	m->prog = prog;
	m->size_a = 0;
	m->size_b = 0;
	init_arrays(m);
	return (m);
}