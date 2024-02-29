SOURCES = ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcat.c ft_strnstr.c
SOURCES += ft_atoi.c ft_isalpha.c ft_memchr.c  ft_memset.c  ft_strlcpy.c ft_strrchr.c
SOURCES += ft_bzero.c ft_isascii.c ft_memcmp.c  ft_strchr.c ft_strlen.c  ft_tolower.c
SOURCES += ft_calloc.c  ft_isdigit.c ft_memcpy.c  ft_strdup.c  ft_strncmp.c ft_toupper.c

HEADER = libft.h

NAME = libft.a

OBJ_DIR = objs
OBJS = $(SOURCES:%.c=$(OBJ_DIR)/%.o)

TEST_DIR = test
TEST_NAME = testft
TEST_MAIN = test_main.c

CFLAG = -Wall -Wextra -Werror
ARFLAG = rcs
RMFLAG = -rf

CC = gcc
AR = ar
RM = rm

CHECK_NAME = check
CHECK_SRC = ft_split.c

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(HEADER)
	$(AR) $(ARFLAG) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(CFLAG) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	$(RM) $(RMFLAG) $(OBJ_DIR)

fclean: clean
	$(RM) -f libft.a

re:
	fclean all

test: $(TEST_NAME)
	./$(TEST_NAME)
	@rm -f $(TEST_NAME)

$(TEST_NAME):
	$(CC) $(TEST_DIR)/*.c ./*.c -o $(TEST_NAME)

check:
	$(CC) $(CHECK_SRC) -o $(CHECK_NAME)
	./$(CHECK_NAME)
	@rm -f $(CHECK_NAME)
