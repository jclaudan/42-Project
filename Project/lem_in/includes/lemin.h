/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:35:27 by jclaudan          #+#    #+#             */
/*   Updated: 2017/05/25 15:36:20 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"

typedef struct		s_obj
{
	char			*line;
	int				start;
	int				end;
	char			**link;
	char			*prev;
	int				antz;
	char			*save;
	struct s_obj	*nxt;
	struct s_obj	*prv;
}					t_obj;

typedef struct		s_all
{
	t_obj	*path1;
	t_obj	*path2;
	char	*str;
}					t_all;

t_obj				*init_lst(void);
t_obj				*new_lst(char *line, int start, int end);
t_obj				*add_lst(t_obj *room, char *line, int start, int end);
int					get_nb_antz(char **str);
int					check_path(t_obj *path, t_obj *room, t_obj *link);
int					check_room(char *line);
int					check_visit(t_obj *visit, char *room);
char				*check_com(char *line, t_obj **room);
char				*get_com(char **line);
int					check_link(char *line);
int					insert_data(char *line, t_obj **room, t_obj **link,
		char **str);
char				*get_data(t_obj **room, t_obj **link, char **str);
int					check_name(t_obj *room, t_obj *link);
int					check_if_dble(t_obj *room);
int					check_start_end(t_obj *room);
int					count_link(char *room, t_obj *link);
char				*get_link(char *room, char *link);
t_obj				*create_link(t_obj *room, t_obj *link);
t_obj				*go_to_room(t_obj *room, char *name);
t_obj				*go_to_start(t_obj *room);
t_obj				*go_to_end(t_obj *room);
t_obj				*go_last_antz(t_obj *path);
t_obj				*new_link(char *room, char *prev);
t_obj				*add_link(t_obj *link, char *room, char *prev);
t_obj				*init_antz(t_obj *path);
t_obj				*nxt_antz(t_obj *path);
void				display_fil(t_obj *path);
t_obj				*find_path(t_obj *room);
t_obj				*make_path(t_obj *path);
t_obj				*add_link_prv(t_obj *path);
void				make_lemin(t_obj *path, int nb);
void				display_graph(t_obj *room, t_obj *link, int n);
void				displaylst(t_obj *lst);
t_obj				*save_line(t_obj *room);
void				display_antz_moove(t_obj *path);
t_obj				*moove_antz(t_obj *path, int antz, int nb);
void				join_str(char **str, char *line);

#endif
