# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oldurosi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 19:29:45 by oldurosi          #+#    #+#              #
#    Updated: 2020/01/03 20:20:47 by oldurosi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name
NAME = fdf

# Compilation flags
FLAGS = -Wall -Wextra -Werror 

# DIR
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/
MINILIBX_DIR = ./minilibx/

# Source Files & Object Files
SRC_FILES = fdf.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# PATHS
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MINILIBX = $(addprefix $(MINILIBX_DIR), libmlx.a)

# Library Linking
LINK = -L $(LIBFT_DIR) -lft -L $(MINILIBX_DIR) \
	 		-lmlx -framework OpenGL -framework Appkit 

# all rule
all: obj $(LIBFT) $(MINILIBX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(MINILIBX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(MINILIBX):
	@make -C $(MINILIBX_DIR)

# compiling 
$(NAME): $(OBJ)
	@echo "Compiling... Wait a sec."
	@gcc $(OBJ) $(LINK) -lm -o $(NAME)
	@echo "$(NAME) generated!"

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINILIBX_DIR) clean
	@echo "Objects Removed!"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(NAME) Removed!"

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re
