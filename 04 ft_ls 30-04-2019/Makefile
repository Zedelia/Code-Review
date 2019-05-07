# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: simrossi <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/25 09:21:00 by simrossi     #+#   ##    ##    #+#        #
#    Updated: 2019/04/30 16:36:06 by simrossi    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

ifeq ($(MUTE), yes)
	SILENT = -s
endif

NAME = ft_ls
CC = gcc

MANDIR = $(HOME)/.man/man/
EXECDIR = $(HOME)/.bin


LIBRAIRIES_DIRECTORY = librairies/
LIBFT_FOLDER = Libft
ABSOLUT_LIBFT_FOLDER = $(addprefix $(LIBRAIRIES_DIRECTORY), $(LIBFT_FOLDER))
LIBRAIRIES := $(ABSOLUT_LIBFT_FOLDER)
LIBRAIRIES_INCLUDES = $(ABSOLUT_LIBFT_FOLDER)

libdir = $(filter $(join $(LIBRAIRIES_DIRECTORY), $(1)), $(LIBRAIRIES))

INCLUDES = includes/ $(LIBRAIRIES_INCLUDES)

CFLAGS = -g -Wall -Wextra -Werror $(addprefix -I, $(INCLUDES))

SRCS_DIR = sources/

SRCS = ls_parsing.c \
	   tfile_utils.c \
	   folder_reading.c \
	   sort_algorithm.c \
	   sort_functions.c \
	   maximum_setup.c \
	   argv_separator.c \
	   pattern_format.c \
	   select_opt.c \
	   t_file_head_utils.c \
	   display_process.c \
	   modify_filename.c \
	   reverse_files.c \
	   date_format.c \
	   printing_functions.c \
	   file_information_getter.c \
	   filename_manipulation.c \
	   printing_functions_long.c \
	   main.c

OBJS = $(addprefix $(SRCS_DIR),$(SRCS:.c=.o))
DEPENDENCIES = $(OBJS:.o=.d)

LIBS_ARCHIVE_FILES = $(shell find $(CURDIR) -name "*.a")

all: get_lib $(NAME)

ifeq ($(shell ls $(MANDIR)),)
all: install_man set_executable
endif

$(NAME): $(OBJS) $(LIBS_ARCHIVE_FILES)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS_ARCHIVE_FILES) -o $(NAME)

get_lib:
	#Compile libft.a
	$(info $(LIBRAIRIES) SEARCH : )
	make  $(SILENT) -C $(filter %$(LIBFT_FOLDER), $(LIBRAIRIES))

clean:
	$(foreach Lib, $(LIBRAIRIES), make -C $(Lib) $@ &&) true
	rm -f $(OBJS)

fclean: clean
	$(foreach Lib, $(LIBRAIRIES), make -C $(Lib) $@ &&) true
	rm -f $(NAME)

proper:fclean
	$(foreach Lib, $(LIBRAIRIES), make -C $(Lib) $@ &&) true
	rm -f $(DEPENDENCIES)
	rm -rf $$(dirname $(MANDIR))
	rm -rf $(EXECDIR)

re: fclean all

install_man:
	if [ ! -e "$(MANDIR)" ] ; then \
		mkdir -p "$(MANDIR)"; \
		for i in {0..9}; do mkdir $(MANDIR)man$$i; done; \
		cp ft_ls.1 $(MANDIR)man1; \
		printf "\nMANPATH+=:$(MANDIR)\nexport MANPATH\n" >> $(HOME)/.$$(basename $$SHELL)rc ; \
		fi

set_executable:
	mkdir $(EXECDIR) && cp ft_ls $(EXECDIR) && \
		printf "PATH+=:$(EXECDIR)\n" >> $(HOME)/.$$(basename $$SHELL)rc

%.d:%.c
		$(CC) -MM $(addprefix -I , $(INCLUDES)) $(filter %.c, $^) > $@
		PREREQUISITES=$$(cat $@ | cut -d : -f 2) && \
			echo "$(@:%.d=%.o) $@:$$PREREQUISITES" > $@

ifeq ($(filter $(MAKECMDGOALS), clean fclean proper),)
include $(DEPENDENCIES)
endif

.PHONY: all clean fclean re get_lib
#.SILENT: $(OBJS)
.DEFAULT_GOAL = all
