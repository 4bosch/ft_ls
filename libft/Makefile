# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abosch <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 13:36:55 by abosch            #+#    #+#              #
#    Updated: 2020/02/20 13:01:43 by abosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#~~~~~~~~~~PATH~~~~~~~~~#
SRC_PATH = src

SRC_LST_PATH := $(SRC_PATH)/lst

SRC_TMP_PATH := $(SRC_PATH)/tmp

SRC_STDIO_PATH := $(SRC_PATH)/stdio

OBJ_PATH = obj

INC_PATH = include
#-----------------------#


#~~~~~~~~~NAMES~~~~~~~~~#
SRC_TMP_NAME =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c		\
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c	\
			ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c	\
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c	\
			ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c			\
			ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c	ft_striter.c	\
			ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c				\
			ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c				\
			ft_strsplit.c ft_itoa.c	ft_putchar.c ft_putstr.c ft_putendl.c	\
			ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c		\
			ft_putnbr_fd.c ft_strjoin_free_d.c								\
			get_next_line.c	ft_atoll.c										\
			ft_isblank.c ft_isspace.c ft_abs.c ft_count_digits.c			\
			ft_getnbr_base.c ft_isprint.c ft_llitoa.c ft_llitoa_base.c		\
			ft_llitosa_base.c ft_lluitoa.c ft_lluitoa_base.c			 	\
			ft_lluitosa_base.c ft_make_printable.c ft_puterr.c 				\
			ft_strjoin_free.c ft_utfecut.c ft_utfecut_index.c 				\
			ft_wchar_utfe.c ft_wchar_utfelen.c ft_count_udigits.c			\
			ft_wstr_utfe.c ft_wstr_utfelen.c ft_wstrlen.c					\
			ft_strmatch.c ft_printerr.c

SRC_LST_NAME =  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c			\
				ft_lstiter.c ft_lstmap.c ft_lstgeti.c ft_lstswap.c			\
				ft_lstlen.c	ft_lstquicksort.c ft_lstquicksorttab.c			\
				ft_lstinsert.c

SRC_STDIO_NAME =  args.c ctl_colors.c floats.c ft_printf.c integers.c output.c\
					ctl_sgr.c parsing.c specifier.c type_base.c type_char.c	\
					type_date.c type_floats.c type_int.c type_utils.c		\
					type_utils_2.c type_wchar.c curly.c curly_utils.c		\
					percent.c type_cast_utils.c type_deprecated.c

OBJ_TMP_NAME := $(SRC_TMP_NAME:.c=.o)

OBJ_LST_NAME := $(SRC_LST_NAME:.c=.o)

OBJ_STDIO_NAME := $(SRC_STDIO_NAME:.c=.o)
#----------------------#


#~~~~~~~~~FLAGS~~~~~~~~#
LIB_FLAG := -I$(INC_PATH)

OPTI_FLAG = -O3

CFLAGS = -Werror -Wextra -Wall -g3
#----------------------#

NAME = libft.a

CC = clang

SRC :=	$(addprefix $(SRC_STDIO_PATH)/,$(SRC_STDIO_NAME))	\
		$(addprefix $(SRC_TMP_PATH)/,$(SRC_TMP_NAME))		\
		$(addprefix $(SRC_LST_PATH)/,$(SRC_LST_NAME))

OBJ_TMP := $(addprefix $(OBJ_PATH)/,$(OBJ_TMP_NAME))
OBJ_LST := $(addprefix $(OBJ_PATH)/,$(OBJ_LST_NAME))
OBJ_STDIO := $(addprefix $(OBJ_PATH)/,$(OBJ_STDIO_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ_TMP) $(OBJ_LST) $(OBJ_STDIO)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compilation of libft.a is done"

$(OBJ_PATH)/%.o: $(SRC_TMP_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(LIB_FLAG) $(OPTI_FLAG) -o $@ -c $<
	@echo "Compiling libft.a: $<"

$(OBJ_PATH)/%.o: $(SRC_LST_PATH)/%.c 
	@$(CC) $(CFLAGS) $(LIB_FLAG) -I../include $(OPTI_FLAG) -o $@ -c $<
	@echo "Compiling libft.a: $<"

$(OBJ_PATH)/%.o: $(SRC_STDIO_PATH)/%.c
	@$(CC) $(CFLAGS) $(LIB_FLAG) $(OPTI_FLAG) -o $@ -c $<
	@echo "Compiling libft.a: $<"

clean:
	@rm -f $(OBJ_TMP) $(OBJ_LST) $(OBJ_STDIO)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)

norme:
	norminette $(SRC)
	norminette $(INC_PATH)

re: fclean all
