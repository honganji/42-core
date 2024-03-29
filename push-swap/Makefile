NAME = push_swap.a
EXECUTABLE_NAME = push_swap

PUSH_SWAP_HEADER = push_swap.h
# MAND_HEADER = mand.h

LIBFT_LIB = libft.a

UTILS_DIR = utils
OBJ_DIR = objs

SOURCE_UTILS = $(wildcard *.c) $(wildcard $(UTILS_DIR)/*.c)

OBJS = $(SOURCE_UTILS:%.c=$(OBJ_DIR)/%.o)

RM = rm
CC = cc
AR = ar
MAKE_DIR = mkdir

RM_FLAG = -rf
CC_FLAG = -Wall -Wextra -Werror
AR_FLAG = -rcs

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(PUSH_SWAP_HEADER)
	$(AR) $(AR_FLAG) $(NAME) $(OBJS)

clean:
	$(RM) $(RM_FLAG) $(OBJ_DIR) $(EXECUTABLE_NAME)

fclean: clean
	$(RM) $(RM_FLAG) $(NAME)

re: fclean all

re_exe: fclean gen_exe

gen_exe:
	$(CC) $(CC_FLAG) -o $(EXECUTABLE_NAME) $(SOURCE_UTILS) $(UTILS_DIR)/$(LIBFT_LIB)
	@./$(EXECUTABLE_NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $< -o $@

$(OBJ_DIR):
	$(MAKE_DIR) $(OBJ_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(UTILS_DIR)

.PHONY: all clean fclean re