# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jclaudan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:49:17 by jclaudan          #+#    #+#              #
#    Updated: 2017/03/26 14:48:11 by jclaudan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC      =  ft_bzero.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c  \
			ft_strcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strlcat.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strstr.c \
			ft_strcmp.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strlen.c \
			ft_putstr.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_atoi.c \
			ft_strdup.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_sqrt.c \
			ft_swap.c \
			ft_strlen_p.c \
			ft_strsub_f.c \
			ft_strjoin_p.c \
			ft_strjoin_f.c \
			ft_disp_tab_char.c \
			ft_display_lst.c \
			ft_free_tout.c \
			ft_get_next_line.c \
			ft_printf.c \
			ft_conv_tools.c \
			ft_litoa.c \
			ft_hitoa.c \
			ft_uitoa.c \
			ft_ulitoa.c \
			ft_olitoa.c \
			ft_oitoa.c \
			add_flag.c \
			kit_add_flag.c \
			micro_kit_add_flag.c \
			mini_kit_add_flag.c \
			tool_add_flag.c \
			tool_condition.c \
			tool_is_c_and_other.c \
			tool_is_d.c \
			tool_is_s_or_p_or_o.c \
			tool_is_x_or_u.c \
			tool_unicode.c \
			utils_printf.c \
			utils2_printf.c \
			tool_is_wildcard.c \
			tool_is_pourcent.c

OBJ     = $(SRC:.c=.o)

NAME    =  libft.a

CFLAGS= -Wall -Werror -Wextra

all:    $(NAME)

$(NAME):    $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:         fclean all

.PHONY:     all clean fclean re
