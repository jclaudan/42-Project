/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:31:48 by jclaudan          #+#    #+#             */
/*   Updated: 2017/03/13 23:35:18 by jclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

# define BUFF_SIZE 32

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_utils
{
	char			*buff;
	char			*tp;
	int				rd;
	int				ln;
}					t_utils;

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putnbr(int n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *news);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_sqrt(int nb);
void				ft_swap(int *a, int *b);
size_t				ft_strlen_p(const char *s);
char				*ft_strsub_f(char *s, unsigned int start, size_t len);
char				*ft_strjoin_p(char const *s1, char const *s2);
char				*ft_strjoin_f(char *s1, char *s2, int flag);
void				ft_disp_tab_char(char **tab_char);
void				ft_display_lst(t_list *dis_lst);
size_t				ft_count_list(t_list *lst);
void				ft_free_tout(void **afree);
char				*ft_litoa(long long n);
char				*ft_ulitoa(unsigned long long n);
char				*ft_hitoa(unsigned long n, char flag_min_or_maj);
char				*ft_uitoa(unsigned int nb);
char				*ft_oitoa(unsigned int nb);
char				*ft_olitoa(unsigned long long int nb);
int					get_next_line(const int fd, char **line);

typedef struct		s_param
{
	char			*str1;
	int				count_prct;
	int				wildcard_p;
	int				wildcard_f;
	int				len_wild;
	int				wildchamp;
	int				wildprecis;
	int				big_s;
	int				flag;
	char			*frm;
	int				i;
	int				size;
	int				two_z;
	char			*str;
	char			*str2;
	char			*form;
	void			*arg;
	char			*str_p;
	char			conv;
	int				champ;
	int				precis;
	int				hasht;
	int				zero;
	int				less;
	int				plus;
	int				space;
	int				j;
	int				z;
	int				hh;
	int				ll;
	int				h;
	int				l;
}					t_param;

int					ft_printf(const char *format, ...);
int					is_conv(char c);
int					is_flags(char c);
int					is_modif(char c);
char				*stock_param(char *s);
int					is_zero(char *s, char c);
t_param				*init_t_param(t_param *p);
t_param				*set_flags(t_param *p);
t_param				*set_modif(t_param *p);
t_param				*set_champ(t_param *p);
t_param				*set_precis(t_param *p);
t_param				*set_conv(t_param *p);
t_param				*recup_format(const char *format, t_param *p, void *arg);
t_param				*init_a_null(t_param *p, const char *format);
char				*set_char(int c, size_t n);
int					is_conv_in(char *form, t_param *p);
char				*tool_add_flag(t_param *p, char *s, char *tp, size_t len);
char				*tool_add_flag_1(t_param *p, char *s, char *tp, size_t len);
char				*tool_add_flag_2(t_param *p, char *tp, size_t len, char *s);
char				*tool_add_flag_3(t_param *p, char *tp, size_t len, char *s);
char				*tool_add_flag_4(t_param *p, char *tp, size_t len, char *s);
char				*add_flags(t_param *p, char *s);
char				*add_flags_1(t_param *p, char *s, char *tp, size_t len);
char				*add_flags_2(t_param *p, char *s, char *tp, size_t len);
char				*add_flags_3(t_param *p, char *s, char *tp);
char				*add_flags_4(t_param *p, char *s, char *tp, size_t len);
char				*kit_add_flag(t_param *p, char *s, char *tp, char *str);
char				*kit_add_flag_1(t_param *p, char *s, char *tp);
char				*kit_add_flag_2(t_param *p, char *tp, size_t len, char *s);
char				*kit_add_flag_3(char *tp, size_t len, char *s, t_param *p);
char				*kit_add_flag_4(char *tp, size_t len, char *s);

int					oxu1(t_param *p);
int					oxu2(t_param *p);
int					oxu3(t_param *p);
int					oxu4(t_param *p);
int					if_is_d(t_param *p);
void				if_is_d_kit(t_param *p, char *s);
char				*if_is_d_kit2(t_param *p, char *s, long long int long_int);
int					if_is_x(t_param *p);
char				*tool_if_is_x(t_param *p, char *s);
void				tool_if_is_x2(t_param *p, char *s, long long int un_int,
		int flag);
int					if_is_u(t_param *p);
t_param				*tool_if_is_u(t_param *p, char *s);
int					if_is_o(t_param *p);
t_param				*tool_if_is_o(t_param *p, char *s);
int					if_is_p(t_param *p);
int					if_is_c(t_param *p);
void				if_is_c_kit_1(t_param *p, wchar_t c);
char				*if_is_c_kit_2(t_param *p, char *s, int flag);
void				if_is_c_kit_3(t_param *p, char c, char *s);
int					if_is_s(t_param *p);
void				if_is_s_kit(t_param *p, char *s);
int					if_is_other(t_param *p);
int					not_in_list(char c);
int					if_pourcent(char *format);
t_param				*if_pourcent_champ(t_param *p);
t_param				*add_pourcent(t_param *p, char *form, int len);
void				print_one_char(t_param *p, char frm_char, int opt);
int					is_wildcard(char c);
int					if_wildcard_kit(const char *form, t_param *p, void *arg);
int					if_wildcard(const char *form, t_param *p, void *arg);
int					if_wildcard_p(t_param *p, void *arg);
void				ft_print(const char *format, va_list *ap, t_param *p);
int					not_in_list(char c);
void				init_a_null_kit(t_param *p);
char				*set_char(int c, size_t n);
char				*mini_kit_add_flag(t_param *p, char *s);
char				*mini_kit_add_flag_1(char *s, char *tp);
char				*mini_kit_add_flag_2(t_param *p, char *tp, size_t len);
char				*mini_kit_add_flag_3(char *tp, t_param *p, char *s);
int					mini_condition_2(t_param *p);
int					mini_condition_1(t_param *p, char *s);
char				*micro_kit_add_flag(t_param *p, char *tp, size_t len);
char				*micro_kit_add_flag_2(t_param *p, char *s, char *tp);
char				*micro_kit_add_flag_3(t_param *p, char *s, char *tp,
		size_t len);
char				*mini_tool_add_flag_2(t_param *p, char *tp, size_t len,
		char *s);
void				conv_to_unicode_kit(wchar_t arg, t_param *p);
t_param				*conv_to_unicode(wchar_t arg, t_param *p);
t_param				*conv_str_unicode_kit(t_param *p, int flag);
t_param				*conv_str_unicode(wchar_t *arg, t_param *p);

#endif
