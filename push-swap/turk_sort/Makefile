NAME = push_swap
NAME_CHECKER = checker_MAC

UTILS_DIR = utils
ALGO_SORT_DIR = sort_algo
LIBFT_DIR = libft

OBJ_DIR = objs

SOURCE = push_swap.c main.c libft/ft_bzero.c libft/ft_calloc.c \
		 libft/ft_isdigit.c libft/ft_atoi.c libft/ft_lstadd_back.c \
		 libft/ft_lstadd_front.c libft/ft_split.c libft/ft_lstnew.c \
		 libft/ft_putstr_fd.c libft/ft_lstsize.c utils/basis.c \
		 utils/store_arg.c utils/clear_lst.c utils/push.c \
		 utils/reverse_rotate.c utils/rotate.c utils/swap.c \
		 utils/check_lst.c sort_algo/push_all_to_a.c sort_algo/push_two_num.c \
		 sort_algo/push_with_sort.c sort_algo/sort_three_nums.c \
		 sort_algo/utils.c

OBJS = $(SOURCE:%.c=$(OBJ_DIR)/%.o)

RM = rm
CC = cc
MAKE_DIR = mkdir

RM_FLAG = -rf
CC_FLAG = -Wall -Wextra -Werror
G_FLAG = -g

# ARGS = 91 26 65 89 38 39 73 36 86 49 47 37 15 20 75 64 45 33 85 62 53 83 40 74 50 31 76 2 95 54 52 58 57 14 94 99 30 9 3 17 21 35 8 80 16 23 72 43 25 56 63 96 79 5 1 66 13 4 55 11 22 44 84 24 42 27 19 48 12 59 6 46 88 32 61 71 7 77 60 69 78 81 97 34 10 28 87 98 93 70 82 68 41 67 92 51 18 100 29 90 
ARGS = 0 1 2 3 4 5 8 9

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CC_FLAG) -o $@ $(OBJS)

clean:
	$(RM) $(RM_FLAG) $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	$(RM) $(RM_FLAG) $(NAME) $(NAME_BONUS)

re: fclean all

exe: all
	./$(NAME) $(ARGS)

check_mem:
	$(CC) $(G_FLAG) -o $(NAME) $(SOURCE)
	valgrind --leak-check=full ./push_swap $(ARGS)

use_checker:
	$(CC) -o $(NAME) $(SOURCE)
	./$(NAME) $(ARGS) | ./$(NAME_CHECKER) $(ARGS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CC_FLAG) -c $< -o $@

$(OBJ_DIR):
	$(MAKE_DIR) $(OBJ_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(UTILS_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(ALGO_SORT_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(LIBFT_DIR)

.PHONY: all clean fclean re exe