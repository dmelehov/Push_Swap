//
// Created by Dmitry Melehov on 3/5/18.
//

#include "../includes/push_swap.h"

static void	display_usage()
{
	exit(0);
}


void	print_arr(int *arr, size_t size)
{
	int	i;

	i = 0;
	while (i < size)
		printf("[%d]", arr[i++]);
	printf("\n");
}

void	ft_bubble_sort(int *arr, size_t size)
{
	size_t	x;
	size_t	y;
	int		tmp;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size - 1)
		{
			if (arr[y] > arr[y + 1])
			{
				tmp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = tmp;
			}
			y = y + 1;
		}
		x = x + 1;
	}
}

int		get_pivot(t_stack *st, int size)
{
	int *arr;
	int	i;

	arr = (int *)ft_malloc_s(size, sizeof(int));
	i = 0;
	while (i < size)
	{
		arr[i] = st->val;
		st = st->next;
		i++;
	}
	ft_bubble_sort(arr, size);
	print_arr(arr, size);
	i = arr[(size >> 1)];
	ft_free_s((void **)&arr);
	return (i);
}

void	pusher(t_main *m, int st_num, int size, int pivot)
{
	t_stack	*st;

//	st = (st_num == A ? m->a : m->b);
	print_stacks(m);
	while (size--)
	{
		st = (st_num == A ? m->a : m->b);
		if (st && st->next && st->val > st->next->val && st->val <= pivot)
		{
			ft_putstr("\t---->");
			ft_putstr(st_num == A ? m->cmd_name[SA] : m->cmd_name[SB]);
			st_num == A ? m->op[SA](m) : m->op[SB](m);
			print_stacks(m);
		}
		if (st->val > pivot)
		{
			ft_putstr("\t---->");
			ft_putstr(st_num == A ? m->cmd_name[PB] : m->cmd_name[PA]);
			st_num == A ? m->op[PB](m) : m->op[PA](m);
		}

		else if (st->val <= pivot)
		{
			ft_putstr("\t---->");
			ft_putstr(st_num == A ? m->cmd_name[RA] : m->cmd_name[RB]);
			st_num == A ? m->op[RA](m) : m->op[RB](m);
		}

		print_stacks(m);
//		st = st->next;
	}
	;
}

void	try_qsort(t_main *m, int st_num, int size)
{
	t_stack *st;
	t_stack *tmp;
	int pivot;
	int i;

	if (size < 2)
		return ;

	st = (st_num == A ? m->a : m->b);
	size = (st_num == A ? m->size_a : m->size_b);
	pivot = get_pivot(st, size);
	tmp = st;
	i = 0;
	printf("Pivot == {%d}\n------------\n", pivot);

	pusher(m , st_num, size, pivot);
//	try_qsort(m, A, m->size_a);
//	try_qsort(m, B, m->size_b);
}

int main(int ac, char **av)
{
	t_main	*m;
	t_stack *st;

	m = init_main_struct(PUSH_SWAP);
	if (ac < 2)
		display_usage();
	ac--;
	av++;
	check_arguments(m, ac, av);
	st = m->a;
	printf("Stack_size = %d\n------------------\n", m->size_a);
	try_qsort(m, A, m->size_a);
	while (st)
	{
		printf("Stack value == %d\n", st->val);
		st = st->next;
	}
	check_sorting(m->a);
	return (0);
}