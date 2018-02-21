.PHONY: all, $(NAME), clean, fclean, re

NAME = jclaudan.filler

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = filler.h

SRC_NAME = filler.c \
		   get_data.c \
			 check_zone.c \
		   battle.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft
	@echo "$(OKC)FILLER:\t\tCompilation.. \tPrêt$(NOC)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo -n =========

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)FILLER:\t\tSuppression du dossier objet :\t./obj/$(NOC)"

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(WAC)FILLER:\t\tSuppression de l'executable  :\tfiller$(NOC)"

re: fclean all
