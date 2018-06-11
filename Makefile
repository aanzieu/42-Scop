# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 11:15:53 by aanzieu           #+#    #+#              #
#    Updated: 2018/06/06 14:28:17 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Scop

MAKE = make
MAKE_FLAGS = --no-print-directory

INCLUDE = -I includes -I libft

SRC_DIR = srcs

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SDL_FLAGS = `sdl2-config --cflags --libs`

GLFW3 = /Users/$(USER)/.brew/opt/glfw/lib/libglfw.3.2.dylib
SDL2 = /Users/$(USER)/.brew/opt/sdl2/lib/libSDL2.dylib

GLEW = frameworks/glew/lib/libGLEW.a

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

RM = rm -f
RF = rm -rf

###################################################
##--- LIST of Sources                         ---##
###################################################

SRC =			$(SRC_DIR)/main.c \

###################################################
##--- Use Patsubst to find .o from .c         ---##
###################################################

OBJ		 = $(patsubst srcs/%.c, obj/%.o, $(SRC))
.SILENT:

###################################################
##--- Compilation Running                     ---##
###################################################

all: $(NAME)

$(NAME): $(OBJ)
	printf '\033[K\033[32m[✔] %s\n\033[0m' "--Compiling Sources--------"
	@$(MAKE) $(MAKE_FLAGS) -C $(LIBFT_DIR)
	printf '\033[32m[✔] %s\n\033[0m' "--Compiling Libft Library--------"
	printf '\033[32m[✔] %s\n\033[0m' "--Compiling Interface--------"
	if [ ! -d bin ]; then mkdir -p bin; fi
	# @gcc -o bin/$(NAME) $(OBJ) $(LIBFT) $(GLFW3) -lglfw3 -framework Cocoa -framework IOKit -framework CoreVideo $(GLEW) -lglew -framework OpenGL
	
	@gcc -g -o bin/$(NAME) $(OBJ) $(LIBFT) -framework OpenGL -Xlinker $(GLEW) -Xlinker $(GLFW3)

	printf '\033[1;7m'
	printf '\033[33m[✔] %s\n\033[0m' "--DONE--------"

###################################################
##--- Create repertories for objects .c to .c ---##
###################################################

obj/%.o: srcs/%.c
	if [ ! -d obj ]; then mkdir -p obj; fi
	if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	$(CC) $(CC_FLAGS) -c $(INCLUDE) $< -o $@
	printf '\033[K\033[0m[✔] %s\n\033[0m\033[1A' "$<"

###################################################
##--- Clean only objects .o                      ##
###################################################

clean:
	printf '\033[1;7m'
	printf '\033[31m[✔] %s\n\033[0m' "--Cleaning Library--------"
	@$(MAKE) $(MAKE_FLAGS) fclean -C $(LIBFT_DIR)
	printf '\033[1;7m'
	printf '\033[31m[✔] %s\n\033[0m' "--Cleaning Output Files--------"
	@$(RM) $(OBJ)

###################################################
##--- Clean ALl                                  ##
###################################################

fclean: clean
	printf '\033[1;7m'
	printf '\033[31m[✔] %s\n\033[0m' "--Cleaning Executable and All Object--------"
	@$(RM) $(NAME)
	@$(RF) obj bin screenshots

re: fclean all