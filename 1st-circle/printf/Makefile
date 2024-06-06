NAME = libftprintf.a
EXECUTABLE_NAME = libftprintf

PRINTF_HEADER = ft_printf.h
MAND_HEADER = mand.h

LIBFT_LIB = libft.a

MAND_DIR = mand
OBJ_DIR = objs

SOURCE_MAND = $(wildcard *.c) $(wildcard $(MAND_DIR)/*.c)

OBJS = $(SOURCE_MAND:%.c=$(OBJ_DIR)/%.o)

RM = rm
CC = cc
AR = ar
MAKE_DIR = mkdir

RM_FLAG = -rf
CC_FLAG = -Wall -Wextra -Werror
AR_FLAG = -rcs

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(PRINTF_HEADER)
	$(AR) $(AR_FLAG) $(NAME) $(OBJS)

clean:
	$(RM) $(RM_FLAG) $(OBJ_DIR) $(EXECUTABLE_NAME)

fclean: clean
	$(RM) $(RM_FLAG) $(NAME)

re: fclean all

re_exe_mand: fclean execute_mand

execute_mand:
	$(CC) $(CC_FLAG) -o $(EXECUTABLE_NAME) $(SOURCE_MAND) $(MAND_DIR)/$(LIBFT_LIB)
	@./$(EXECUTABLE_NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $< -o $@

$(OBJ_DIR):
	$(MAKE_DIR) $(OBJ_DIR)
	$(MAKE_DIR) $(OBJ_DIR)/$(MAND_DIR)

.PHONY: all clean fclean re