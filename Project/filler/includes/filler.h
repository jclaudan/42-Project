/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:08:51 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/17 21:08:17 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_obj
{
	char		player;
	char		advers;
	t_pos		m;
	t_pos		p;
	t_pos		best;
	int			np;
	char		**pform;
	char		**mform;
	t_pos		pos;
	int			len_form_x;
	int			len_form_y;
}				t_obj;

int				get_data(char *player, t_obj *e);
void			recup_arena(char *line, t_obj *e);
void			recup_piece(char *line, t_obj *e);
char			init_player(char *line, t_obj *e);
int				len_tetri_y(char **tetri, t_obj *e);
void			len_tetri_x(char **tetri, t_obj *e);
int				abs(int num);
int				is_inmap(t_pos m, t_pos pp, t_pos c);
int				iswall(t_obj *e, t_pos p, t_pos c);
void			set_point(t_pos *o, int y, int x);
int				can_place(t_obj *e, t_pos c);
int				nearer(t_obj *e, t_pos c);
void			print_best(t_pos best, t_obj *e);
int				check_distance(t_obj *e, t_pos j, t_pos c);
void			play(t_obj *e);
#endif
