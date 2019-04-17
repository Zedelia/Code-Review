# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 16:44:21 by qpupier      #+#   ##    ##    #+#        #
#    Updated: 2019/03/12 15:46:58 by qpupier     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf
INCLUDES = includes/fdf.h includes/keys.h
INCLUDES_BIS = ../includes/fdf.h ../includes/keys.h
MINILIBX = -I./minilibx_macos -L ./minilibx_macos -lmlx -framework OpenGL 	\
-framework AppKit
FLAGS = -Wall -Wextra -Werror
FILES = objects/main.o 														\
		objects/parse.o 													\
		objects/lines.o 													\
		objects/display.o 													\
		objects/event.o 													\
		objects/options.o 													\
		objects/hidden_faces.o 												\
		objects/event_mouse.o 												\
		objects/gradient.o 													\
		objects/help.o 														\
		objects/infos.o 													\
		objects/init.o 														\
		objects/display_hidden_faces.o 										\
		objects/event_buttons.o 											\
		objects/event_projections.o 										\
		objects/hidden_faces_calc.o 										\
		objects/hidden_faces_lines_calc.o 									\
		objects/update.o

all: $(NAME)

$(NAME): objects $(INCLUDES) $(FILES)
	make -C libft
	gcc $(FLAGS) $(MINILIBX) libft/libft.a $(FILES) -o $(NAME)
	@rm -rf includes/*.h.gch
	@rm -rf fdf.dSYM
	@rm -rf .vscode

objects/%.o: sources/%.c
	cd objects ; gcc $(FLAGS) -I $(INCLUDES_BIS) -c ../$^

objects:
	mkdir objects

clean:
	make clean -C libft
	rm -rf objects

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all