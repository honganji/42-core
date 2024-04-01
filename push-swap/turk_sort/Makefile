NAME = push_swap.a
EXECUTABLE_NAME = push_swap

PUSH_SWAP_HEADER = push_swap.h

LIBFT_LIB = libft.a

UTILS_DIR = utils
ALGO_SORT_DIR = sort_algo
OBJ_DIR = objs

SOURCE = $(wildcard *.c) $(wildcard **/*.c)

OBJS = $(SOURCE:%.c=$(OBJ_DIR)/%.o)

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
	$(CC) $(CC_FLAG) -o $(EXECUTABLE_NAME) $(SOURCE) $(UTILS_DIR)/$(LIBFT_LIB)
	./$(EXECUTABLE_NAME) 7 8 90 78 55 4 34 76 46 989 45
	rm $(EXECUTABLE_NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $< -o $@

$(OBJ_DIR):
	$(MAKE_DIR) $(OBJ_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(UTILS_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(ALGO_SORT_DIR)

.PHONY: all clean fclean re