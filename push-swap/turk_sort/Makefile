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
	$(CC) $(CC_FLAG) -o $(EXECUTABLE_NAME) $(SOURCE) $(UTILS_DIR)/$(LIBFT_LIB)

clean:
	$(RM) $(RM_FLAG) $(OBJ_DIR) $(EXECUTABLE_NAME)

fclean: clean
	$(RM) $(RM_FLAG) $(NAME)

re: fclean all

re_exe: fclean gen_exe

gen_exe:
	$(CC) $(CC_FLAG) -o $(EXECUTABLE_NAME) $(SOURCE) $(UTILS_DIR)/$(LIBFT_LIB)
	./$(EXECUTABLE_NAME) 83 98 10 5 30 41 15 4 87 9 73 38 36 52 89 95 93 56 43 18 70 13 28 85 53 90 81 69 25 20 6 39 82 51 75 62 94 78 40 61 26 63 80 37 54 88 84 49 1 67 29 21 35 42 34 2 59 27 23 86 100 47 7 91 72 17 92 66 44 76 77 97 11 99 65 79 3 50 46 57 71 55 58 32 68 14 33 60 16 96 22 12 64 19 24 31 74 8 45 48 

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $< -o $@

$(OBJ_DIR):
	$(MAKE_DIR) $(OBJ_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(UTILS_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(ALGO_SORT_DIR)

.PHONY: all clean fclean re