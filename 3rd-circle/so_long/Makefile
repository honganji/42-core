NAME := so_long

UTILS_DIR := utils
LIB_DIR := libs
OBJ_DIR := objs
LIBFT_DIR := $(LIB_DIR)/42-c-library
MLX_DIR := $(LIB_DIR)/MLX42
OBJS_DIR := objs $(addprefix $(OBJ_DIR)/, $(UTILS_DIR))

HEADER := so_long.h
UTILS_HEADER := $(UTILS_DIR)/utils.h

SOURCE := main.c $(UTILS_DIR)/close_setup.c $(UTILS_DIR)/create_map.c \
		  $(UTILS_DIR)/error.c $(UTILS_DIR)/key_setup.c \
		  $(UTILS_DIR)/loop_setup.c $(UTILS_DIR)/move.c $(UTILS_DIR)/utils.c \
		  $(UTILS_DIR)/verify_map.c

OBJS := $(SOURCE:%.c=$(OBJ_DIR)/%.o)

MODULES := $(LIBFT_DIR)/library.h $(MLX_DIR)/CMakeLists.txt

LIBFT := $(LIBFT_DIR)/libft.a
MLX := $(MLX_DIR)/build/libmlx42.a

RM := rm
CC := cc
MAKE := make
MAKE_DIR := mkdir

LINK_HEADERS := -I $(MLX_DIR)/include -I $(LIB_DIR)

RM_FLAG := -rf
CC_FLAG := -Wall -Wextra -Werror
LIB_FLAG := -framework Cocoa -framework OpenGL -framework \
			IOKit $(MLX) -Iinclude -lglfw -g

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@if [ -z "$(shell ls -A $(LIBFT_DIR))" ]; then \
		git submodule init $(LIBFT_DIR); \
		git submodule update $(LIBFT_DIR); \
	fi
	@echo "$(BLUE)Start compiling libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Done!$(NC)"

$(MLX):
	@if [ -z "$(shell ls -A $(MLX_DIR))" ]; then \
		git submodule init $(MLX_DIR); \
		git submodule update $(MLX_DIR); \
	fi
	@echo "$(BLUE)Start compiling MLX...$(NC)"
	@cd $(MLX_DIR) && cmake -B build && make -C build -j4
	@echo "$(GREEN)Done$(NC)"

$(NAME): $(OBJ_DIR) $(OBJS) $(HEADER) $(UTILS_HEADER)
	@$(CC) $(CC_FLAG) $(OBJS) $(LIBFT) $(LIB_FLAG) -o $(NAME)
	@echo "$(GREEN)Build successfully!$(NC)"

clean:
	@$(RM) $(RM_FLAG) $(OBJ_DIR) $(LIBFT_DIR)/objs
	@echo "$(GREEN)Clean bins successfully!$(NC)"

fclean: clean
	@$(RM) $(RM_FLAG) $(NAME) $(LIBFT) $(MLX_DIR)/build
	@echo "$(GREEN)Clean everything successfully!$(NC)"

re: fclean all

exe: all
	./$(NAME)

clean_libs:
	@cd $(LIBFT_DIR) && ls -A | xargs rm -rf
	@cd $(MLX_DIR) && ls -A | xargs rm -rf

$(OBJ_DIR)/%.o: %.c $(UTILS_HEADER)
	$(CC) $(CC_FLAG) -Imlx -c $< -o $@ $(LINK_HEADERS)

$(OBJ_DIR):
	@echo "$(BLUE)Start compiling...$(NC)"
	$(MAKE_DIR) $(OBJS_DIR)

.PHONY: all clean fclean re init-sub mlx

GREEN := \033[0;32m
BLUE := \033[0;34m
NC := \033[0m