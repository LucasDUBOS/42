/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucdubos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:13:03 by lucdubos          #+#    #+#             */
/*   Updated: 2018/10/24 15:23:55 by lucdubos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct	s_struct
{
	int		**tab;
	int		nbra;
	int		nbrb;
	int		mediane;
	int		nbr_mediane;
	int		mediane_passee;
	int		mediane_actuelle;
	int		min;
	int		med_av;
	int		nbr_coup;
	int		nbr_coup2;
	int		ecriture;
	int		optionv;
	int		sens_rot_a_apres_full_pa;
	int		min_global_a;
	int		last_med;
	int		second_min;
	int		second_max;
	int		flag_depil;
	int		max;
	int		options;
	int		nbb;
	int		j_err;
}				t_struct;

void			ft_rot_a_sens(t_struct *s);
int				**stock_int_ps(char **str, int n);
void			printtab(t_struct *s);
void			sa(t_struct *s);
void			sb(t_struct *s);
void			ss(t_struct *s);
void			ra(t_struct *s);
void			rb(t_struct *s);
void			rr(t_struct *s);
void			rra(t_struct *s);
void			rrb(t_struct *s);
void			rrr(t_struct *s);
void			pa(t_struct *s);
void			pb(t_struct *s);
int				is_tri(int **tab, int *nbra, int *nbrb);
void			ft_petit_nbr(t_struct *s, int argc, char **argv);
int				ft_mediane(int *tab, int nb, t_struct *s);
int				ft_push_b_mediane(t_struct *s);
void			push_b_max(t_struct *s);
void			ft_free(int **tab, int **tab2);
int				gestion_erreur(char **tab, int argc, t_struct *s);
void			last_mediane(t_struct *s);
int				ft_algo(t_struct *s);
void			ft_algo1(t_struct *s, int **tab2);
void			ft_optionv(char **argv, int argc);
void			ft_algo3(t_struct *s, int argc, char **argv);
int				error_optionv(char **argv, int *argc, t_struct *s);
void			ft_rot_rra_sens(t_struct *s);
void			ft_rot_ra_sens(t_struct *s);
void			ft_rot_a_sens(t_struct *s);

/*
**			placement.c
*/

int				ft_nbr_max_min_b(int **tab, int *nbrb, int *min);
int				ft_where_is_min(int **tab, int min);
int				ft_where_is_max(int **tab, int max);
void			ft_second_max_min(t_struct *s, int min, int max);

/*
**			ft_depil_sens.c
*/

int				ft_depil_rrb_max(t_struct *s);
int				ft_depil_rb_max(t_struct *s);
int				ft_depil_rb_min(t_struct *s);
int				ft_depil_rrb_min(t_struct *s);

/*
**			ft_push_b_1.c
*/

void			push_b_1(t_struct *s);

/*
**			ft_petit_nbr6.c
*/

void			ft_petit_nbr6(t_struct *s, char **argv);
void			ft_petit_nbr3(t_struct *s);

#endif
