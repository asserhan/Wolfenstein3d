# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 09:59:05 by otait-ta          #+#    #+#              #
#    Updated: 2023/09/17 13:52:02 by otait-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Variables
NAME = cub3d
CC = cc
FLAGS = -Wall -Werror -Wextra 
MLX = -lmlx -framework OpenGl -framework Appkit
RM = rm -rf
LIBTFT = lib/libft/libft.a
PRINTF = lib/ft_printf/libftprintf.a
OBJ_DIR = obj
SRC := $(notdir $(shell find src -name '*.c'))
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LEAKS =  -g
HEADER = src/cub3d.h
# Targets
all: $(NAME)

$(NAME): $(OBJ) obj_libft obj_printf $(HEADER)
	@$(CC)  $(FLAGS) $(MLX) $(OBJ) $(LIBTFT) $(PRINTF)  -o $@

$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(FLAGS)   -c $< -o $@

$(OBJ_DIR)/%.o: src/*/%.c $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: src/*/*/%.c $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

obj_libft:
	$(MAKE) -C lib/libft
	@make bonus -C lib/libft

obj_printf:
	$(MAKE) -C lib/ft_printf

clean:
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/ft_printf clean
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/ft_printf fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re obj_libft