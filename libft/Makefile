# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiwu <wiwu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/30 15:04:13 by wiwu              #+#    #+#              #
#    Updated: 2025/12/04 13:51:48 by wiwu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME = libft.a

SOURCES = ft_atoi.c \
          ft_bzero.c \
          ft_calloc.c \
          ft_isalnum.c \
          ft_isalpha.c \
          ft_isascii.c \
          ft_isdigit.c \
          ft_isprint.c \
          ft_itoa.c \
          ft_memchr.c \
          ft_memcmp.c \
          ft_memcpy.c \
          ft_memmove.c \
          ft_memset.c \
          ft_putchar_fd.c \
          ft_putendl_fd.c \
          ft_putnbr_fd.c \
          ft_putstr_fd.c \
          ft_split.c \
          ft_strchr.c \
          ft_strncmp.c \
          ft_strdup.c \
          ft_striteri.c \
          ft_strjoin.c \
          ft_strlcat.c \
          ft_strlcpy.c \
          ft_strlen.c \
          ft_strmapi.c \
          ft_strnstr.c \
          ft_strrchr.c \
          ft_strtrim.c \
          ft_substr.c \
          ft_tolower.c \
          ft_toupper.c \
          ft_printf.c \
          ft_printf_utils.c \

BONUS_SRCS = ft_lstadd_front_bonus.c \
            ft_lstnew_bonus.c \
			ft_lstsize_bonus.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) 
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c libft.h ft_printf.h
	$(CC) -c $(CFLAGS) $< -o $@

bonus: $(OBJECTS) $(BONUS_OBJS)
	ar rcs ${NAME} $^

clean:
	rm -f $(OBJECTS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all