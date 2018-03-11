//
// Created by Dmitry Melehov on 3/5/18.
//

#include "../includes/push_swap.h"

void	op_sb(t_main *m)
{
	t_stack *st;
	int 	tmp;

	st = m->b;
	if (st && st->next)
	{
		tmp = st->next->val;
		st->next->val = st->val;
		st->val = tmp;
	}
}

void	op_sa(t_main *m)
{
	t_stack *st;
	int 	tmp;

	st = m->a;
	if (st && st->next)
	{
		tmp = st->next->val;
		st->next->val = st->val;
		st->val = tmp;
	}
}

void	op_ss(t_main *m)
{
	op_sa(m);
	op_sb(m);
}

void	op_ra(t_main *m)
{
	t_stack *st;
	t_stack	*tmp;

	st = m->a;
	tmp = m->a;
	if (st && st->next)
	{
		m->a = st->next;
		while (st->next)
			st = st->next;
		st->next = tmp;
		tmp->next = NULL;
	}
}

void	op_rb(t_main *m)
{
	t_stack *st;
	t_stack	*tmp;

	st = m->b;
	tmp = m->b;
	if (st && st->next)
	{
		m->b = st->next;
		while (st->next)
			st = st->next;
		st->next = tmp;
		tmp->next = NULL;
	}
}
void	op_rr(t_main *m)
{
	op_ra(m);
	op_rb(m);
}

void	op_rra(t_main *m)
{
	t_stack *st;
	t_stack	*tmp;
	t_stack	*tmp2;

	st = m->a;
	tmp = m->a;
	if (tmp && tmp->next)
	{
		while (tmp->next)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp2->next = NULL;
		m->a = tmp;
		tmp->next = st;
	}
}

void	op_rrb(t_main *m)
{
	t_stack *st;
	t_stack	*tmp;
	t_stack	*tmp2;

	st = m->b;
	tmp = m->b;
	if (tmp && tmp->next)
	{
		while (tmp->next)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		tmp2->next = NULL;
		m->b = tmp;
		tmp->next = st;
	}
}

void	op_rrr(t_main *m)
{
	op_rra(m);
	op_rrb(m);
}

void	op_pa(t_main *m)
{
	t_stack *a;
	t_stack *b;

	a = m->a;
	b = m->b;
	if (m->b)
	{
		m->b = b->next;
		m->a = b;
		b->next = a;
		m->size_a += 1;
		m->size_b -= 1;
	}
}

void	op_pb(t_main *m)
{
	t_stack *a;
	t_stack *b;

	a = m->a;
	b = m->b;
	if (m->a)
	{
		m->a = a->next;
		m->b = a;
		a->next = b;
		m->size_a -= 1;
		m->size_b += 1;
	}
}

void	print_stacks(t_main *m)
{
	t_stack *a;
	t_stack *b;

	a = m->a;
	b = m->b;
	printf("_________\n");
	printf("  A  |  B\n");
	printf("_________\n");
	printf("  %d  |  %d\n", m->size_a, m->size_b);
	printf("_________\n");
	while (a != NULL || b != NULL)
	{
		if (a && b)
			printf("%3d  |%3d\n", a->val, b->val);
		else if (a && !b)
			printf("%3d  |%3s\n", a->val, " ");
		else if (!a && b)
			printf("%3s  |%3d\n", " ", b->val);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	printf("_________\n");
}