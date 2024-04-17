# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytoshihi <ytoshihi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 19:58:38 by ytoshihi          #+#    #+#              #
#    Updated: 2024/04/14 20:53:52 by ytoshihi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

LIBFT_DIR := libft
PRINTF_DIR := printf
GNL_DIR := get_next_line
OBJ_DIR := objs
OBJS_DIR := $(OBJ_DIR) \
			$(addprefix $(OBJ_DIR)/, $(LIBFT_DIR) $(PRINTF_DIR) $(GNL_DIR))

SOURCE := $(wildcard **/*.c)

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