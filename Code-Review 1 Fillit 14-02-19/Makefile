# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/30 19:08:53 by groubaud     #+#   ##    ##    #+#        #
#    Updated: 2018/07/30 06:00:48 by groubaud    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all re clean fclean lib

NAME = fillit

SRC_DIR = ./source/
OBJ_DIR = $(SRC_DIR)object/
INC_DIR = $(SRC_DIR)
LIB_DIR = ./libft/

SRC_NAME = ft_algo.c ft_check_error.c ft_clean_map.c ft_convert_tetri.c\
		   ft_do_tetri.c ft_free.c ft_manage_pos.c ft_map.c\
		   ft_read.c ft_size.c ft_swap.c main.c ft_error.c
INC_NAME = $(NAME).h
LIB_NAME = libft.a

OBJ_NAME = $(SRC_NAME:.c=.o)
INC = $(addprefix $(INC_DIR), $(INC_NAME))
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
LIB = $(addprefix $(LIB_DIR), $(LIB_NAME))

FLAG = -Wall -Werror -Wextra

all	: $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ) $(LIB)
	gcc $(FLAG) $(OBJ) $(LIB) -o $(NAME)

$(LIB) :
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	gcc $(FLAG) -I $(INC) -o $@ -c $<

lib :
	$(MAKE) -C $(LIB_DIR)

clean : lib_clean
	rm -rf $(OBJ_DIR)

lib_clean :
	$(MAKE) -C $(LIB_DIR) clean

fclean : lib_fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)

lib_fclean :
	$(MAKE) -C $(LIB_DIR) fclean

re : fclean lib all
