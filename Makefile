# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otait-ta <otait-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 09:59:05 by otait-ta          #+#    #+#              #
#    Updated: 2023/10/03 15:53:34 by otait-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Variables
NAME = cub3D
CC = cc
FLAGS = -Wall -Werror -Wextra  -g
MLX = ../MLX42/build/libmlx42.a  -Iinclude -lglfw -L"/Users/$(USER)/goinfre/homebrew/opt/glfw/lib"

RM = rm -rf
LIBTFT = lib/libft/libft.a
PRINTF = lib/ft_printf/libftprintf.a
OBJ_DIR = obj
BNS_OBJ_DIR = obj_bonus
SRC := angle_helpers.c cast_horizantally.c cast_vertically.c drawing.c ft_check.c init.c mini_map.c movment.c free_ressource.c \
 ray_cast.c textures.c get_next_line.c get_next_line_utils.c hooks.c main.c check_map.c check_texture.c dimensions.c map_utils.c read_map.c texture_utils.c utils.c
BONUS_SRC := angle_helpers.c cast_horizantally.c cast_vertically.c drawing.c ft_check.c init.c mini_map.c movment_bonus.c ray_cast.c textures.c get_next_line.c get_next_line_utils.c\
 hooks_bonus.c main.c check_map.c check_texture.c dimensions.c map_utils.c read_map.c texture_utils.c utils.c free_ressource.c

OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ := $(addprefix $(BNS_OBJ_DIR)/, $(BONUS_SRC:.c=.o))
LEAKS =  -g
HEADER = src/cub3d.h
BONUS_HEADER = bonus/cub3d_bonus.h
# Targets
all: $(NAME)

$(NAME): $(OBJ) obj_libft obj_printf $(HEADER)
	$(MAKE) -C lib/MLX42/build
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
	make -C lib/MLX42/build clean
	$(RM) $(OBJ_DIR)
	$(RM) $(BNS_OBJ_DIR)

fclean: clean
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/ft_printf fclean
	$(RM) $(NAME) 
re: fclean all

$(BNS_OBJ_DIR)/%.o: bonus/%.c $(BONUS_HEADER)
	@mkdir -p $(@D)
	$(CC) $(FLAGS)   -c $< -o $@

$(BNS_OBJ_DIR)/%.o: bonus/*/%.c $(BONUS_HEADER)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

$(BNS_OBJ_DIR)/%.o: bonus/*/*/%.c $(BONUS_HEADER)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

bonus: fclean $(BONUS_HEADER) $(BONUS_OBJ) obj_libft obj_printf
	@$(CC)  $(FLAGS) $(MLX) $(BONUS_OBJ) $(LIBTFT) $(PRINTF)  -o $(NAME)
	
	

.PHONY: all clean fclean re obj_libft