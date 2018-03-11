//
// Created by Dmitry Melehov on 3/1/18.
//

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/includes/libft.h"

//enum {ONE,TWO,THREE,SRAV};

enum {CHECKER, PUSH_SWAP};
enum {A, B};
enum {SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR};

typedef struct		s_stack
{
	int 			val;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_main
{
	t_stack			*a;
	t_stack			*b;
	int 			size_a;
	int 			size_b;
	char 			*cmd_name[12];
	void			(*op[12])(struct s_main *m);
	int 			prog;

}					t_main;

/*
** validation.c
*/

void	check_arguments(t_main *m, int ac, char **av);
void	check_sorting(t_stack *st);

/*
** initializations.c
*/

t_main	*init_main_struct(int prog);

/*
** operations.c
*/

void	op_sb(t_main *m);
void	op_sa(t_main *m);
void	op_ss(t_main *m);
void	op_ra(t_main *m);
void	op_rb(t_main *m);
void	op_rr(t_main *m);
void	op_rra(t_main *m);
void	op_rrb(t_main *m);
void	op_rrr(t_main *m);
void	op_pa(t_main *m);
void	op_pb(t_main *m);

void	print_stacks(t_main *m);




#endif //PUSH_SWAP_PUSH_SWAP_H
