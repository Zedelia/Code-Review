# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: groubaud <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/23 16:01:11 by groubaud     #+#   ##    ##    #+#        #
#    Updated: 2018/07/30 06:03:48 by groubaud    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: clean fclean all re

NAME = libft.a

SRC_DIR = ./
OBJ_DIR = ./object/
INC_DIR = ./

PART1 = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c\
	   ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
	   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c\
	   ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c\
	   ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
	   ft_tolower.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
	   ft_memmove.c ft_memset.c ft_memchr.c ft_memcmp.c\
	   ft_strndup.c

PART2 = ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
		ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c\
		ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c\
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\

BONUS1 = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c\
		 ft_lstiter.c ft_lstmap.c

BONUS2 = ft_itoa_base.c ft_spec_rev.c ft_nbrlen.c ft_swap.c\
		 ft_strlowcase.c ft_strupcase.c ft_strcasecmp.c\
		 ft_iscntrl.c ft_is_tnsp.c ft_islower.c ft_isspace.c\
		 ft_isupper.c ft_isgraph.c ft_str_is_alpha.c\
		 ft_isblank.c ft_str_is_lowercase.c ft_str_is_numeric.c\
		 ft_str_is_printable.c ft_str_is_uppercase.c ft_strncasecmp.c\
		 ft_sqrt.c ft_isprime.c ft_pow.c ft_puttab.c ft_tablen.c\
		 ft_abs.c ft_puterror.c ft_sleep.c ft_freetab.c\
		 ft_memalloc_int.c

SRC_NAME = $(PART1) $(PART2) $(BONUS1) $(BONUS2)
INC_NAME = libft.h

OBJ_NAME = $(SRC_NAME:.c=.o)
INC = $(addprefix $(INC_DIR), $(INC_NAME))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	gcc $(FLAGS) -I $(INC) -o $@ -c $<

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all
