# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/06 11:15:53 by aanzieu           #+#    #+#              #
#    Updated: 2018/12/10 16:52:30 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop

MAKE = make
MAKE_FLAGS = --no-print-directory

SRC_DIR = srcs

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
#endif

GLFW3 = /Users/$(USER)/.brew/opt/glfw/lib/libglfw.3.2.dylib
GLEW = /Users/$(USER)/.brew/opt/glew/lib/libGLEW.2.1.dylib

OPENGL = -framework OpenGL

INCLUDE = -I frameworks/glew/include/GL -I frameworks/glfw/include/GLFW -I includes/ -I libft

CC = gcc -g
CC_FLAGS = -Wall -Werror -Wextra

#OS= $(shell lsb_release -si)

RM = rm -f
RF = rm -rf

###################################################
##--- LIST of Sources                         ---##
###################################################

SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/utils_command.c \
		\
		$(SRC_DIR)/glfw/glfw_grid.c \
		$(SRC_DIR)/glfw/glfw_init.c \
		$(SRC_DIR)/glfw/glfw_input.c \
		$(SRC_DIR)/glfw/glfw_keys.c \
		$(SRC_DIR)/glfw/glfw_loadshaders.c \
		$(SRC_DIR)/glfw/glfw_render.c \
		\
		$(SRC_DIR)/mtrx/mtrx_init.c \
		$(SRC_DIR)/mtrx/mtrx_rot.c \
		$(SRC_DIR)/mtrx/mtrx_op.c \
		$(SRC_DIR)/mtrx/mtrx_utils.c \
		$(SRC_DIR)/mtrx/mtrx_new.c \
		\
		$(SRC_DIR)/vect/vect_op.c \
		\
		$(SRC_DIR)/parser/add_element.c \
		$(SRC_DIR)/parser/add_poly.c \
		$(SRC_DIR)/parser/create_obj.c \
		$(SRC_DIR)/parser/del_obj.c \
		$(SRC_DIR)/parser/get_element.c \
		$(SRC_DIR)/parser/process_obj.c \
		$(SRC_DIR)/parser/read_indices.c \
		$(SRC_DIR)/parser/read_obj.c \
		$(SRC_DIR)/parser/set_element.c \
		$(SRC_DIR)/parser/set_texture.c \

###################################################
##--- Use Patsubst to find .o from .c         ---##
###################################################

OBJ		 = $(patsubst srcs/%.c, obj/%.o, $(SRC))
.SILENT:

###################################################
##--- Compilation Running                     ---##
###################################################

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_CUDA)
	printf '\033[K\033[32m[✔] %s\n\033[0m' "--Compiling Sources--------"
	@$(MAKE) $(MAKE_FLAGS) -C $(LIBFT_DIR)
	printf '\033[32m[✔] %s\n\033[0m' "--Compiling Libft Library--------"
	if [ ! -d bin ]; then mkdir -p bin; fi
	$(CC) $(CC_FLAGS) -o bin/$(NAME) $(OBJ) $(LIBFT) $(GLEW) $(GLFW3) $(OPENGL)
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
	@$(RF) obj bin

re: fclean all