NAME := philo

HEADER := philosopher.h

OBJ_DIR := objs

SOURCE := main.c

OBJS := $(SOURCE:%.c=$(OBJ_DIR)/%.o)

RM := rm
CC := cc
MAKE_DIR := mkdir

RM_FLAG := -rf
CC_FLAG := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "$(BLUE)Start compiling...$(NC)"
	$(CC) $(CC_FLAG) -o $(NAME) $(OBJS)

clean:
	@$(RM) $(RM_FLAG) $(OBJ_DIR)
	@echo "$(GREEN)Clean objective files successfully!$(NC)"

fclean: clean
	$(RM) $(RM_FLAG) $(NAME)

re: flean all

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@$(CC) $(CC_FLAG) -c $< -o $@
	@echo "$(GREEN)Clean everything successfully!$(NC)"

$(OBJ_DIR):
	$(MAKE_DIR) $(OBJ_DIR)

.PHONY: all clean flean re

GREEN := \033[0;32m
BLUE := \033[0;34m
NC := \033[0m