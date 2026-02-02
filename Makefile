# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dasamuel <dasamuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#              #
#    Updated: 2026/01/15 11:45:48 by dasamuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

GREEN	= \033[0;32m
RED		= \033[0;31m
RESET	= \033[0m
TITLE	= \033[1;32m

NAME		=	miniRT
# -Werror 
CC			=	cc -Wall -Wextra -g3 #-Ofast -march=native -mtune=native -ffast-math -funroll-loops
LINK_FLAG	=	-lm -lXext -lX11

SRC_FILES	=	main.c
HEADER_FILES =	main.h

OBJ_FILES	=	$(SRC_FILES:.c=.o)
SRC_FOLDER	=	src/
OBJ_FOLDER	=	obj/
INC_FOLDER	=	include/

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a
MINILIBX = minilibx-linux
MINILIBX_A = $(MINILIBX)/libmlx.a

SOURCES	= $(addprefix $(SRC_FOLDER),$(SRC_FILES))
OBJECTS	= $(addprefix $(OBJ_FOLDER),$(OBJ_FILES))
HEADERS = $(addprefix $(INC_FOLDER),$(HEADER_FILES))

# RULES

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_A) $(MINILIBX_A)
	$(CC) $(OBJECTS) $(LIBFT_A) $(MINILIBX_A) $(LINK_FLAG) -o $(NAME)
# 	echo "$(GREEN)✔ Successfully compiled$(RESET)"
# 	echo

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.c $(HEADERS)
	mkdir -p $(dir $@)
	$(CC) -I$(INC_FOLDER) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)
$(MINILIBX_A):
	$(MAKE) -C $(MINILIBX)
	
clean:
	rm -rf $(OBJ_FOLDER)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX) clean

fclean: clean
	rm -rf $(NAME) $(NAME)_bonus
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINILIBX) clean

re: fclean all

bonus: $(NAME)_bonus

run: all
	./$(NAME)

$(NAME)_bonus: $(OBJECTS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_A) $(LINK_FLAG) -o $(NAME)_bonus
	@echo "$(GREEN)✔ Successfully compiled$(RESET)"
	@echo
