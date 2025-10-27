# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 14:50:40 by kqueiroz          #+#    #+#              #
#    Updated: 2025/10/15 15:29:47 by kqueiroz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
       ft_push.c \
	   ft_swap.c \
	   ft_rotate.c \
	   ft_reverse_rotate.c \
	   validate.c \
	   sort.c \
	   radix_sort.c

OBJS = $(SRCS:.c=.o)

GREEN = \033[0;32m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(PURPLE)Compiling Libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(PURPLE)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(CYAN)$(NAME) compiled successfully!$(RESET)"

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	@echo "$(GREEN)Cleaning object files...$(RESET)"
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)

fclean: clean
	@echo "$(GREEN)Cleaning all files...$(RESET)"
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re