# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanzieu <aanzieu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/04 09:15:34 by aanzieu           #+#    #+#              #
#    Updated: 2018/05/14 12:55:09 by aanzieu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

RM = rm -f
RF = rm -rf

HEADERS = ./libft.h

SRC_DIR = srcs

SRC = 	$(SRC_DIR)/ft_abs.c \
		$(SRC_DIR)/ft_atoi_double.c \
		$(SRC_DIR)/ft_atoi.c \
		\
		$(SRC_DIR)/ft_bzero.c \
		\
		$(SRC_DIR)/ft_cleanup_str.c \
		$(SRC_DIR)/ft_convert_base.c \
		$(SRC_DIR)/ft_count_dl.c \
		$(SRC_DIR)/ft_count_word.c \
		\
		$(SRC_DIR)/ft_deg_to_radian.c \
		\
		$(SRC_DIR)/ft_isalnum.c \
		$(SRC_DIR)/ft_isalpha.c \
		$(SRC_DIR)/ft_isascii.c \
		$(SRC_DIR)/ft_isdigit.c \
		$(SRC_DIR)/ft_isprint.c \
		$(SRC_DIR)/ft_itoa.c \
		\
		$(SRC_DIR)/ft_lst_add_back.c \
		$(SRC_DIR)/ft_lstadd.c \
		$(SRC_DIR)/ft_lstdel_cont.c \
		$(SRC_DIR)/ft_lstdel.c \
		$(SRC_DIR)/ft_lstdelone.c \
		$(SRC_DIR)/ft_lstiter.c \
		$(SRC_DIR)/ft_lstmap.c \
		$(SRC_DIR)/ft_lstnew.c \
		\
		$(SRC_DIR)/ft_memalloc.c \
		$(SRC_DIR)/ft_memccpy.c \
		$(SRC_DIR)/ft_memchr.c \
		$(SRC_DIR)/ft_memcmp.c \
		$(SRC_DIR)/ft_memcpy.c \
		$(SRC_DIR)/ft_memdel.c \
		$(SRC_DIR)/ft_memmove.c \
		$(SRC_DIR)/ft_memset.c \
		\
		$(SRC_DIR)/ft_pow.c \
		$(SRC_DIR)/ft_putchar.c \
		$(SRC_DIR)/ft_putchar_fd.c \
		$(SRC_DIR)/ft_putendl.c \
		$(SRC_DIR)/ft_putendl_fd.c \
		$(SRC_DIR)/ft_putnbr.c \
		$(SRC_DIR)/ft_putnbr_fd.c \
		$(SRC_DIR)/ft_putstr.c \
		$(SRC_DIR)/ft_putstr_fd.c \
		\
		$(SRC_DIR)/ft_swap_str.c \
		$(SRC_DIR)/ft_swap_double.c \
		$(SRC_DIR)/ft_strcat.c \
		$(SRC_DIR)/ft_strchr.c \
		$(SRC_DIR)/ft_strclr.c \
		$(SRC_DIR)/ft_strcmp.c \
		$(SRC_DIR)/ft_strcpy.c \
		$(SRC_DIR)/ft_strdel.c \
		$(SRC_DIR)/ft_strdup.c \
		$(SRC_DIR)/ft_strequ.c \
		$(SRC_DIR)/ft_striter.c \
		$(SRC_DIR)/ft_striteri.c \
		$(SRC_DIR)/ft_strjoin.c \
		$(SRC_DIR)/ft_strlcat.c \
		$(SRC_DIR)/ft_strlen.c \
		$(SRC_DIR)/ft_strmap.c \
		$(SRC_DIR)/ft_strmapi.c \
		$(SRC_DIR)/ft_strncat.c \
		$(SRC_DIR)/ft_strncmp.c \
		$(SRC_DIR)/ft_strncpy.c \
		$(SRC_DIR)/ft_strwcpy.c \
		$(SRC_DIR)/ft_strnequ.c \
		$(SRC_DIR)/ft_strnew.c \
		$(SRC_DIR)/ft_strnstr.c \
		$(SRC_DIR)/ft_strrchr.c \
		$(SRC_DIR)/ft_strsplit.c \
		$(SRC_DIR)/ft_strstr.c \
		$(SRC_DIR)/ft_strsub.c \
		$(SRC_DIR)/ft_strtrim.c \
		$(SRC_DIR)/ft_strtolower.c \
		$(SRC_DIR)/ft_sq.c \
		\
		$(SRC_DIR)/ft_tolower.c \
		$(SRC_DIR)/ft_toupper.c \
		\
		$(SRC_DIR)/get_next_line.c \

###########################################
##--- Use Patsubst to find .o from .c ---##
###########################################

OBJ		 = $(patsubst srcs/%.c, obj/%.o, $(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	printf '\033[32m[✔] %s\n\033[0m' "--Compiling Libft Library--------"

###################################################
##--- Create repertories for objects .c to .c ---##
###################################################

obj/%.o: srcs/%.c
	if [ ! -d obj ]; then mkdir -p obj; fi
	if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	$(CC) $(CC_FLAGS) -I. -c $< -o $@
	printf '\033[K\033[0m[✔] %s\n\033[0m\033[1A' "$<"

#################################
##--- Clean only objects .o ---##
#################################

clean:
	printf '\033[1;7m'
	printf '\033[31m[✔] %s\n\033[0m' "--Cleaning Library--------"
	@$(RM) $(OBJ) 

#####################
##--- Clean ALl ---##
#####################

fclean: clean
	printf '\033[1;7m'
	printf '\033[31m[✔] %s\n\033[0m' "--Cleaning Libft and All Object--------"
	@$(RM) $(NAME)
	@$(RF) obj

re: fclean all
.PHONY: clean fclean re all