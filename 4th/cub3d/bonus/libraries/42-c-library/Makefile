# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 19:58:38 by ytoshihi          #+#    #+#              #
#    Updated: 2024/04/21 00:36:14 by ytoshihi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

OBJ_DIR := objs
LIBFT_DIR := $(addprefix $(OBJ_DIR)/, libft)
PRINTF_DIR := $(addprefix $(OBJ_DIR)/, printf)
GNL_DIR := $(addprefix $(OBJ_DIR)/, get_next_line)
OBJS_DIR := $(OBJ_DIR) $(LIBFT_DIR) $(PRINTF_DIR) $(GNL_DIR)

LIBFT_SOURCE := $(addprefix libft/, ft_isalnum.c ft_isprint.c ft_memmove.c \
		  		ft_strlcat.c ft_strnstr.c ft_atoi.c ft_isalpha.c ft_memchr.c \
		  		ft_memset.c  ft_strlcpy.c ft_strrchr.c ft_bzero.c ft_isascii.c \
		  		ft_memcmp.c  ft_strchr.c ft_strlen.c  ft_tolower.c ft_calloc.c \
		  		ft_isdigit.c ft_memcpy.c ft_strdup.c  ft_strncmp.c \
				ft_toupper.c ft_substr.c  ft_strjoin.c ft_strtrim.c ft_split.c \
				ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c)

PRINTF_SOURCE := $(addprefix printf/, put_some.c put_with_condition.c \
				 ft_printf.c)
				
GNL_SOURCE := $(addprefix get_next_line/, get_next_line.c get_next_line_utils.c)

SOURCE := $(LIBFT_SOURCE) $(PRINTF_SOURCE) $(GNL_SOURCE)

OBJS := $(SOURCE:%.c=$(OBJ_DIR)/%.o)

RM := rm
CC := cc
AR := ar
MAKE_DIR := mkdir

RM_FLAG := -rf
CC_FLAG := -Wall -Wextra -Werror
AR_FLAG := -rcs

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(AR) $(AR_FLAG) $(NAME) $(OBJS)

clean:
	$(RM) $(RM_FLAG) $(OBJ_DIR)

fclean: clean
	$(RM) $(RM_FLAG) $(NAME)

re: fclean all

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CC_FLAG) -c $< -o $@

$(OBJ_DIR):
	$(MAKE_DIR) $(OBJS_DIR)

.PHONY: all clean fclean re