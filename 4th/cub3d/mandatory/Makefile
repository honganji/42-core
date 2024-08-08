NAME := cub3D

SRC_DIR := src
HEADER_DIR := include
LIB_DIR := libraries
OBJ_DIR := objs
LIBFT_DIR := $(LIB_DIR)/42-c-library
MLX_DIR := $(LIB_DIR)/MLX42
OBJS_DIR := $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(UTILS_DIR) $(PARSING_DIR))

HEADERS := $(addprefix $(HEADER_DIR)/, cub3d.h parsing.h utils.h)

SOURCE := $(addprefix $(SRC_DIR)/, main.c err.c ft_mlx.c clean_data.c array.c\
		    key_hook.c mlx_utils.c draw.c draw2.c ray_utils.c store_img.c \
			identifiers.c file.c map.c fill_color.c identifiers_util.c\
			wall_collision.c)

OBJS := $(SOURCE:%.c=$(OBJ_DIR)/%.o)

MODULES := $(LIBFT_DIR)/library.h $(MLX_DIR)/CMakeLists.txt

LIBFT := $(LIBFT_DIR)/libft.a
MLX := $(MLX_DIR)/build/libmlx42.a

RM := rm
CC := cc -g
MAKE := make
MAKE_DIR := mkdir -p

OS := $(shell uname)

ifeq ($(OS), Darwin) # macOS
    LINK_HEADERS := -I $(MLX_DIR)/include -I $(LIB_DIR)
    LIB_FLAG := -framework Cocoa -framework OpenGL -framework IOKit $(MLX) -Iinclude -lglfw -ldl -g
else # Linux
    LINK_HEADERS := -I $(MLX_DIR)/include -I $(LIB_DIR)
    LIB_FLAG := -L/usr/local/lib $(MLX) -Iinclude -ldl -lglfw -pthread -lm
endif

RM_FLAG := -rf
CC_FLAG := -Wall -Wextra -Werror

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
	@cd $(MLX_DIR) && rm -rf build && cmake -B build && cmake --build build -j4
	@echo "$(GREEN)Done$(NC)"

$(NAME): $(OBJ_DIR) $(OBJS) $(HEADERS)
	$(CC) $(CC_FLAG) $(OBJS) $(LIBFT) $(LIB_FLAG) -o $(NAME)
	@echo "$(GREEN)Build successfully!$(NC)"

clean:
	@$(RM) $(RM_FLAG) $(OBJ_DIR) $(LIBFT_DIR)/objs
	@echo "$(GREEN)Clean bins successfully!$(NC)"

fclean: clean
	@$(RM) $(RM_FLAG) $(NAME) $(LIBFT) $(MLX_DIR)/build
	@echo "$(GREEN)Clean everything successfully!$(NC)"

re: fclean all

clean_libs:
	@cd $(LIBFT_DIR) && ls -A | xargs rm -rf
	@cd $(MLX_DIR) && ls -A | xargs rm -rf

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@$(MAKE_DIR) $(dir $@)  # Create the directory for the object file if it doesn't exist
	$(CC) $(CC_FLAG) -c $< -o $@ $(LINK_HEADERS)

$(OBJ_DIR):
	@echo "$(BLUE)Start compiling...$(NC)"
	$(MAKE_DIR) $(OBJS_DIR)

.PHONY: all clean fclean re

GREEN := \033[0;32m
BLUE := \033[0;34m
NC := \033[0m
