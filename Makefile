# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaktion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 12:34:39 by olaktion          #+#    #+#              #
#    Updated: 2018/10/31 12:34:41 by olaktion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = -I libft/inc
LIBFT = libft/libft.a
SRC = \
	ft_ls.c \
	ft_loading.c \
	ft_pars.c \
	ft_print.c \
	ft_sort.c \
	ft_args.c \
	ft_stat.c \
	ft_util.c \
	ft_valid.c \
	ft_wrap.c 
	
OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $@
	@echo "Compilation of LS: \033[1;32mOK\033[m"

$(LIBFT):
	@make -C libft
	@echo "Compilation of Libft: \033[1;36mOK\033[m"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "LS: Removing object files: \033[1;32mOK\033[m"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean
	@echo "Removing LS: \033[1;32mOK\033[m"

re: fclean all
