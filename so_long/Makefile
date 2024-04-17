NAME := so_long
LIBFT := libft.a


UTILS_DIR := utils
LIB_DIR := libs
LIBFT_DIR := 42-c-library
MLX_DIR := MLX42
OBJ_DIR := objs
OBJS_DIR := objs $(addprefix $(OBJ_DIR)/, $(UTILS_DIR))

HEADER := so_long.h
UTILS_HEADER := $(UTILS_DIR)/utils.h

SOURCE := main.c $(wildcard $(UTILS_DIR)/*.c)

OBJS = $(SOURCE:%.c=$(OBJ_DIR)/%.o)

RM := rm
CC := cc
MAKE := make
MAKE_DIR := mkdir
LINK_HEADERS := -I $(LIB_DIR)/$(MLX_DIR)/include -I $(LIB_DIR)

RM_FLAG := -rf
CC_FLAG := -Wall -Wextra -Werror
LIB_FLAG := -framework Cocoa -framework OpenGL -framework \
			IOKit ./$(LIB_DIR)/$(MLX_DIR)/build/libmlx42.a -Iinclude -lglfw -g

all: init-sub mlx $(NAME)
	@echo "$(GREEN)Build Successfully!$(NC)"

init-sub:
	@echo "$(BLUE)Start fetching git submodules...$(NC)"
	@if [ -z "$(shell ls -A $(LIB_DIR)/$(LIBFT_DIR))" ]; then \
		git submodule init $(LIB_DIR)/$(LIBFT_DIR); \
		git submodule update $(LIB_DIR)/$(LIBFT_DIR); \
	fi
	@if [ -z "$(shell ls -A $(LIB_DIR)/$(MLX_DIR))" ]; then \
		git submodule init $(LIB_DIR)/$(MLX_DIR); \
		git submodule update $(LIB_DIR)/$(MLX_DIR); \
	fi
	@echo "$(GREEN)Done!$(NC)"
	@echo "$(BLUE)Building MLX42...$(NC)"

mlx:
	@cd $(LIB_DIR)/$(MLX_DIR) && cmake -B build && make -C build -j4
	@echo "$(GREEN)Done!$(NC)"
	@echo "$(BLUE)Start compiling...$(NC)"

$(NAME): $(OBJ_DIR) $(OBJS) $(HEADER) $(UTILS_HEADER)
	@$(MAKE) -C $(LIB_DIR)/$(LIBFT_DIR)
	@$(CC) $(CC_FLAG) $(OBJS) $(LIB_DIR)/$(LIBFT_DIR)/$(LIBFT) $(LIB_FLAG) \
	-o $(NAME)

clean:
	@$(RM) $(RM_FLAG) $(OBJ_DIR) $(LIB_DIR)/$(MLX_DIR)/build \
	$(LIB_DIR)/$(LIBFT_DIR)/objs
	@echo "$(GREEN)Clean Bins Successfully!$(NC)"

fclean: clean
	$(RM) $(RM_FLAG) $(NAME) $(LIB_DIR)/$(LIBFT_DIR)/$(LIBFT)
	@echo "$(GREEN)Clean everything Successfully!$(NC)"

re: fclean all

exe: all
	./$(NAME)

$(OBJ_DIR)/%.o: %.c $(UTILS_HEADER)
	$(CC) $(CC_FLAG) -Imlx -c $< -o $@ $(LINK_HEADERS)

$(OBJ_DIR):
	$(MAKE_DIR) $(OBJS_DIR)

.PHONY: all clean fclean re init-sub mlx

GREEN := \033[0;32m
BLUE := \033[0;34m
NC := \033[0m