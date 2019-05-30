# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaktion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 18:01:29 by olaktion          #+#    #+#              #
#    Updated: 2018/01/04 15:09:53 by olaktion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = -I inc
SRC_DIR = src
NAME =	libft.a
SRC =	ft_strequ.c \
		ft_strnequ.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strtrim.c \
		ft_strsub.c \
		ft_strncpy.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strjoin.c \
		ft_strsplit.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strlen.c \
		ft_strnlen.c \
		ft_strlcat.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_isupper.c \
		ft_toupper.c \
		ft_strupcase.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_itoa.c \
		ft_abs.c \
		ft_swap.c \
		ft_fact.c \
		ft_cntchr.c \
		ft_sq.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_stpcpy.c \
		char_print.c \
		char_util.c \
		float_print.c \
		float_util.c \
		int_handlers_deprec.c \
		int_handlers.c \
		int_print.c \
		int_util.c \
		ft_printf.c \
		ft_printf_pars.c \
		

OBJ =	$(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	
%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "Libft: Removing object files: \033[1;36mOK\033[m"

fclean: clean
	@rm -f $(NAME)
	@echo "Removing Libft: \033[1;36mOK\033[m"

re: fclean all

